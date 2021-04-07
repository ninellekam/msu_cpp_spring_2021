#include "test.hpp"

template <typename T>
void assertVector(const std::vector<T> &generated, const std::vector<T> &expected) {
	assert(generated.size() == expected.size());
	assert(std::equal(generated.begin(), generated.end(), expected.begin()));
}

void test_without_callback() {
	TokenParser	TokenParser;
	TokenParser.TParser("abc def 123    678    agsj");
}

void test_all() {
	std::string str;
	std::vector<uint32_t> DigitFound;
	std::vector<std::string> StringFound;
	TokenParser TokenParser;
	DigitFound.reserve(2);
	StringFound.reserve(5);
	TokenParser.SetStartCallback([&str](){str += "Start";});
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetDigitCallback([&DigitFound](uint32_t digitToken) {
	DigitFound.push_back(digitToken);
	});
	TokenParser.SetStringCallback([&StringFound](std::string stringToken) {
	StringFound.push_back(std::move(stringToken));
	});
	TokenParser.TParser("jfajfa7873831318##$$!@!$!    \
			+14 -15 15 3218713     \
			jjHSHJAskAKSK12Q@!@");

	std::vector<uint32_t> DigitExpected = {15, 3218713};
	std::vector<std::string> StringExpected = {
	"jfajfa7873831318##$$!@!$!", "+14", "-15", "jjHSHJAskAKSK12Q@!@"};
	assertVector(DigitFound, DigitExpected);
	assertVector(StringFound, StringExpected);
	assert(str == "StartEnd");
}

void test_string_tabs() {
	std::string str;
	std::vector<uint32_t> DigitFound;
	std::vector<std::string> StringFound;
	TokenParser TokenParser;
	DigitFound.reserve(0);
	StringFound.reserve(0);
	TokenParser.SetStartCallback([&str](){str += "Start";});
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetDigitCallback([&DigitFound](uint32_t digitToken) {
	DigitFound.push_back(digitToken);
	std::cout << digitToken;
	});
	TokenParser.SetStringCallback([&StringFound](std::string stringToken) {
	StringFound.push_back(std::move(stringToken));
	});
	TokenParser.TParser("   \t    \t\n");
	std::vector<uint32_t> DigitExpected = {};
	std::vector<std::string> StringExpected = {};
	assertVector(DigitFound, DigitExpected);
	assertVector(StringFound, StringExpected);
	assert(str == "StartEnd");
}

void test_with_only_string_tokens() {
	std::string str;
	std::vector<uint32_t> DigitFound;
	std::vector<std::string> StringFound;
	TokenParser TokenParser;
	DigitFound.reserve(4);
	StringFound.reserve(5);
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetDigitCallback([&DigitFound, &str](uint32_t digitToken) { str += "1"; DigitFound.push_back(digitToken); });
	TokenParser.SetStringCallback([&StringFound](std::string stringToken) { StringFound.push_back(stringToken); });
	TokenParser.SetDigitCallback([&DigitFound, &str](uint32_t digitToken) { str += "2"; DigitFound.push_back(digitToken); });
	TokenParser.TParser("jfajfa7873831318##$$!@!$!    \
			+14 -15 15 3218713     \
			jjHSHJAskAKSK12 1222 5555 Q@!@");

	std::vector<uint32_t> DigitExpected = {15, 3218713, 1222, 5555};
	std::vector<std::string> StringExpected = {
	"jfajfa7873831318##$$!@!$!", "+14", "-15", "jjHSHJAskAKSK12", "Q@!@"};
	assertVector(DigitFound, DigitExpected);
	assertVector(StringFound, StringExpected);
	assert(str == "2222End");
}

void test_with_only_digit_tokens() {
	std::string str;
	std::vector<uint32_t> DigitFound;
	std::vector<std::string> StringFound;
	TokenParser TokenParser;
	DigitFound.reserve(3);
	StringFound.reserve(0);
	TokenParser.SetStartCallback([&str](){str += "Start";});
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetStringCallback([&StringFound](std::string stringToken) { StringFound.push_back(stringToken); });
	TokenParser.SetDigitCallback([&DigitFound, &str](uint32_t digitToken) { DigitFound.push_back(digitToken); });
	TokenParser.TParser("25 \t\v\t    \n  778234 1273134");
	std::vector<uint32_t> DigitExpected = {25, 778234, 1273134};
	std::vector<std::string> StringExpected = {};
	assertVector(DigitFound, DigitExpected);
	assertVector(StringFound, StringExpected);
	assert(str == "StartEnd");
}

void test_with_no_start() {
	std::string str;
	std::vector<uint32_t> DigitFound;
	std::vector<std::string> StringFound;
	TokenParser TokenParser;
	DigitFound.reserve(3);
	StringFound.reserve(0);
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetStringCallback([&StringFound](std::string stringToken) { StringFound.push_back(stringToken); });
	TokenParser.SetDigitCallback([&DigitFound, &str](uint32_t digitToken) {DigitFound.push_back(digitToken); });
	TokenParser.TParser("25 \t\v\t    \n  778234 1273134");
	std::vector<uint32_t> DigitExpected = {25, 778234, 1273134};
	std::vector<std::string> StringExpected = {};
	assertVector(DigitFound, DigitExpected);
	assertVector(StringFound, StringExpected);
	assert(str == "End");
}

