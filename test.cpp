#include "test.hpp"
#include <iostream>
#include "allocator.hpp"

void test() {
	Allocator a(100);
	a.information();

	if(a.alloc(20))
		a.information();
	else
		std::cout << "\nERROR! 20" << std::endl;

	if(a.alloc(30) != NULL)
		a.information();
	else
		std::cout << "\nERROR! 30" << std::endl;

	std::cout << "\nAfter reset()!\n";
	a.reset();
	a.information();

	if(a.alloc(256))
		a.information();
	else
		std::cout << "ERROR! 256 " << std::endl;

	if(a.alloc(1024))
		a.information();
	else
		std::cout << "ERROR! 1024" << std::endl;

	if(a.alloc(35))
		a.information();
	else
		std::cout << "ERROR! 256" << std::endl;

	return ;
}