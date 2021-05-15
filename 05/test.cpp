#include "test.hpp"

int main(){
	Data x { 1, true, 2 };

	std::stringstream stream;

	Serializer serializer(stream);
	serializer.save(x);

	Data y { 1, true, 2 };

	Deserializer deserializer(stream);
	const Error err = deserializer.load(y);

	assert( err == Error::NoError );

	assert(x.a == y.a);
	std::cout << "Test 1 is OK!\n";
	assert(x.b == y.b);
	std::cout << "Test 2 is OK!\n";
	assert(x.c == y.c);
	std::cout << "Test 3 is OK!\n";
	return 0;
}