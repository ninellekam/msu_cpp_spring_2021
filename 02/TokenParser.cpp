#include "TokenParser.hpp"

TokenParser::TokenParser() {
	start_callback = [](){};
	digit_callback = [](uint32_t & token) {};
	string_callback = [](const std::string & token) {};
	end_callback = [](){};
}

void TokenParser::SetStartCallback(StartEndCallback start_cb = nullptr) {
	if (start_cb != nullptr)
		start_callback = start_cb;
}

void TokenParser::SetDigitCallback(TokenDigitCallback digit_cb) {
	if (digit_cb != nullptr)
		digit_callback = digit_cb;
}

void TokenParser::SetStringCallback(TokenCallback string_cb) {
	if (string_cb != nullptr)
		string_callback = string_cb;
}

void TokenParser::SetEndCallback(StartEndCallback end_cb) {
	if (end_cb != nullptr)
		end_callback = end_cb;
}

bool	ft_isspace(char c) {
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v');
}

bool	ft_isdigit(char c) {
	return (c >= '0' && c <= '9');
}

void TokenParser::TParser(const std::string & text) {
	start_callback();
	std::string	token;
	auto it = text.begin();

	while (it != text.end()) {
		while (!ft_isspace(*it) && it != text.end()) {
			char c = *it;
			token.push_back(c);
			if (!ft_isdigit(c))
				digit_is = false;
			++it;
		}
		while (ft_isspace(*it) && it != text.end())
			++it;
		--it;
		if (token == "")
				break;
		if (digit_is == true) {
			unsigned long long dig;
			char * pEnd;
			dig = strtoull(token.c_str(), &pEnd, 10);
			uint32_t d = dig;
			if (dig > 446744073709551615)
				string_callback(token);
			else
				digit_callback(d);
		}
		else
			string_callback(token);
		token.clear();
		digit_is = true;
		if (it != text.end())
			++it;
	}
	end_callback();
}