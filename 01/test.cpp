#include "test.hpp"
#include <iostream>
#include "allocator.hpp"
#include <cassert>

void DefaultTest(){
	Allocator myAllocator;
	myAllocator.makeAllocator(1024);
	char* ptr = myAllocator.alloc(200);
	assert(ptr != nullptr);
	assert(myAllocator.getCurrPtr() == 200);
}

void LimitTest(){
	Allocator myAllocator;
	myAllocator.makeAllocator(100);
	char* ptr = myAllocator.alloc(100);
	assert(ptr != nullptr);
	assert(myAllocator.getCurrPtr() == 100);
}

void DoublingTest(){
	Allocator myAllocator;
	myAllocator.makeAllocator(1000);
	char* ptr = myAllocator.alloc(200);
	assert(ptr != nullptr);
	ptr = myAllocator.alloc(400);
	assert(ptr != nullptr);
	assert(myAllocator.getCurrPtr() == 600);
}

void OverflowTest(){
	Allocator myAllocator;
	myAllocator.makeAllocator(100);
	char* ptr = myAllocator.alloc(20);
	assert(ptr != nullptr);
	ptr = myAllocator.alloc(90);
	assert(myAllocator.getCurrPtr() == 20);
}

void ResetTest(){
	Allocator myAllocator;
	myAllocator.makeAllocator(100);
	char* ptr = myAllocator.alloc(30);
	assert(ptr != nullptr);
	ptr = myAllocator.alloc(90);
	myAllocator.reset();
	ptr = myAllocator.alloc(90);
	assert(ptr != nullptr);
	assert(myAllocator.getCurrPtr() == 90);
}

void ResizeTest() {
	Allocator myAllocator;
	myAllocator.makeAllocator(100);
	char* ptr = myAllocator.alloc(110);
	myAllocator.makeAllocator(160);
	ptr = myAllocator.alloc(110);
	assert(ptr != nullptr);
	assert(myAllocator.getCurrPtr() == 110);
	assert(ptr != nullptr);
}

void test() {
	DefaultTest();
	std::cout << "Succes DefaultTest\n";
	LimitTest();
	std::cout << "Succes LimitTest\n";
	ResetTest();
	std::cout << "Succes ResetTest\n";
	OverflowTest();
	std::cout << "Succes OverFlowTest\n";
	ResetTest();
	std::cout << "Succes DoublingTest\n";
	ResizeTest();
	std::cout << "Succes ResizeTest\n";
	return ;
}