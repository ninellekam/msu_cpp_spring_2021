#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <string>

class Allocator
{
private:
	char *end;
	size_t maxSize;
	char *curr;
	char *begin;
public:
	Allocator(size_t size);
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
	void check();
	~Allocator();
};

#endif