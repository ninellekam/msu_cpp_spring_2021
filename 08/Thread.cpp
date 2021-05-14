#include "Thread.hpp"

ThreadPool::ThreadPool(size_t SizeOfPool) {
	stop = false;
	for (size_t i = 0; i < SizeOfPool; ++i) {
		std::thread MyThread(&ThreadPool::GoProccess, this);
		pool.emplace_back(std::move(MyThread));
	}
}

void ThreadPool::GoProccess() {
	while (!stop) {
		std::unique_lock<std::mutex> lock(MyMutex);
		if (TaskQueue.empty()) {
			ConditionVar.wait(lock);
		}
		else {
			auto task(std::move(TaskQueue.front()));
			TaskQueue.pop();
			lock.unlock();
			task();
		}
	}
}

ThreadPool::~ThreadPool(){
		stop = true;
		ConditionVar.notify_all();
		for (size_t i = 0; i < pool.size(); ++i) {
			pool[i].join();
		}
}
