#include "Bigint.hpp"

BigInt::BigInt() : len(0) {
	data = new int32_t[len];
	neg = 0;
}

BigInt::BigInt(const std::string & str) {
	size_t i = 0, len = 0;

	if (str[0] == '-')
		neg = 1;
	else
		neg = 0;
	while (str[i] == '0')
		++i;
	this->len = str.size() - neg - i;
	this->data = new int[this->len];
	for(int j = 0; j < this->len; ++j) {
		this->data[j] = str[j + neg + i] - '0';
	}
}

bool operator==(const BigInt & obj1, const BigInt & obj2) {
	if (obj1.len != obj2.len || obj1.neg != obj2.neg)
		return false;
	for (size_t i = 0; i < obj1.len; ++i) {
		if (obj1.data[i] != obj2.data[i]) {
			return false;
		}
	}
	return true;
}

BigInt::BigInt(int32_t number){
	int32_t obj = number;
	size_t size = 0;

	while (obj) {
		obj /= 10;
		++size;
	}
	if (number == 0)
		size = 1;
	neg = number < 0;
	if (neg)
		number = -number;

	len = size;
	data = new int32_t [len];
	for(size_t i = 0; i < len; ++i) {
		data[i] = number % 10;
		number /= 10;
	}
	std::reverse(data, data + size);
}

// BigInt::BigInt(const BigInt & object) {
// 	len = object.len;
// 	data = new char[len];
// 	for(size_t i = 0; i < len; ++i)
// 		data[i] = object.data[i];
// 	data[len] = '\0';
// }

// BigInt::BigInt(BigInt && object) {
// 	len = object.len;
// 	data = object.data;
// 	object.data = nullptr;
// 	object.len = 0;
// }

BigInt&	BigInt::operator=(const BigInt &object) {
	if (this == &object)
		return *this;
	delete [] data;
	int *tmp = new int[len];
	data = tmp;
	tmp = nullptr;
	size_t len = object.len;
	for(int i = 0; i < len; ++i)
		data[i] = object.data[i];
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

bool	BigInt::operator>(const BigInt &object) const {
	if (this == &object)
		return false;
	if (neg != 1 && object.neg == 1)
		return true;
	else if (neg == 1 && object.neg != 1)
		return false;
	if (neg == 1 && object.neg == 1) {
		if (len != object.len) {
			if (len < object.len)
				return true;
			else
				return false;
		}
		for(size_t i = 1; i < len; ++i) {
			if (data[i] < object.data[i])
				return true;
			else if (data[i] > object.data[i])
				return false;
		}
	}
	if (neg != 1 && object.neg != 1) {
		if (len < object.len)
			return false;
		else if (len > object.len)
			return true;
		for (size_t i = 0; i < len; ++i) {
			if (data[0] > object.data[0])
				return true;
			else if (data[0] < object.data[0])
				return false;
		}
	}
	return false;
}

bool BigInt::operator!=(const BigInt & object) const {
	return !(*this == object);
}

bool BigInt::operator<(const BigInt & object) const {
	if (*this == object)
		return false;
	return !(*this > object);
}

bool BigInt::operator>=(const BigInt & object) const {
	return *this == object || *this > object;
}

bool BigInt::operator<=(const BigInt & object) const {
	return *this == object || *this < object;
}

// BigInt& BigInt::adder(const char *data, size_t len, const char *object_data, size_t object_len){
// 	size_t max_len = std::max(len, object_len);
// 	char *tmp = new char [max_len + 1];
// 	tmp[max_len + 1] = '\0';
// 	size_t i = len + 1, j = object_len + 1, over = 0;
// 	while (--i > 0 && --j > 0) {
// 		over = (data[i] - '0') + (object_data[j] - '0') + over;
// 		tmp[i] = char(over % 10 + '0');
// 		over = over / 10;
// 	}
// 	while (--i > 0) {
// 		over = (data[i] - '0') + over;
// 		tmp[i] = char(over % 10 + '0');
// 		over = over / 10;
// 	}
// 	while (--j > 0) {
// 		over = (data[j] - '0') + over;
// 		tmp[j] = char(over % 10 + '0');
// 		over = over / 10;
// 	}
// 	tmp[0] = char(over + '0');
// 	BigInt tmp_return(tmp);
// 	delete [] tmp;
// 	return tmp_return;
// }

// BigInt& BigInt::minuser(const char *data, size_t len, const char *object_data, size_t object_len){
// 	char * tmp = new char[len];
// 	bool borrow = false;
// 	size_t i = 0;
// 	for(; i < object_len; i++) {
// 		if((data[len - 1 - i] - '0') - borrow < (object_data[object_len - 1 - i] - '0')) {
// 			tmp[len - 1 - i] = char(data[len - 1 - i] + 10 - borrow - object_data[object_len - 1 - i] + '0');
// 			borrow = 1;
// 		}
// 		else {
// 			tmp[len - 1 - i] = char(data[len - 1 - i] - borrow - object_data[object_len - 1 - i] + '0');
// 			borrow = 0;
// 		}
// 	}
// 	for(; i<len; i++) {
// 		if(borrow and data[len - 1 - i] == '0') {
// 			tmp[len - 1 - i] = '9';
// 			borrow = 1;
// 		}
// 		else {
// 			tmp[len - 1 - i] = char(data[len - 1 - i] - borrow);
// 			borrow = 0;
// 		}
// 	}
// 	tmp[len] = '\0';
// 	BigInt val(tmp);
// 	delete[] tmp;
// 	return val;
// }

// char * BigInt::copy_str(size_t j, size_t len, char *tmp, char *data){
// 	for(size_t i = j; i < len; ++i)
// 		tmp[i] = data[i];
// 	tmp[len] = '\0';
// 	return tmp;
// }

// BigInt& BigInt::operator-(){
// 	size_t flag_minus = data[0] == '-' ? 1: 0;
// 	char *tmp;
// 	if (flag_minus == 1) {
// 		tmp = new char [len - 1];
// 		tmp = copy_str(0, len - 1, tmp, data);
// 	}
// 	else if (flag_minus == 0) {
// 		tmp = new char [len + 1];
// 		tmp[0] = '-';
// 		tmp = copy_str(1, len + 1, tmp, data);
// 	}
// 	BigInt ob(tmp);
// 	delete [] tmp;
// 	return ob;
// }

std::ostream& operator<<(std::ostream & os, const BigInt & obj) {
	if (obj.neg == 1)
		os << "-";
	for (size_t i = 0; i < obj.len; ++i)
		os << obj.data[i];
	return os;
}

BigInt::~BigInt() {
	if (data)
		delete [] data;
}