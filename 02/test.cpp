#include "test.hpp"
#include <vector>
#include <iostream>

#include <cassert>

template <typename T>
void assertVector(const std::vector<T> &generated, const std::vector<T> &expected) {
	assert(generated.size() == expected.size());
	assert(std::equal(generated.begin(), generated.end(), expected.begin()));
}

void test_without_callback()
{
	TokenParser	TokenParser;
	TokenParser.TParser("abc def 123    678    agsj");
}

void test_all()
{
	std::string str;
	std::vector<uint32_t> integer_found_tokens;
	std::vector<std::string> string_found_tokens;
	TokenParser TokenParser;
	integer_found_tokens.reserve(2);
	string_found_tokens.reserve(5);
	TokenParser.SetStartCallback([&str](){str += "Start";});
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetDigitCallback([&integer_found_tokens](uint32_t digitToken) {
	integer_found_tokens.push_back(digitToken);
	});
	TokenParser.SetStringCallback([&string_found_tokens](std::string stringToken) {
	string_found_tokens.push_back(std::move(stringToken));
	});
	TokenParser.TParser("jfajfa7873831318##$$!@!$!    \
			+14 -15 15 3218713     \
			jjHSHJAskAKSK12Q@!@");

	std::vector<uint32_t> integer_expected_tokens = {15, 3218713};
	std::vector<std::string> string_expected_tokens = {
	"jfajfa7873831318##$$!@!$!", "+14", "-15", "jjHSHJAskAKSK12Q@!@"};
	assertVector(integer_found_tokens, integer_expected_tokens);
	assertVector(string_found_tokens, string_expected_tokens);
	assert(str == "StartEnd");
}

void test_string_tabs()
{
	std::string str;
	std::vector<uint32_t> integer_found_tokens;
	std::vector<std::string> string_found_tokens;
	TokenParser TokenParser;
	integer_found_tokens.reserve(0);
	string_found_tokens.reserve(0);
	TokenParser.SetStartCallback([&str](){str += "Start";});
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetDigitCallback([&integer_found_tokens](uint32_t digitToken) {
	integer_found_tokens.push_back(digitToken);
	std::cout << digitToken;
	});
	TokenParser.SetStringCallback([&string_found_tokens](std::string stringToken) {
	string_found_tokens.push_back(std::move(stringToken));
	});
	TokenParser.TParser("   \t    \t\n");
	std::vector<uint32_t> integer_expected_tokens = {};
	std::vector<std::string> string_expected_tokens = {};
	assertVector(integer_found_tokens, integer_expected_tokens);
	assertVector(string_found_tokens, string_expected_tokens);
	assert(str == "StartEnd");
}

void test_with_only_string_tokens()
{
	std::string str;
	std::vector<uint32_t> integer_found_tokens;
	std::vector<std::string> string_found_tokens;
	TokenParser TokenParser;
	integer_found_tokens.reserve(4);
	string_found_tokens.reserve(5);
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetDigitCallback([&integer_found_tokens, &str](uint32_t digitToken) { str += "1"; integer_found_tokens.push_back(digitToken); });
	TokenParser.SetStringCallback([&string_found_tokens](std::string stringToken) { string_found_tokens.push_back(stringToken); });
	TokenParser.SetDigitCallback([&integer_found_tokens, &str](uint32_t digitToken) { str += "2"; integer_found_tokens.push_back(digitToken); });
	TokenParser.TParser("jfajfa7873831318##$$!@!$!    \
			+14 -15 15 3218713     \
			jjHSHJAskAKSK12 1222 5555 Q@!@");

	std::vector<uint32_t> integer_expected_tokens = {15, 3218713, 1222, 5555};
	std::vector<std::string> string_expected_tokens = {
	"jfajfa7873831318##$$!@!$!", "+14", "-15", "jjHSHJAskAKSK12", "Q@!@"};
	assertVector(integer_found_tokens, integer_expected_tokens);
	assertVector(string_found_tokens, string_expected_tokens);
	assert(str == "2222End");
}

