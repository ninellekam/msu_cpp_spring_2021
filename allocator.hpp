#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <string>

static char *ptr = NULL;
static size_t maxSize = 0;
static size_t current_ptr_size = 0;

class Allocator
{
public:
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
	~Allocator();
};

void Allocator::makeAllocator(size_t maxSize) {
	if (maxSize > 0)
		ptr = new char[maxSize];
}

char* Allocator::alloc(size_t size) {
	if (size > maxSize - current_ptr_size || ptr == NULL)
		return (NULL);
	current_ptr_size += size;
	size_t offset = current_ptr_size - size;
	if (offset < 0 )
		return (NULL);
	return (ptr + offset);
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