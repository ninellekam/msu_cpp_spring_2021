#include "test.hpp"

void test() {
	std::cout << "New emory allocated!" << std::endl;
	Allocator a(1024);
	a.information();

	if(a.alloc(512))	a.information();
	else	std::cout << "Bad alloc!" << std::endl;


	if(a.alloc(256))	a.information();
	else	std::cout << "Bad alloc!" << std::endl;

	std::cout << "Reset!" << std::endl;
	a.reset();
	a.information();

	if(a.alloc(256))	a.information();
	else	std::cout << "Bad alloc!" << std::endl;

	if(a.alloc(1024))	a.information();
	else	std::cout << "Bad alloc!" << std::endl;

	if(a.alloc(256))	a.information();
	else	std::cout << "Bad alloc!" << std::endl;

}