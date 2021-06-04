#include "Format.hpp"


void Test1(){
    auto text= format("{1}+{1} = {0}", 2, "one");
    assert(text == "one+one = 2");
}

void Test2(){
    auto text = format("{0}*{1} = {0}", 0, "one");
    assert(text == "0*one = 0");
}

void Test3(){
    auto text = format("{0}", 100500);
    assert(text == "100500");
}

void Test4(){
    auto text = format("technosphere");
    assert(text == "technosphere");
}

void Test5(){
    auto text = format("И {1} меня, и {1} меня В звенящую снежную даль {0} {3} коня, эх, {2} {3} коня Декабрь, {4}февраль{5}", "Три","уносят", "3", "белых", "январь и ", "!");
    assert(text == "И уносят меня, и уносят меня В звенящую снежную даль Три белых коня, эх, 3 белых коня Декабрь, январь и февраль!");
}


void Test8(){
    try{
        auto text = format("{0} + {1} = {2}", 10, 5, 15, 16);
    } catch(FormatError& error){
        std::string a = error.what();
        assert(a == "invalid format");
    }
}

void Test10(){
    try{
        auto text = format("0 + 1 = 2{");
    } catch (FormatError& error){
        std::string a = error.what();
        assert(a == "invalid format");
    }
}

int main(){
    Test1();
	std::cout << "OK!\n" << std::endl;
    Test2();
	std::cout << "OK!\n" << std::endl;
    Test3();
	std::cout << "OK!\n" << std::endl;
    Test4();
	std::cout << "OK!\n" << std::endl;
    Test5();
	std::cout << "OK!\n" << std::endl;
    // Test6();
    // Test7();
    Test8();
	std::cout << "OK!\n" << std::endl;
    // Test9();
    Test10();
	std::cout << "OK!\n" << std::endl;
}


// void testNormal() {
// 	bool caught = false;
// 	auto text = format("{1}+{1} = {0}", 2, "one");
// 	assert(text == "one+one = 2");
// }

// void testOneBracket() {
// 	bool caught = false;
// 	std::string message = "";
// 	try {
// 		auto text = format("}", 0);
// 	}
// 	catch (std::runtime_error &a){
// 		message = a.what();
// 		caught = true;
// 	}
// 	assert(!strcmp(message.c_str(), "Error!\n"));
// 	assert(caught == true);
// }

// void testOneBracketOneDigit() {
// 	bool caught = false;
// 	std::string message = "";
// 	try {
// 		auto text = format("{0", 0);
// 	}
// 	catch (std::invalid_argument &a){
// 		message = a.what();
// 		caught = true;
// 	}
// 	assert(!strcmp(message.c_str(), "Error Bracket!\n"));
// 	assert(caught);
// }

// void testWithoutDigit() {
// 	bool caught = false;
// 	std::string message = "";
// 	try {
// 		auto text = format("{}", 0);
// 	}
// 	catch (std::runtime_error &a){
// 		message = a.what();
// 		caught = true;
// 	}
// 	assert(!strcmp(message.c_str(), "Empty buffer!\n"));
// 	assert(caught);
// }

// void testBracketsWithoutDigit() {
// 	bool	caught = false;
// 	std::string message = "";
// 	try {
// 		auto text = format("{{}}", 0);
// 	}
// 	catch (std::invalid_argument &a){
// 		message = a.what();
// 		caught = true;
// 	}
// 	assert(!strcmp(message.c_str(),  "Error Bracket!\n"));
// 	assert(caught);
// }

// void testArgumentsLess1() {
// 	bool caught = false;
// 	std::string message = "";
// 	try {
// 		auto text = format("{1} {0}", 0);
// 	}
// 	catch (std::overflow_error &a){
// 		message = a.what();
// 		caught = true;
// 	}
// 	assert(!strcmp(message.c_str(),  "Out of range!\n"));
// 	assert(caught);
// }

// void testNormalBracketsOneDigit() {
// 	auto text = format("{0}", 1);
// 	assert(text == "1");
// }

// void testEmptyString() {
// 	auto text = format("");
// 	assert(text == "");
// }

// void testArgumentWithChar() {
// 	auto text = format("{0}{0}", "a");
// 	assert(text == "aa");
// }

// void testStringAndBrackets() {
// 	assert(format("{0} msg", "1111") == "1111 msg");
// }

// void testArgumentWithFalse() {
// 	assert(format("msg {0} {1} {0}", "1", false) == "msg 1 0 1");
// }

// void testArgemuntsLess2() {
// 	bool error = false;
// 	std::string message = "";
// 	try {
// 		auto t = format("{} {0}", 1);
// 	}
// 	catch(const std::runtime_error& err) {
// 		message = err.what();
// 		error = true;
// 	}
// 	assert(!strcmp(message.c_str(), "Empty buffer!\n"));
// 	assert(error);
// }

// void testManyFormatArgsWithoutDelimiter() {
// 	bool caught = false;
// 	auto text = format("{1}{1}{0}", 2, "one");
// 	assert(text == "oneone2");
// }

// void testNotEmptyStrWithoutFormat() {
// 	bool caught = false;
// 	auto text = format("1123232322232", 3, "one");
// 	assert(text == "1123232322232");
// }

// void testErrorBracket() {
// 	bool caught = false;
// 	std::string message = "";
// 	try {
// 		auto text = format("{{{{0}", 3, "one");
// 	}
// 	catch (std::invalid_argument &a){
// 		message = a.what();
// 		caught = true;
// 	}
// 	assert(!strcmp(message.c_str(),  "Error Bracket!\n"));
// 	assert(caught);
// }

// void testIntMax() {
// 	bool caught = false;
// 	auto text = format("{0}", 2147483648);
// 	assert(text == "2147483648");
// }

// int main() {
// 	testNormal();
// 	std::cout << "testNormal is OK!\n";
// 	testOneBracket();
// 	std::cout << "testOneBracket is OK!\n";
// 	testOneBracketOneDigit();
// 	std::cout << "testOneBracketOneDigit is OK!\n";
// 	testWithoutDigit();
// 	std::cout << "testWithoutDigit is OK!\n";
// 	testBracketsWithoutDigit();
// 	std::cout << "testBracketsWithoutDigit is OK!\n";
// 	testArgumentsLess1();
// 	std::cout << "testArgemuntsLess is OK!\n";
// 	testNormalBracketsOneDigit();
// 	std::cout << "testNormalBracketsOneDigit is OK!\n";
// 	testEmptyString();
// 	std::cout << "testEmptyString is OK!\n";
// 	testArgumentWithChar();
// 	std::cout << "test10 is OK!\n";
// 	testStringAndBrackets();
// 	std::cout << "testStringAndBrackets is OK!\n";
// 	testArgumentWithFalse();
// 	std::cout << "testArgumentWithFalse is OK!\n";
// 	testArgemuntsLess2();
// 	std::cout << "testArgemuntsLess2 is OK!\n";
// 	testManyFormatArgsWithoutDelimiter();
// 	std::cout << "testManyFormatArgsWithoutDelimiter is OK!\n";
// 	testNotEmptyStrWithoutFormat();
// 	std::cout << "testNotEmptyStrWithoutFormat is OK!\n";
// 	testErrorBracket();
// 	std::cout << "testErrorBracket is OK!\n";
// 	testIntMax();
// 	std::cout << "testIntMax is OK!\n";
// 	return 0;
// }