void test_with_only_digit_tokens()
{
	std::string str;
	std::vector<uint32_t> integer_found_tokens;
	std::vector<std::string> string_found_tokens;
	TokenParser TokenParser;
	integer_found_tokens.reserve(3);
	string_found_tokens.reserve(0);
	TokenParser.SetStartCallback([&str](){str += "Start";});
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetStringCallback([&string_found_tokens](std::string stringToken) { string_found_tokens.push_back(stringToken); });
	TokenParser.SetDigitCallback([&integer_found_tokens, &str](uint32_t digitToken) { integer_found_tokens.push_back(digitToken); });
	TokenParser.TParser("25 \t\v\t    \n  778234 1273134");
	std::vector<uint32_t> integer_expected_tokens = {25, 778234, 1273134};
	std::vector<std::string> string_expected_tokens = {};
	assertVector(integer_found_tokens, integer_expected_tokens);
	assertVector(string_found_tokens, string_expected_tokens);
	assert(str == "StartEnd");
}

void test_with_no_start()
{
	std::string str;
	std::vector<uint32_t> integer_found_tokens;
	std::vector<std::string> string_found_tokens;
	TokenParser TokenParser;
	integer_found_tokens.reserve(3);
	string_found_tokens.reserve(0);
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetStringCallback([&string_found_tokens](std::string stringToken) { string_found_tokens.push_back(stringToken); });
	TokenParser.SetDigitCallback([&integer_found_tokens, &str](uint32_t digitToken) {integer_found_tokens.push_back(digitToken); });
	TokenParser.TParser("25 \t\v\t    \n  778234 1273134");
	std::vector<uint32_t> integer_expected_tokens = {25, 778234, 1273134};
	std::vector<std::string> string_expected_tokens = {};
	assertVector(integer_found_tokens, integer_expected_tokens);
	assertVector(string_found_tokens, string_expected_tokens);
	assert(str == "End");
}

void test_two_same_callbacks()
{
	std::string str;
	std::vector<uint32_t> integer_found_tokens;
	std::vector<std::string> string_found_tokens;
	TokenParser TokenParser;
	integer_found_tokens.reserve(4);
	string_found_tokens.reserve(5);
	TokenParser.SetStartCallback([&str](){str += "Start";});
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetDigitCallback([&integer_found_tokens, &str](uint32_t digitToken) {
	str += "1";
	integer_found_tokens.push_back(digitToken);
	});
	TokenParser.SetStringCallback([&string_found_tokens](std::string stringToken) {
	string_found_tokens.push_back(stringToken);
	});
	TokenParser.SetDigitCallback([&integer_found_tokens, &str](uint32_t digitToken) {
	str += "2";
	integer_found_tokens.push_back(digitToken);
	});
	TokenParser.TParser("jfajfa7873831318##$$!@!$!    \
			+14 -15 15 3218713     \
			jjHSHJAskAKSK12 1222 5555 Q@!@");

	std::vector<uint32_t> integer_expected_tokens = {15, 3218713, 1222, 5555};
	std::vector<std::string> string_expected_tokens = {
	"jfajfa7873831318##$$!@!$!", "+14", "-15", "jjHSHJAskAKSK12", "Q@!@"};
	assertVector(integer_found_tokens, integer_expected_tokens);
	assertVector(string_found_tokens, string_expected_tokens);
	assert(str == "Start2222End");
}

