CC=g++
CFLAGS =-std=c++17

all: main.o
	@$(CC) main.o -o start

test.o: test.cpp Format.hpp
	@$(CC) -c $(CFLAGS) test.cpp

test: test.o
	@$(CC) test.o -o test
	@./test

clean:
	rm -rf *.o start

fclean:
	rm -rf *.o test