CC = g++
FLAGS = -std=c++17 -g

re: all

all: Matrix.o test.o
	@$(CC) Matrix.o test.o

test: Matrix.o test.o
	@$(CC) Matrix.o test.o -o test
	@./test

Matrix.o: Matrix.cpp Matrix.hpp
	@$(CC) -c $(FLAGS) Matrix.cpp

test.o: test.cpp test.hpp
	@$(CC) -c $(FLAGS) test.cpp

clean:
	rm -f *.o

fclean:
	@rm -f *.o
	@rm test

.PHONY:
	clean all fclean