CC = g++
FLAGS = -std=c++11 -Wall -Wextra -Werror -g

all: test.o allocator.o
	$(CC) test.o allocator.o -o run

test.o: test.cpp test.hpp
	g++ -c test.cpp

allocator.o: allocator.cpp allocator.hpp
	$(CC) -c allocator.cpp

clean:
	rm -f *.o run

.PHONY:
	clean all