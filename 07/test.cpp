#include "Vector.hpp"

void TestOperator()
{
	Vector<int> v;
	v.push_back(200);
	v.push_back(300);
	v.push_back(400);
	assert(v[1] == 300);
}

void TestPush()
{
	Vector<int> v;
	v.push_back(342424);
	assert(!v.empty());
	assert(v.size() == 1);
}

void TestPop()
{
	Vector<int> v;
	v.push_back(3423);
	v.pop_back();
	assert(v.empty());
	// assert(x == 22);
	assert(v.size() == 0);
	v.push_back(4545);
	v.push_back(453522);
	v.pop_back();
	assert(v.size() == 1);
}

void TestEmpty()
{
	Vector<int> v;
	assert(v.empty());
	v.push_back(888);
	assert(!v.empty());
}

void TestOfSize()
{
	Vector<int> v;
	assert(v.size() == 0);
	v.push_back(10);
	assert(v.size() == 1);
	v.push_back(34242);
	v.push_back(56464643);
	assert(v.size() == 3);

}

void TestClear()
{
	Vector<int> v;
	v.push_back(888);
	v.push_back(1111);
	v.push_back(5555);
	assert(v.size() == 3);
	v.clear();
	assert(v.size() == 0);
}

void TestBegRbeg()
{
	Vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);

	auto b = v.begin();
	assert(b != v.end());
	assert(*b == 0);
	++b;
	assert(b != v.end());
	assert(*b == 1);
	++b;
	assert(b != v.end());
	assert(*b == 2);
	++b;
	assert(b == v.end());

	auto r = v.rbegin();
	assert(r != v.rend());
	assert(*r == 2);
	++r;
	assert(r != v.rend());
	assert(*r == 1);
	++r;
	assert(r != v.rend());
	assert(*r == 0);
	++r;
	assert(r == v.rend());
}

void TestEndRend()
{
	Vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);

	auto b = v.end();
	assert(b != v.begin());
	--b;
	assert(b != v.begin());
	assert(*b == 0);
	--b;
	assert(b != v.begin());
	assert(*b == 1);
	--b;
	assert(b == v.begin());
	assert(*b == 2);

	auto r = v.rend();
	assert(r != v.rbegin());
	--r;
	assert(r != v.rbegin());
	assert(*r == 2);
	--r;
	assert(r != v.rbegin());
	assert(*r == 1);
	--r;
	assert(r == v.rbegin());
	assert(*r == 0);
}

void TestResize()
{
	Vector<int> v;
	v.push_back(2);
	v.resize(10);
	assert(v.size() == 10);
}

void TestReserve()
{
	Vector<int> v;
	v.push_back(2);
	v.push_back(33);
	v.push_back(21);
	v.reserve(100);
	assert(v.capacity() >= 100);
}

void CapacityTest()
{
	Vector<int> v;
	v.reserve(100);
	assert(v.capacity() >= 100);
}

int main()
{
	TestOperator();
	std::cout <<  "OperatorTest is OK!\n";
	TestPush();
	std::cout <<  "PushTest is OK!\n";
	TestPop();
	std::cout <<  "PopTest is OK!\n";
	TestEmpty();
	std::cout <<  "EmptyTest is OK!\n";
	TestOfSize();
	std::cout <<  "SizeOfTest is OK!\n";
	TestClear();
	std::cout <<  "ClearTest is OK!\n";
	TestBegRbeg();
	std::cout <<  "BegRbegTest is OK!\n";
	TestEndRend();
	std::cout <<  "EndRendTest is OK!\n";
	TestResize();
	std::cout <<  "ResizeTest is OK!\n";
	TestReserve();
	std::cout <<  "ReserveTest is OK!\n";
	CapacityTest();
	std::cout <<  "CapacityTest is OK!\n";
}