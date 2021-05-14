#include "Thread.hpp"

ThreadPool::ThreadPool(size_t poolSize) {
	stop = false;
	for (size_t i = 0; i < poolSize; ++i) {
		// pool.emplace_back(std::thread(this->work()));
		pool.emplace_back(std::thread([this]() { this->work();}));
	}
}

ThreadPool::~ThreadPool(){
		stop = true;
		cond.notify_all();
		for (size_t i = 0; i < pool.size(); ++i){
			pool[i].join();
		}
}

void ThreadPool::work() {
	while (!stop) {
		std::unique_lock<std::mutex> lock(m);
		if (task_queue.empty()) {
			cond.wait(lock);
		}
		else {
			auto task(std::move(task_queue.front()));
			task_queue.pop();
			lock.unlock();
			task();
		}
	}
}

// template <class Func, class... Args>
// auto ThreadPool::exec(Func func, Args... args) -> std::future<decltype(func(args...))> {
// 	typedef std::packaged_task <decltype(func(args ...))()> task_pack;
// 	// auto task = std::make_shared <std::packaged_task <decltype(func(args...))()> > (std::bind(func, args...));
// 	auto task = std::make_shared <task_pack> (std::bind(func, args...));
// 	auto res = task->get_future();
// 	std::unique_lock<std::mutex> lock(m);
// 	task_queue.push([task](){
// 		(*task)();
// 	});
// 	cond.notify_one();
// 	return res;
// }