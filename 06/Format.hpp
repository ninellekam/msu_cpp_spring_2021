#include	<iostream>
#include	<vector>
#include	<sstream>
#include	<initializer_list>
#include	<unistd.h>

template <class T>
std::string to_str(T&& x) {
	std::stringstream s;
	s << x;
	return s.str();
}

template<class... argsT>
std::string format(const std::string& format_str, argsT&&... args) {
	std::vector<std::string> arguments = {to_str(std::forward<argsT>(args))... };
   	std::string	result_str;
	std::string	str_tmp;
	bool		start_format = false;

	for (size_t i = 0; i < format_str.size(); ++i) {
		if (start_format == true) {
			if (isdigit(format_str[i])) {
				while (isdigit(format_str[i])) {
					str_tmp += format_str[i];
					++i;
				}
				--i;
				if (i == format_str.size() - 1)
					throw std::runtime_error("Error Bracket!\n");
			}
			else {
				if (format_str[i] != '}')
					throw std::runtime_error("Error Bracket!\n");
				if (str_tmp.empty())
					throw std::runtime_error("Empty buffer!\n");
				else {
					size_t index = atoi(str_tmp.c_str());
					if (index > arguments.size() - 1)
						throw std::runtime_error("Out of range!\n");
					else {
						result_str += arguments[index];
						str_tmp.clear();
						start_format = false;
					}
				}
			}
		}
		else {
			if (format_str[i] == '{')
				start_format = true;
			else if (format_str[i] == '}')
				throw std::runtime_error("Error!\n");
			else
				result_str += format_str[i];
		}
		if (format_str[i] != '{' && start_format == true && !isdigit(format_str[i])) {
			throw std::runtime_error("Error!\n");
		}
	}
	return result_str;
}