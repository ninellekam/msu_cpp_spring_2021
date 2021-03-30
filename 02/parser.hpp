#ifndef PARSER_HPP
#define PARSER_HPP
#include <iostream>
#include <functional>
#include <string>

using TokenCallback = std::function<void(const std::string & token)>;
using StartEndCallback = std::function<void()>;

class Parser {
private:
	StartEndCallback start_callback;
	TokenCallback digit_callback;
	TokenCallback string_callback;
	StartEndCallback end_callback;
	bool start = false;
	bool end = false;
	bool digit_is = true;

public:
	Parser();
	void set_start_callback(StartEndCallback start_cb);
	void set_digit_callback(TokenCallback digit_cb);
	void set_string_callback(TokenCallback string_cb);
	void set_end_callback(StartEndCallback end_cb);
	void parse(const std::string & text);
	void token_processing(std::string & token, bool & digit);
};

#endif
// class TokenParser
// {
// public:
// 	TokenParser() = default;
// 	SetStartCallback(...);
// 	SetEndCallback(...);
// 	SetDigitTokenCallback(...);
// 	SetStringWithDigitTokenCallback(...);
// 	SetStringCallback(...);
// };

// #endif