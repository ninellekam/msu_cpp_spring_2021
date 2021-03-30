#include "TokenParser.hpp"
#include <cassert>

void test_1() {
	TokenParser TokenParser;
	size_t count_digits = 0;
	size_t count_strings = 0;
	std::string text = "Hello 12345 123 123techo 777 msu666spring456 345543";

	TokenParser.SetDigitCallback([&count_digits](const std::string & token){ count_digits++; });
	TokenParser.SetStringCallback([&count_strings](const std::string & token){ count_strings++; });
	TokenParser.TParser(text);
	assert(count_digits == 4 and count_strings == 3);
}

void test_2() {
	TokenParser TokenParser;
	std::string str;
	std::string digit_str;
	std::string text = "MsuCppSpring \t\n \n 20202021\n \t\t\t\n\n\n\n\n \t\n\t\n";

	TokenParser.SetDigitCallback([&](const std::string & token){ digit_str += token; });
	TokenParser.SetStringCallback([&](const std::string & token){ str += token; });
	TokenParser.TParser(text);
	assert(digit_str == "20202021" and str == "MsuCppSpring");
}

void test_3() {
	TokenParser TokenParser;
	size_t count_digits = 0;
	size_t count_strings = 0;
	std::string text = "TestNumberThree 12345 123ByNinaKamkia\n";

	TokenParser.SetDigitCallback([&count_digits](const std::string & token){ count_digits++; });
	TokenParser.SetStringCallback([&count_strings](const std::string & token){ count_strings++; });
	TokenParser.TParser(text);
	assert(count_digits == 1 and count_strings == 2);
}

void test_4() {
	TokenParser TokenParser;
	std::string str;
	std::string digit_str;
	std::string text = "string 12345 123nodigit\n\n \n\t\n \n \n \n n\n\n";

	TokenParser.SetDigitCallback([&](const std::string & token){ digit_str += token; });
	TokenParser.SetStringCallback([&](const std::string & token){ str += token; });
	TokenParser.TParser(text);
	assert(digit_str == "12345" and str == "string123nodigitn");
}

void test_5() {
	TokenParser TokenParser;
	bool started = false;
	bool ended = false;
	std::string str_fot_test;
	std::string text = "Mail.RU GROUP 2020 2021 Spring\n\t\n CPP\n DEEP \n";

	TokenParser.SetStartCallback([&str_fot_test](){ str_fot_test += "start";});
	TokenParser.SetDigitCallback([&str_fot_test](const std::string & token){ str_fot_test.push_back('1'); });
	TokenParser.SetStringCallback([&str_fot_test](const std::string & token){ str_fot_test.push_back('0'); });
	TokenParser.SetEndCallback([&str_fot_test](){ str_fot_test += "end"; });
	TokenParser.TParser(text);
	assert(str_fot_test == std::string("start0011000end"));
}

void test_6() {
	TokenParser TokenParser;
	bool started = false;
	bool ended = false;
	std::string str_fot_test;
	std::string text = "string 12345 123nodigit\n\t\n 1234\n \n123456789 \n";

	TokenParser.SetStartCallback([&str_fot_test](){ str_fot_test += "Start";});
	TokenParser.SetDigitCallback([&str_fot_test](const std::string & token){ str_fot_test+=token; });
	TokenParser.SetStringCallback([&str_fot_test](const std::string & token){ str_fot_test+=token; });
	TokenParser.SetEndCallback([&str_fot_test](){ str_fot_test += "End";});
	TokenParser.TParser(text);

	assert(str_fot_test == std::string("Startstring12345123nodigit1234123456789End"));
}

int main() {
	test_1();
	std::cout << "test_1 " <<"OK" << std::endl;
	test_2();
	std::cout << "test_2 " << "OK" << std::endl;
	test_3();
	std::cout << "test_3 " << "OK" << std::endl;
	test_4();
	std::cout << "test_4 " << "OK" << std::endl;
	test_5();
	std::cout << "test_5 " << "OK" << std::endl;
	test_6();
	std::cout << "test_6 " << "OK" << std::endl;
	return 0;
}