void test_two_same_callbacks() {
	std::string str;
	std::vector<uint32_t> DigitFound;
	std::vector<std::string> StringFound;
	TokenParser TokenParser;
	DigitFound.reserve(4);
	StringFound.reserve(5);
	TokenParser.SetStartCallback([&str](){str += "Start";});
	TokenParser.SetEndCallback([&str](){str += "End";});
	TokenParser.SetDigitCallback([&DigitFound, &str](uint32_t digitToken) {
	str += "1";
	DigitFound.push_back(digitToken);
	});
	TokenParser.SetStringCallback([&StringFound](std::string stringToken) {
	StringFound.push_back(stringToken);
	});
	TokenParser.SetDigitCallback([&DigitFound, &str](uint32_t digitToken) {
	str += "2";
	DigitFound.push_back(digitToken);
	});
	TokenParser.TParser("jfajfa7873831318##$$!@!$!    \
			+14 -15 15 3218713     \
			jjHSHJAskAKSK12 1222 5555 Q@!@");

	std::vector<uint32_t> DigitExpected = {15, 3218713, 1222, 5555};
	std::vector<std::string> StringExpected = {
	"jfajfa7873831318##$$!@!$!", "+14", "-15", "jjHSHJAskAKSK12", "Q@!@"};
	assertVector(DigitFound, DigitExpected);
	assertVector(StringFound, StringExpected);
	assert(str == "Start2222End");
}

void test_overflow() {
	TokenParser TokenParser;
	std::string input("hello mail.ru 12 446744073709551616 125 7777 1818181818181818181811818 \
			@#$kkoooklsffsf stainherfS     \
	");
	std::vector<uint32_t> DigitFound;
	std::vector<std::string> StringFound;
	DigitFound.reserve(3);
	StringFound.reserve(6);
	TokenParser.SetStartCallback([](){});
	TokenParser.SetEndCallback([](){});
	TokenParser.SetDigitCallback([&DigitFound](uint32_t digitToken) {
	DigitFound.push_back(digitToken);
	});
	TokenParser.SetStringCallback([&StringFound](std::string stringToken) {
	StringFound.push_back(stringToken);
	});
	TokenParser.TParser(input);

	std::vector<uint32_t> DigitExpected = {12, 125, 7777};
	std::vector<std::string> StringExpected = {
	"hello", "mail.ru", "446744073709551616", "1818181818181818181811818", "@#$kkoooklsffsf", "stainherfS"};
	assertVector(DigitFound, DigitExpected);
	assertVector(StringFound, StringExpected);
}

void test_empty_string() {
	TokenParser TokenParser;
	std::vector<uint32_t> DigitFound;
	std::vector<std::string> StringFound;
	DigitFound.reserve(0);
	StringFound.reserve(0);
	TokenParser.SetStartCallback([](){});
	TokenParser.SetEndCallback([](){});
	TokenParser.SetDigitCallback([&DigitFound](uint32_t digitToken) {
	DigitFound.push_back(digitToken);
	});
	TokenParser.SetStringCallback([&StringFound](std::string stringToken) {
	StringFound.push_back(stringToken);
	});
	TokenParser.TParser("");

	std::vector<uint32_t> DigitExpected = {};
	std::vector<std::string> StringExpected = {};
	assertVector(DigitFound, DigitExpected);
	assertVector(StringFound, StringExpected);
}

void test_one_symbol() {
	TokenParser TokenParser;
	std::vector<uint32_t> DigitFound;
	std::vector<std::string> StringFound;
	DigitFound.reserve(5);
	StringFound.reserve(4);
	TokenParser.SetStartCallback([](){});
	TokenParser.SetEndCallback([](){});
	TokenParser.SetDigitCallback([&DigitFound](uint32_t digitToken) {
	DigitFound.push_back(digitToken);
	});
	TokenParser.SetStringCallback([&StringFound](std::string stringToken) {
	StringFound.push_back(stringToken);
	});
	TokenParser.TParser("a b c d 1 2 3 4 5");

	std::vector<uint32_t> DigitExpected = {1, 2, 3, 4, 5};
	std::vector<std::string> StringExpected = {"a", "b", "c", "d"};
	assertVector(DigitFound, DigitExpected);
	assertVector(StringFound, StringExpected);
}

void test_nullptr_callback() {
	TokenParser TokenParser;
	std::vector<uint32_t> DigitFound;
	std::vector<std::string> StringFound;
	DigitFound.reserve(0);
	StringFound.reserve(4);
	TokenParser.SetStartCallback(nullptr);
	TokenParser.SetEndCallback([](){});
	TokenParser.SetDigitCallback(nullptr);
	TokenParser.SetStringCallback([&StringFound](std::string stringToken) {
	StringFound.push_back(stringToken);
	});
	TokenParser.TParser("a b c d 1 2 3 4 5");

	std::vector<uint32_t> DigitExpected = {};
	std::vector<std::string> StringExpected = {"a", "b", "c", "d"};
	assertVector(DigitFound, DigitExpected);
	assertVector(StringFound, StringExpected);
}

int main() {
	std::cout << "-------- C A L L B A C K S -------\n";
	test_without_callback();
	std::cout << "test_without_callback		OK\n";
	test_two_same_callbacks();
	std::cout << "test_two_same_callbacks is	OK\n";
	test_nullptr_callback();
	std::cout << "test_nullptr_callback is	OK\n";

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