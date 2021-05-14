#include "Test.hpp"

int foo(const A& a) {
	return a.value;
}

void test1(ThreadPool &pool) {
	auto task1 = pool.exec(foo, A{5});
	assert(task1.get() == 5);
}

void test2(ThreadPool &pool) {
	auto task2 = pool.exec([]() { return 1; });
	assert(task2.get() == 1);
}

int main(){
	ThreadPool pool(3);
	test1(pool);
	std::cout << "Test 1 is OK!\n";
	test2(pool);
	std::cout << "Test 2 is OK!\n";
	for(int i = 0; i < 10; ++i){
		auto task = pool.exec([i](){ return i; });
		assert(task.get() == i);
		std::cout << "Test for ID = " << i << " proccess is OK!\n";
	}
	return 0;
}
