#include "Thread.hpp"

ThreadPool::~ThreadPool(){
		stop = true;
		condition_var.notify_all();
		for (size_t i = 0; i < pool.size(); ++i){
			pool[i].join();
		}
}

void ThreadPool::work() {
	while (!stop) {
		std::unique_lock<std::mutex> lock(my_mutex);
		if (task_queue.empty()) {
			condition_var.wait(lock);
		}
		else {
			auto task(std::move(task_queue.front()));
			task_queue.pop();
			lock.unlock();
			task();
		}
	}
}

ThreadPool::ThreadPool(size_t poolSize) {
	stop = false;
	for (size_t i = 0; i < poolSize; ++i) {
		std::thread my_thread(&ThreadPool::work, this);
		pool.emplace_back(std::move(my_thread));
	}
}