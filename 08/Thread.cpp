#include "Thread.hpp"

ThreadPool::~ThreadPool(){
		stop = true;
		condition_var.notify_all();
		for (size_t i = 0; i < pool.size(); ++i){
			pool[i].join();
		}
}

void ThreadPool::FuncForThread() {
	while (!stop) {
		std::unique_lock<std::mutex> lock(my_mutex);
		if (TaskQueue.empty()) {
			condition_var.wait(lock);
		}
		else {
			auto task(std::move(TaskQueue.front()));
			TaskQueue.pop();
			lock.unlock();
			task();
		}
	}
}

ThreadPool::ThreadPool(size_t SizeOfPool) {
	stop = false;
	for (size_t i = 0; i < SizeOfPool; ++i) {
		std::thread MyThread(&ThreadPool::FuncForThread, this);
		pool.emplace_back(std::move(MyThread));
	}
}
