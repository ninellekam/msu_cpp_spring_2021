CC = g++
FLAGS = -std=c++17 -g

re: all

all: test.o
	@$(CC) test.o

test.o:
	$(CC) $(FLAGS) test.cpp -c
test: test.o
	$(CC) $(FLAGS) test.o -o test
	./test

clean:
	rm -f *.o

fclean:
	@rm -f *.o
	@rm test

.PHONY:
	clean all fclean