#include "allocator.hpp"

void Allocator::check() {
	std::cout <<"-------------\n";
	std::cout << "Memory size:  " << (size_t)(end - begin) << std::endl;
	std::cout << "Current pointer adress:  " << (size_t)(curr) << std::endl;
	std::cout << "Remaining memory size:  " << (size_t)(end - curr) << std::endl;
	std::cout << "Current pointer:  " << (size_t)(curr - begin) << std::endl;
	std::cout <<"-------------\n";
	return ;
}

void Allocator::makeAllocator(size_t max) {
	maxSize = max;
	assert(max > 0);
	if (maxSize > 0)
		begin = new char[maxSize];
	curr = begin;
	end = begin + maxSize;
	return ;
}

char* Allocator::alloc(size_t size) {
	if (size < 0 || maxSize <= 0)
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
	return ;
}

size_t Allocator::getCurrPtr() {
	return ((size_t)(curr - begin));
}

Allocator::~Allocator() {
	if (begin != NULL)
		free(begin);
	begin = NULL;
	maxSize = 0;
}