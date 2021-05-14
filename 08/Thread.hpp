#ifndef		THREAD_HPP
#define		THREAD_HPP

#include	<iostream>
#include	<pthread.h>
#include	<future>
#include	<thread>
#include	<vector>
#include	<queue>
#include	<unistd.h>
#include	<functional>
#include	<condition_variable>

class ThreadPool{
	std::mutex							MyMutex;
	std::vector<std::thread>			pool;
	std::condition_variable				ConditionVar;
	std::queue<std::function<void()>>	TaskQueue;
	std::atomic<bool>					stop;
public:
	ThreadPool(size_t SizeOfPool);
	~ThreadPool();
	void GoProccess();
	template <class Func, class... Args>
	auto exec(Func func, Args... args) -> std::future<decltype(func(args...))> {
		using res_type = std::packaged_task <decltype(func(args ...))()>;
		auto task = std::make_shared <res_type> (std::bind(func, args...));
		auto res = task->get_future();
		std::unique_lock<std::mutex> lock(MyMutex);
		std::function<void()> my_func = [task](){ (*task)(); };
		TaskQueue.push(my_func);
		ConditionVar.notify_one();
		return res;
	}
};

#endif
