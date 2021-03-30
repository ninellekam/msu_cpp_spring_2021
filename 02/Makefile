CC = g++
FLAGS = -std=c++17 -g

re: all

all: TokenParser.o test.o
	@$(CC) TokenParser.o test.o -o run

test: TokenParser.o test.o
	@$(CC) TokenParser.o test.o -o test
	@./test

TokenParser.o: TokenParser.cpp TokenParser.hpp
	@$(CC) -c $(FLAGS) TokenParser.cpp

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