void test_overflow() {
	TokenParser TokenParser;
	std::string input("hello mail.ru 12 446744073709551616 125 7777 1818181818181818181811818 \
			@#$kkoooklsffsf stainherfS     \
	");
	std::vector<uint32_t> integer_found_tokens;
	std::vector<std::string> string_found_tokens;
	integer_found_tokens.reserve(3);
	string_found_tokens.reserve(6);
	TokenParser.SetStartCallback([](){});
	TokenParser.SetEndCallback([](){});
	TokenParser.SetDigitCallback([&integer_found_tokens](uint32_t digitToken) {
	integer_found_tokens.push_back(digitToken);
	});
	TokenParser.SetStringCallback([&string_found_tokens](std::string stringToken) {
	string_found_tokens.push_back(std::move(stringToken));
	});
	TokenParser.TParser(input);

	std::vector<uint32_t> integer_expected_tokens = {12, 125, 7777};
	std::vector<std::string> string_expected_tokens = {
	"hello", "mail.ru", "446744073709551616", "1818181818181818181811818", "@#$kkoooklsffsf", "stainherfS"};
	assertVector(integer_found_tokens, integer_expected_tokens);
	assertVector(string_found_tokens, string_expected_tokens);
}

void test_empty_string() {
	TokenParser TokenParser;
	std::vector<uint32_t> integer_found_tokens;
	std::vector<std::string> string_found_tokens;
	integer_found_tokens.reserve(0);
	string_found_tokens.reserve(0);
	TokenParser.SetStartCallback([](){});
	TokenParser.SetEndCallback([](){});
	TokenParser.SetDigitCallback([&integer_found_tokens](uint32_t digitToken) {
	integer_found_tokens.push_back(digitToken);
	});
	TokenParser.SetStringCallback([&string_found_tokens](std::string stringToken) {
	string_found_tokens.push_back(std::move(stringToken));
	});
	TokenParser.TParser("");

	std::vector<uint32_t> integer_expected_tokens = {};
	std::vector<std::string> string_expected_tokens = {};
	assertVector(integer_found_tokens, integer_expected_tokens);
	assertVector(string_found_tokens, string_expected_tokens);
}

void test_one_symbol() {
	TokenParser TokenParser;
	std::vector<uint32_t> integer_found_tokens;
	std::vector<std::string> string_found_tokens;
	integer_found_tokens.reserve(5);
	string_found_tokens.reserve(4);
	TokenParser.SetStartCallback([](){});
	TokenParser.SetEndCallback([](){});
	TokenParser.SetDigitCallback([&integer_found_tokens](uint32_t digitToken) {
	integer_found_tokens.push_back(digitToken);
	});
	TokenParser.SetStringCallback([&string_found_tokens](std::string stringToken) {
	string_found_tokens.push_back(std::move(stringToken));
	});
	TokenParser.TParser("a b c d 1 2 3 4 5");

	std::vector<uint32_t> integer_expected_tokens = {1, 2, 3, 4, 5};
	std::vector<std::string> string_expected_tokens = {"a", "b", "c", "d"};
	assertVector(integer_found_tokens, integer_expected_tokens);
	assertVector(string_found_tokens, string_expected_tokens);
}

int main() {
	std::cout << "-------- C A L L B A C K S -------\n";
	test_without_callback();
	std::cout << "test_without_callback		OK\n";
	test_two_same_callbacks();
	std::cout << "test_two_same_callbacks is	OK\n";

	std::cout << "------------ D I G I T -----------\n";
	test_with_only_digit_tokens();
	std::cout << "test_with_only_digit_tokens is	OK" << std::endl;

	std::cout << "-- O V E R F L O W   D I G I T ---\n";
	test_overflow();
	std::cout << "test_overflow is		OK" << std::endl;

	std::cout << "---------- S T R I N G S ---------\n";
	test_with_only_string_tokens();
	std::cout << "test_with_only_string_tokens is	OK" << std::endl;
	test_string_tabs();
	std::cout << "test_string_tabs is		OK\n";
	test_empty_string();
	std::cout << "test_empty_string is		OK" << std::endl;

	std::cout << "------------ A L L ---------------\n";
	test_one_symbol();
	std::cout << "test_one_symbol is		OK" << std::endl;
	test_all();
	std::cout << "test_all is			OK\n";
	return 0;
}