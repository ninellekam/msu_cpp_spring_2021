#include "parser.hpp"
#include <cassert>

void test_1() {
	Parser parser;
	size_t n_digits = 0;
	size_t n_strings = 0;
	std::string text = "string 12345 123 123nodigit 987654321 no123digit456 54321";

	parser.set_digit_callback([&n_digits](const std::string & token){ n_digits++; });
	parser.set_string_callback([&n_strings](const std::string & token){ n_strings++; });
	parser.parse(text);
	assert(n_digits == 4 and n_strings == 3);
}

void test_2() {
	Parser parser;
	std::string str;
	std::string digit_str;
	std::string text = "string \t\n \n 12345\n \t\t\t\n\n\n\n\n \t\n\t\n";

	parser.set_digit_callback([&](const std::string & token){ digit_str += token; });
	parser.set_string_callback([&](const std::string & token){ str += token; });
	parser.parse(text);
	assert(digit_str == "12345" and str == "string");
}

void test_3() {
	Parser parser;
	size_t n_digits = 0;
	size_t n_strings = 0;
	std::string text = "string 12345 123nodigit\n";

	parser.set_digit_callback([&n_digits](const std::string & token){ n_digits++; });
	parser.set_string_callback([&n_strings](const std::string & token){ n_strings++; });
	parser.parse(text);
	assert(n_digits == 1 and n_strings == 2);
}

void test_4() {
	Parser parser;
	std::string str;
	std::string digit_str;
	std::string text = "string 12345 123nodigit\n\n \n\t\n \n \n \n n\n\n";

	parser.set_digit_callback([&](const std::string & token){ digit_str += token; });
	parser.set_string_callback([&](const std::string & token){ str += token; });
	parser.parse(text);
	assert(digit_str == "12345" and str == "string123nodigitn");
}

void test_5() {
	Parser parser;
	bool started = false;
	bool ended = false;
	std::string check;
	std::string text = "string 12345 123nodigit\n\t\n 1234\n 123456789 \n";

	parser.set_start_callback([&started](){ started = true; });
	parser.set_digit_callback([&check](const std::string & token){ check.push_back('1'); });
	parser.set_string_callback([&check](const std::string & token){ check.push_back('0'); });
	parser.set_end_callback([&ended](){ ended = true; });
	parser.parse(text);
	assert(check == std::string("01011") and started and ended);
}

void test_6() {
	Parser parser;
	bool started = false;
	bool ended = false;
	std::string check;
	std::string text = "string 12345 123nodigit\n\t\n 1234\n \n123456789 \n";

	parser.set_start_callback([&started](){ started = true; });
	parser.set_digit_callback([&check](const std::string & token){ check+=token; });
	parser.set_string_callback([&check](const std::string & token){ check+=token; });
	parser.set_end_callback([&ended](){ ended = true; });
	parser.parse(text);

	assert(check == std::string("string12345123nodigit1234123456789") and started and ended);
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