#include "TokenParser.hpp"

TokenParser::TokenParser() {
	start_callback = [](){};
	digit_callback = [](const std::string & token) {};
	string_callback = [](const std::string & token) {};
	end_callback = [](){};
}

void TokenParser::SetStartCallback(StartEndCallback start_cb) {
	start_callback = start_cb;
}

void TokenParser::SetDigitCallback(TokenCallback digit_cb) {
	digit_callback = digit_cb;
}

void TokenParser::SetStringCallback(TokenCallback string_cb) {
	string_callback = string_cb;
}

void TokenParser::SetEndCallback(StartEndCallback end_cb) {
	end_callback = end_cb;
}

bool	ft_isspace(char c) {
	return (c == ' ' || c == '\n' || c == '\t');
}

bool	ft_isdigit(char c) {
	return (c >= '0' && c <= '9');
}

void TokenParser::TParser(const std::string & text) {
	start_callback();
	std::string	token;
	auto it = text.begin();
	int	n_digit = 0;

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
		if (digit_is == true) {
			digit_callback(token);
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