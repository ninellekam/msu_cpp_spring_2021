CC = g++
FLAGS = -std=c++17 -g
PROJECT=Serializer
LIBNAME=lib$(PROJECT).a

re: all

all: $(LIBNAME)

$(LIBNAME): Serializer.hpp Deserializer.hpp Error.hpp
	ar rc $(LIBNAME) Serializer.hpp Deserializer.hpp Error.hpp

test: $(LIBNAME) test.exe
	@./test.exe $(LIBNAME)

test.exe: test.o $(LIBNAME)
	@$(CC) -o test.exe test.o -L -l$(PROJECT)

test.o: test.cpp
	@$(CC) -c $(FLAGS) test.cpp

clean:
	rm -f *.o

fclean:
	@rm -f *.o
	@rm test.exe
	@rm libSerializer.a

.PHONY:
	clean all fclean