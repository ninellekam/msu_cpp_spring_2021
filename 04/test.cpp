#include "test.hpp"
#include <cassert>
#include "test.hpp"

void	TestStrs() {
	std::string s1 = "-228";
	std::string s2 = "1255";

	BigInt ob2(s2);
	assert(ob2 == 1255);
	BigInt ob1(s1);
	assert(ob1 == -228);
}

void TestInts() {
	BigInt ob1(-400);
	assert(ob1 == -400);
	BigInt ob2(-23232332);
	assert(ob2 == -23232332);
}

void TestZeroesAfter() {
	std::string s1 = "00000228";
	BigInt ob1(s1);
	assert(ob1 == 228);

	std::string s2 = "00001255";
	BigInt ob2(s2);
	assert(ob2 == 1255);
}

void TestEqual() {
	BigInt c = 25;
	assert(c == 25);
	BigInt d = -666;
	assert(d == -666);
}


void TestNotEqual() {
	BigInt c = 20;
	assert(c != -25);
	BigInt d = -665;
	assert(d != -666);
}

void TestMore() {
	BigInt c = 20;
	assert(c > -25);
	BigInt d = 666;
	assert(d > -666);
	std::string str("500500");
	BigInt l = str;
	assert(l > 5);
}

void TestLess() {

}



int main() {
	TestStrs();
	std::cout << "TestStrs OK\n";
	TestInts();
	std::cout << "TestInts OK\n";
	TestZeroesAfter();
	std::cout << "TestZeroesAfter OK\n";
	TestEqual();
	std::cout << "TestEqual OK\n";
	TestNotEqual();
	std::cout << "TestNotEqual OK\n";
	TestMore();
	std::cout << "TestMore OK";
	// TestLess();
	// std::cout << "TestLess OK";
}