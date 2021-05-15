#ifndef		TEST_HPP
#define		TEST_HPP

#include	<iostream>
#include	<sstream>
#include	<cassert>
#include	<cctype>
#include	"Serializer.hpp"
#include	"Deserializer.hpp"
#include	"Error.hpp"

struct Data {
	uint64_t a;
	bool b;
	uint64_t c;

	template <class Serializer>
	Error serialize(Serializer& source){
		return source(a, b, c);
	}

	Error deserialize(Deserializer& source){
		return source(a, b, c);
	}
};

#endif