#include "Format.hpp"

void testNormal() {
	bool caught = false;
	auto text = format("{1}+{1} = {0}", 2, "one");
	assert(text == "one+one = 2");
}

void testOneBracket() {
	bool caught = false;
	std::string message = "";
	try {
		auto text = format("}", 0);
	}
	catch (std::runtime_error &a){
		message = a.what();
		caught = true;
	}
	assert(!strcmp(message.c_str(), "Error!\n"));
	assert(caught == true);
}

void testOneBracketOneDigit() {
	bool caught = false;
	std::string message = "";
	try {
		auto text = format("{0", 0);
	}
	catch (std::invalid_argument &a){
		message = a.what();
		caught = true;
	}
	assert(!strcmp(message.c_str(), "Error Bracket!\n"));
	assert(caught);
}

void testWithoutDigit() {
	bool caught = false;
	std::string message = "";
	try {
		auto text = format("{}", 0);
	}
	catch (std::runtime_error &a){
		message = a.what();
		caught = true;
	}
	assert(!strcmp(message.c_str(), "Empty buffer!\n"));
	assert(caught);
}

void testBracketsWithoutDigit() {
	bool	caught = false;
	std::string message = "";
	try {
		auto text = format("{{}}", 0);
	}
	catch (std::invalid_argument &a){
		message = a.what();
		caught = true;
	}
	assert(!strcmp(message.c_str(),  "Error Bracket!\n"));
	assert(caught);
}

void testArgumentsLess1() {
	bool caught = false;
	std::string message = "";
	try {
		auto text = format("{1} {0}", 0);
	}
	catch (std::overflow_error &a){
		message = a.what();
		caught = true;
	}
	assert(!strcmp(message.c_str(),  "Out of range!\n"));
	assert(caught);
}

void testNormalBracketsOneDigit() {
	auto text = format("{0}", 1);
	assert(text == "1");
}

void testEmptyString() {
	auto text = format("");
	assert(text == "");
}

void testArgumentWithChar() {
	auto text = format("{0}{0}", "a");
	assert(text == "aa");
}

void testStringAndBrackets() {
	assert(format("{0} msg", "1111") == "1111 msg");
}

void testArgumentWithFalse() {
	assert(format("msg {0} {1} {0}", "1", false) == "msg 1 0 1");
}

void testArgemuntsLess2() {
	bool error = false;
	std::string message = "";
	try {
		auto t = format("{} {0}", 1);
	}
	catch(const std::runtime_error& err) {
		message = err.what();
		error = true;
	}
	assert(!strcmp(message.c_str(), "Empty buffer!\n"));
	assert(error);
}

void testManyFormatArgsWithoutDelimiter() {
	bool caught = false;
	auto text = format("{1}{1}{0}", 2, "one");
	assert(text == "oneone2");
}

void testNotEmptyStrWithoutFormat() {
	bool caught = false;
	auto text = format("1123232322232", 3, "one");
	assert(text == "1123232322232");
}

void testErrorBracket() {
	bool caught = false;
	std::string message = "";
	try {
		auto text = format("{{{{0}", 3, "one");
	}
	catch (std::invalid_argument &a){
		message = a.what();
		caught = true;
	}
	assert(!strcmp(message.c_str(),  "Error Bracket!\n"));
	assert(caught);
}

void testIntMax() {
	bool caught = false;
	auto text = format("{0}", 2147483648);
	assert(text == "2147483648");
}

int main() {
	testNormal();
	std::cout << "testNormal is OK!\n";
	testOneBracket();
	std::cout << "testOneBracket is OK!\n";
	testOneBracketOneDigit();
	std::cout << "testOneBracketOneDigit is OK!\n";
	testWithoutDigit();
	std::cout << "testWithoutDigit is OK!\n";
	testBracketsWithoutDigit();
	std::cout << "testBracketsWithoutDigit is OK!\n";
	testArgumentsLess1();
	std::cout << "testArgemuntsLess is OK!\n";
	testNormalBracketsOneDigit();
	std::cout << "testNormalBracketsOneDigit is OK!\n";
	testEmptyString();
	std::cout << "testEmptyString is OK!\n";
	testArgumentWithChar();
	std::cout << "test10 is OK!\n";
	testStringAndBrackets();
	std::cout << "testStringAndBrackets is OK!\n";
	testArgumentWithFalse();
	std::cout << "testArgumentWithFalse is OK!\n";
	testArgemuntsLess2();
	std::cout << "testArgemuntsLess2 is OK!\n";
	testManyFormatArgsWithoutDelimiter();
	std::cout << "testManyFormatArgsWithoutDelimiter is OK!\n";
	testNotEmptyStrWithoutFormat();
	std::cout << "testNotEmptyStrWithoutFormat is OK!\n";
	testErrorBracket();
	std::cout << "testErrorBracket is OK!\n";
	testIntMax();
	std::cout << "testIntMax is OK!\n";
	return 0;
}
