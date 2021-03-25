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

#endif