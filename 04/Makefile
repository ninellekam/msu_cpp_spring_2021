CC = g++
FLAGS = -std=c++17 -g

re: all

all: Bigint.o test.o
	@$(CC) Bigint.o test.o

test: Bigint.o test.o
	@$(CC) Bigint.o test.o -o test
	@./test

Bigint.o: Bigint.cpp Bigint.hpp
	@$(CC) -c $(FLAGS) Bigint.cpp

test.o: test.cpp test.hpp
	@$(CC) -c $(FLAGS) test.cpp

clean:
	rm -f *.o

fclean:
	@rm -f *.o
	@rm test

.PHONY:
	clean all fclean