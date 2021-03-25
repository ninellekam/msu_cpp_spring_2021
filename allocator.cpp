#include "allocator.hpp"

Allocator::Allocator(size_t size) {
	maxSize = size;
	makeAllocator(size);
}

void Allocator::information() {
	std::cout <<"-------------\n";
	std::cout << "Size Of memory:  " << (size_t)(ptr_end - ptr_begin) << std::endl;
	std::cout << "Current pointer adress:  " << (size_t)(ptr_curr) << std::endl;
	std::cout << "The rest of the memory:  " << (size_t)(ptr_end - ptr_curr) << std::endl;
	std::cout << "Current pointer:  " << (size_t)(ptr_curr - ptr_begin) << std::endl;
	std::cout <<"-------------\n";
}

void Allocator::makeAllocator(size_t max) {
	maxSize = max;
	if (maxSize > 0)
		ptr_begin = new char[maxSize];
	if (!ptr_begin)
		std::cout << "makeAlloccator ERROR!\n";
	ptr_curr = ptr_begin;
	ptr_end = ptr_begin + maxSize;
}

char* Allocator::alloc(size_t size) {
	if (!size)
		return (NULL);
	ptr_curr += size;
	if (ptr_curr > ptr_end) {
		ptr_curr -= size;
		return (NULL);
	}
	return (ptr_curr);
}

void Allocator::reset() {
	ptr_curr = ptr_begin;
}

Allocator::~Allocator() {
	if (ptr_begin != NULL)
		free(ptr_begin);
	ptr_begin = NULL;
	maxSize = 0;
}