CC = g++
FLAGS = -std=c++17 -Wall -Wextra -Werror -g

re: all

all: main.o allocator.o test.o
	@$(CC) main.o test.o allocator.o -o run

test: main.o allocator.o test.o
	@$(CC) main.o test.o allocator.o -o test
	@./test

main.o: main.cpp test.hpp
	@$(CC) -c $(FLAGS) main.cpp

allocator.o: allocator.cpp allocator.hpp
	@$(CC) -c $(FLAGS) allocator.cpp

test.o: test.cpp test.hpp
	@$(CC) -c $(FLAGS) test.cpp

clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm run
	rm test

.PHONY:
	clean all fclean