#include "Format.hpp"

void test1() {
	bool caught = false;
	auto text = format("{1}+{1} = {0}", 2, "one");
	assert(text == "one+one = 2");
}

void test2() {
	bool caught = false;
	try {
		auto text = format("}", 0);
	}
	catch (std::runtime_error &a){
		caught = true;
	}
	assert(caught == true);
}

void test3() {
	bool caught = false;
	try {
		auto text = format("{0", 0);
	}
	catch (const std::runtime_error&){
		caught = true;
	}
	assert(caught);
}

void test4() {
	bool caught = false;
	try {
		auto text = format("{}", 0);
	}
	catch (const std::runtime_error&){
		caught = true;
	}
	assert(caught);
}

void test5() {
	bool caught = false;
	try {
		auto text = format("}", 0);
	}
	catch (const std::runtime_error&){
		caught = true;
	}
	assert(caught);
}

void test6() {
	bool	caught = false;
	try {
		auto text = format("{{}}", 0);
	}
	catch (const std::runtime_error&){
		caught = true;
	}
	assert(caught);
}

void test7() {
	bool caught = false;
	try {
		auto text = format("{1} {0}", 0);
	}
	catch (const std::runtime_error&){
		caught = true;
	}
	assert(caught);
}

void test8() {
	auto text = format("{0}", 1);
	assert(text == "1");
}

void test9() {
	auto text = format("");
	assert(text == "");
}

void test10() {
	auto text = format("{0}{0}", "a");
	assert(text == "aa");
}

void test11() {
    assert(format("{0} msg", "1111") == "1111 msg");
}

void test12() {
    assert(format("msg {0} {1} {0}", "1", false) == "msg 1 0 1");
}

void test13() {
    bool error = false;
    try {
        auto t = format("{", 1);
    }
    catch(const std::runtime_error& err) {
        error = true;
        assert(error);
    }
}

void test14() {
    bool error = false;
    try {
        auto t = format("{} {0}", 1);
    }
    catch(const std::runtime_error& err) {
        error = true;
        assert(error);
    }
}

int main() {
	test1();
	std::cout << "test1 is OK!\n";
	test2();
	std::cout << "test2 is OK!\n";
	test3();
	std::cout << "test3 is OK!\n";
	test4();
	std::cout << "test4 is OK!\n";
	test5();
	std::cout << "test5 is OK!\n";
	test6();
	std::cout << "test6 is OK!\n";
	test7();
	std::cout << "test7 is OK!\n";
	test8();
	std::cout << "test8 is OK!\n";
	test9();
	std::cout << "test9 is OK!\n";
	test10();
	std::cout << "test10 is OK!\n";
	test11();
	std::cout << "test11 is OK!\n";
	test12();
	std::cout << "test12 is OK!\n";
	test13();
	std::cout << "test13 is OK!\n";
	test14();
	std::cout << "test14 is OK!\n";
	return 0;
}
