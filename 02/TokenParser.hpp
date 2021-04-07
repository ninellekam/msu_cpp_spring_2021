#ifndef					TOKEN_PARSER_HPP
#define					TOKEN_PARSER_HPP

#include				<iostream>
#include				<functional>
#include				<string>
#include				<cstdlib>

using					TokenCallback = std::function<void(const std::string & token)>;
using					TokenDigitCallback = std::function<void(uint32_t & token)>;
using					StartEndCallback = std::function<void()>;

class					TokenParser {
private:
	StartEndCallback		start_callback;
	TokenDigitCallback		digit_callback;
	TokenCallback			string_callback;
	StartEndCallback		end_callback;
	bool				digit_is = true;
public:
	TokenParser();
	void				SetStartCallback(StartEndCallback start_cb);
	void				SetDigitCallback(TokenDigitCallback digit_cb);
	void				SetStringCallback(TokenCallback string_cb);
	void				SetEndCallback(StartEndCallback end_cb);
	void				TParser(const std::string & text);
};

#endif
