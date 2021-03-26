#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <string>

class Allocator
{
private:
	size_t maxSize;
	char *end;
	char *curr;
	char *begin;
public:
	size_t getCurrPtr();
	Allocator();
	void makeAllocator(size_t maxSize);
	char* alloc(size_t size);
	void reset();
	void check();
	~Allocator();
};

#endif