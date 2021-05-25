CC = g++
FLAGS = -std=c++17 -g

re: fclean all

all: Sort.o test.o

test: Sort.o test.o
	@$(CC) $(FLAGS) -o test test.o Sort.o -pthread
	@./test

Sort.o: Sort.cpp Sort.hpp
	@$(CC) $(FLAGS) -c Sort.cpp

test.o: test.cpp test.hpp
	@$(CC) $(FLAGS) -c test.cpp

clean:
	@rm -f *.o

fclean:
	@rm -f *.o
	@rm test

.PHONY:
	clean all fclean