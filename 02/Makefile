CC = g++
FLAGS = -std=c++17 -g

re: all

all: parser.o test.o
	@$(CC) parser.o test.o -o run

test: parser.o test.o
	@$(CC) parser.o test.o -o test
	@./test

parser.o: parser.cpp parser.hpp
	@$(CC) -c $(FLAGS) parser.cpp

test.o: test.cpp
	@$(CC) -c $(FLAGS) test.cpp

clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm run
	rm test

.PHONY:
	clean all fclean