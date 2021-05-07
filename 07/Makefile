all: test
test: test.cpp
	g++ -std=c++11 -o my_prog test.cpp
	./my_prog
clean:
	rm -rf *.o my_prog

# CC = g++
# FLAGS = -std=c++17 -g

# re: all

# all: Vector.o test.o
# 	@$(CC) Vector.o test.o

# test: Bigint.o test.o
# 	@$(CC) Bigint.o test.o -o test
# 	@./test

# Vector.o: Vector.cpp Vector.hpp
# 	@$(CC) -c $(FLAGS) Vector.cpp

# test.o: test.cpp test.hpp
# 	@$(CC) -c $(FLAGS) test.cpp

# clean:
# 	rm -f *.o

# fclean:
# 	@rm -f *.o
# 	@rm test

# .PHONY:
# 	clean all fclean