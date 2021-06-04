#include "test.hpp"

void EqualTest()
{
    BigInt x = 3;
    assert(x == 3);
    BigInt y = x;
    assert(x == y);
    assert(y == 3);
    BigInt z;
    z = 0;
    int n = 5;
    z = n;
    assert(x != z);
}

void MaxTest()
{
    const BigInt big = std::numeric_limits<int32_t>::max();
    assert(big == std::numeric_limits<int32_t>::max());
}

void StrTest()
{
    BigInt x("-11");
    assert(x == -11);
    BigInt s = 12;
    BigInt z;
    z = x+s;
    assert(z == 1);
}

void PlusTest()
{
    BigInt x = 4;
    BigInt z = 3;
    z = z + x + 3;
    assert(z == 10);
}

void MinusTest()
{
    BigInt x = 4;
    BigInt z = 3;
    z = x - 3;
    assert(z == 1);
}

void CompareTest()
{
    BigInt x = 4;
    BigInt z = 3;
    assert(x > z);
    assert(z < x);
    BigInt y = 3;
    assert(y <= z);
}

void UnoMinusTets()
{
    BigInt x = 4;
    x = -x;
    assert(x == -4);
}

void MoveTest()
{
    BigInt c = 4;
    BigInt d;
    d = std::move(c);
    assert(d == 4);
}

void CopyTest()
{
    BigInt c(4);
    BigInt d(c);
    BigInt a;
    a = d;
    BigInt b;
    a = BigInt("123");
    b = 1111;
}

void MullTest()
{
    BigInt a = 1;
    BigInt c = 4;
    BigInt d = -11;
    BigInt e = d * c;
    BigInt f = c * 3;
    assert(e == -44);
    assert(f == 12);
    f = a * c;
    assert(f == 4);
}

void ClassTest()
{
    BigInt a = 1;
    BigInt b("123456789012345678901234567890");
    BigInt c = a * b + 2;
    BigInt d;
    d = std::move(c);
    a = d + b;
}

void InterestingTest()
{
    BigInt a = 1;
    BigInt b("99999999");
    BigInt c = a + b;
    assert(a+b == 100000000);
    BigInt e = 0;
    BigInt f = 0;
    BigInt g = e+f;
    assert(g == 0);

}


int main()
{
    EqualTest();
	std::cout << "OK!\n";
    MaxTest();
	std::cout << "OK!\n";
    StrTest();
	std::cout << "OK!\n";
    PlusTest();
	std::cout << "OK!\n";
    CompareTest();
	std::cout << "OK!\n";
    UnoMinusTets();
	std::cout << "OK!\n";
    MinusTest();
	std::cout << "OK!\n";
    MoveTest();
	std::cout << "OK!\n";
    CopyTest();
	std::cout << "OK!\n";
    MullTest();
	std::cout << "OK!\n";
    ClassTest();
	std::cout << "OK!\n";
    InterestingTest();
	std::cout << "OK!\n";
    return 0;
}
