#ifndef THREAD_HPP
#define THREAD_HPP

#include <iostream>
#include <pthread.h>
#include <future>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>

class ThreadPool{
	std::mutex							my_mutex;
	std::vector<std::thread>			pool;
	std::condition_variable				condition_var;
	std::queue<std::function<void()>>	task_queue;
	std::atomic<bool>					stop;
public:
	ThreadPool(size_t poolSize);
	~ThreadPool();
	void work();
	template <class Func, class... Args>
	auto exec(Func func, Args... args) -> std::future<decltype(func(args...))> {
		typedef std::packaged_task <decltype(func(args ...))()> task_pack;
		auto task = std::make_shared <task_pack> (std::bind(func, args...));
		auto res = task->get_future();
		std::unique_lock<std::mutex> lock(my_mutex);
		// std::packaged_task <decltype(func(args ...))()> task(std::bind(func, args...));
		// auto res = task.get_future();
		// std::unique_lock<std::mutex> lock(m);
		// task_queue.push([task](){ task(); });
		// std::cout << typeid(*task).name() << std::endl;
		task_queue.push([task](){ (*task)(); });
		condition_var.notify_one();
		return res;
	}
};

#endif