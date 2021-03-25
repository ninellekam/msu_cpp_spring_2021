#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <string>

class Allocator
{
private:
	char *ptr;
	size_t maxSize;
	size_t current_ptr_size;
public:
	Allocator(size_t size);
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
	void information();
	~Allocator();
};

Allocator::Allocator(size_t size) {
	maxSize = size;
}

void Allocator::information() {
	std::cout << "Size Of memory:  " << (size_t)(ptr - current_ptr_size) << std::endl;
	//std::cout << "Start pointer:  " << (size_t)ptr_begin << std::endl;
	std::cout << "Current pointer adress:  " << (size_t)(current_ptr_size) << std::endl;
	std::cout << "The rest of the memory:  " << (size_t)(ptr - current_ptr_size) << std::endl;
	std::cout << "Current pointer:  " << (size_t)(current_ptr_size) << std::endl;
	std::cout << std::endl;
}

void Allocator::makeAllocator(size_t max) {
	maxSize = max;
	if (maxSize > 0)
		ptr = new char[maxSize];
	if (!ptr)
		std::cout << "nullptr";
}

char* Allocator::alloc(size_t size) {
	std::cout << "size\n";
	if (size)
		return (NULL);
	if (size > maxSize - current_ptr_size || ptr == NULL)
		return (NULL);
	std::cout << "B\n";
	current_ptr_size += size;
	size_t offset = current_ptr_size - size;
		std::cout << "C\n";
	if (offset < 0 )
		return (NULL);
	if (ptr + offset != NULL)
		return (ptr + offset);
	return (NULL);
}

void Allocator::reset() {
	current_ptr_size = 0;
}

Allocator::~Allocator() {
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
	current_ptr_size = 0;
}

#endif