CC = g++
FLAGS = -std=c++17 -g

all: test

test: Thread.o test.o
	$(CC) $(FLAGS) -o test test.o Thread.o -pthread
	./test

Thread.o: Thread.cpp Thread.hpp
	$(CC) $(FLAGS) -c Thread.cpp

test.o: test.cpp test.hpp
	$(CC) $(FLAGS) -c test.cpp

clean:
	rm -f *.o

fclean:
	@rm -f *.o
	@rm test

.PHONY:
	clean all fclean