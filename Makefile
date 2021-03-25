CC = g++
FLAGS = -std=c++11 -Wall -Wextra -Werror -g

all: main.o allocator.o test.o
	$(CC) main.o test.o allocator.o -o run

main.o: main.cpp test.hpp
	g++ -c main.cpp

allocator.o: allocator.cpp allocator.hpp
	$(CC) -c allocator.cpp

test.o: test.cpp test.hpp
	g++ -c test.cpp

clean:
	rm -f *.o
