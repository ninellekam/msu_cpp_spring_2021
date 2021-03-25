#include "allocator.hpp"

Allocator::Allocator(size_t size) {
	maxSize = size;
	makeAllocator(size);
}

void Allocator::check() {
	std::cout <<"-------------\n";
	std::cout << "Memory size:  " << (size_t)(end - begin) << std::endl;
	std::cout << "Current pointer adress:  " << (size_t)(curr) << std::endl;
	std::cout << "Remaining memory size:  " << (size_t)(end - curr) << std::endl;
	std::cout << "Current pointer:  " << (size_t)(curr - begin) << std::endl;
	std::cout <<"-------------\n";
}

void Allocator::makeAllocator(size_t max) {
	if (maxSize > 0)
		begin = new char[maxSize];
	if (!begin || max <= 0)
		std::cout << "makeAlloccator ERROR!\n";
	curr = begin;
	end = begin + maxSize;
}

char* Allocator::alloc(size_t size) {
	if (!size)
		return (NULL);
	curr += size;
	if (curr > end) {
		curr -= size;
		return (NULL);
	}
	return (curr);
}

void Allocator::reset() {
	curr = begin;
}

Allocator::~Allocator() {
	if (begin != NULL)
		free(begin);
	begin = NULL;
	maxSize = 0;
}