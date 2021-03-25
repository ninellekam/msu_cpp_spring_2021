#include "test.hpp"

void test() {
	Allocator a(1024);
	a.information();

	if(a.alloc(512))
		a.information();
	else
		std::cout << "ERROR!" << std::endl;

	if(a.alloc(256))
		a.information();
	else
		std::cout << "ERROR!" << std::endl;

	a.reset();
	a.information();

	if(a.alloc(256))
		a.information();
	else
		std::cout << "ERROR!" << std::endl;

	if(a.alloc(1024))
		a.information();
	else
		std::cout << "ERROR!" << std::endl;

	if(a.alloc(256))
		a.information();
	else
		std::cout << "ERROR!" << std::endl;

	return ;
}