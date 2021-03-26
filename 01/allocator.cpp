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

Allocator::Allocator() {
	begin = nullptr;
	curr = nullptr;
	end = nullptr;
	maxSize = 0;
}

void Allocator::makeAllocator(size_t max) {
	maxSize = max;
	assert(max > 0);
	if (maxSize > 0) {
		if (begin != nullptr) {
			delete [] begin;
			begin = nullptr;
		}
		begin = new char[maxSize];
	}
	curr = begin;
	end = begin + maxSize;
	return ;
}

char* Allocator::alloc(size_t size) {
	if (size < 0 || maxSize <= 0)
		return (nullptr);
	curr += size;
	if (curr > end) {
		curr -= size;
		return (nullptr);
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
	if (begin != nullptr)
		delete [] begin;
	begin = nullptr;
	maxSize = 0;
}