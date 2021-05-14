#ifndef TEST_HPP
#define TEST_HPP
#include <iostream>
#include <cassert>

#include "Thread.hpp"
struct A {
	int value;
};

void test2(ThreadPool &pool);
void test1(ThreadPool &pool);
int foo(const A& a);

#endif