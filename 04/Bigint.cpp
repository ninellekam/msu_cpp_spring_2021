#include "Bigint.hpp"

BigInt::BigInt() : len(1) {
	data = new char[len];
	data[0] = 0;
	data[1] = '\0';
}

BigInt::BigInt(const std::string & str) {
	int flag_minus, flag_plus;
	size_t i = 0, len = 0;

	flag_minus = str[0] == '-' ? 1: 0;
	flag_plus = str[0] == '+'? 1: 0;
	i = flag_minus + flag_plus;

	while (str[i] == '0')
		++i;
	len = str.size() - i + flag_minus + flag_plus;
	data = new char[len];
	for(int j = i; j < len; ++j) {
		if (flag_minus)
			data[0] = '-';
		if (!isdigit(str[j]))
			throw std::invalid_argument("Error argument!");
		else
			data[j] = str[j];
	}
}

BigInt::BigInt(const int32_t & number){
	BigInt my_copy(std::to_string(number));
	len = my_copy.len;
	data = new char [len];
	data = my_copy.data;
}

BigInt::BigInt(const BigInt & object) {
	len = object.len;
	data = new char[len];
	for(size_t i = 0; i < len; ++i)
		data[i] = object.data[i];
	data[len] = '\0';
}

BigInt::BigInt(BigInt && object) {
	len = object.len;
	data = object.data;
	object.data = nullptr;
	object.len = 0;
}

BigInt& BigInt::operator=(const BigInt &object) {
	if (this == &object)
		return *this;
	delete [] data;
	char *tmp = new char[len];
	data = tmp;
	tmp = nullptr;
	size_t len = object.len;
	for(int i = 0; i < len; ++i)
		data[i] = object.data[i];
	data[len] = '\0';
	return *this;
}

BigInt& BigInt::operator=(BigInt &&object) {
	if (this == &object)
		return *this;
	delete [] data;
	len = object.len;
	data = object.data;
	object.data = nullptr;
	object.len = 0;
	return *this;
}

