#include "parser.hpp"


Parser::Parser() {
	start_callback = [](){};
	digit_callback = [](const std::string & token) {};
	string_callback = [](const std::string & token) {};
	end_callback = [](){};
}

void Parser::set_start_callback(StartEndCallback start_cb) {
	start_callback = start_cb;
}

void Parser::set_digit_callback(TokenCallback digit_cb) {
	digit_callback = digit_cb;
}

void Parser::set_string_callback(TokenCallback string_cb) {
	string_callback = string_cb;
}

void Parser::set_end_callback(StartEndCallback end_cb) {
	end_callback = end_cb;
}

bool	ft_isspace(char c) {
	return (c == ' ' ||
			c == '\n' ||
			c == '\t');
}

bool	ft_digit_is(char c) {
	return (c >= '0' && c <= '9');
}

void Parser::parse(const std::string & text) {
	start_callback();
	std::string token;
	auto it = text.begin();
	int n_digit = 0;

	while (it != text.end()) {
		while (!isspace(*it) && it != text.end()) {
			char c = *it;
			token.push_back(c);
			if (!isdigit(c))
				digit_is = false;
			++it;
		}
		while (isspace(*it) && it != text.end())
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