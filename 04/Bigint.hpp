#ifndef		BIGINT_HPP
#define		BIGINT_HPP

#include	<iostream>
#include	<vector>
#include	<stdlib.h>
#include	<stdio.h>


class BigInt {
	size_t	len;
	int32_t	*data;
	int32_t neg;
public:
	BigInt();
	BigInt(const std::string &str);
	BigInt(int32_t number);
	BigInt(const BigInt &object);
	BigInt(BigInt &&object);

	BigInt& adder(const char *data, size_t len, const char *object_data, size_t object_len);
	BigInt& minuser(const char *data, size_t len, const char *object_data, size_t object_len);
	BigInt&	operator=(const BigInt &object);
	BigInt& operator=(BigInt &&object);
	BigInt& operator-(const BigInt &object) const;
	BigInt& operator+(const BigInt &object);
	BigInt& operator*(const BigInt &object) const;
	BigInt&	operator-();

	bool	operator>(const BigInt &object) const;
	bool	operator<(const BigInt &object) const;
	bool	operator>=(const BigInt &object) const;
	bool	operator!=(const BigInt &object) const;
	bool	operator<=(const BigInt &object) const;

	friend std::ostream& operator<<(std::ostream & os, const BigInt & obj);
	friend bool operator==(const BigInt & obj1, const BigInt & obj2);
	char * copy_str(size_t i, size_t len, char *tmp, char *data);
	~BigInt();
};

#endif