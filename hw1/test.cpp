#include "test.hpp"
#include <iostream>
#include "allocator.hpp"
#include <cassert>

void DefaultTest() {
	Allocator alloc;
	alloc.makeAllocator(1000);
	char *ptr = alloc.alloc(200);
	assert(ptr != NULL);
	assert(alloc.getCurrPtr() == 200);
	alloc.check();
}

void LimitTest() {
	Allocator alloc;
	alloc.makeAllocator(1000);
	char *ptr = alloc.alloc(1000);
	assert(ptr != NULL);
	assert(alloc.getCurrPtr() == 1000);
	alloc.check();
}

void ResetTest() {
	Allocator alloc;
	alloc.makeAllocator(1024);
	char *ptr = alloc.alloc(125);
	assert(alloc.getCurrPtr() == 125);
	assert(ptr != NULL);
	alloc.reset();
	ptr = alloc.alloc(516);
	assert(ptr != NULL);
	assert(alloc.getCurrPtr() == 516);
	alloc.check();
}

void OverFlowTest() {
	Allocator alloc;
	alloc.makeAllocator(1024);
	char *ptr = alloc.alloc(1000);
	assert(alloc.getCurrPtr() == 1000);
	ptr = alloc.alloc(25);
	assert(alloc.getCurrPtr() == 1000);
	alloc.check();
}

void test() {
	DefaultTest();
	std::cout << "Succes DefaultTest\n";
	LimitTest();
	std::cout << "Succes LimitTest\n";
	ResetTest();
	std::cout << "Succes ResetTest\n";
	OverFlowTest();
	std::cout << "Succes OverFlowTest\n";
	return ;
}