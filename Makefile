CPP_COMPILER = clang++
CFLAGS = -g -Wall -fstandalone-debug
CPP_VERSION=c++2b 
ENSCRIPT_FLAGS=-C -T 2 -p - -M Letter -Ecpp --color -fCourier8
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all

.PHONY: all bin runMe clean valgrind

all: bin bin/main.exe

bin:
	mkdir -p bin

bin/main.exe: bin src/*.cpp
	${CPP_COMPILER} ${CFLAGS} -std=${CPP_VERSION} -o bin/main.exe src/*.cpp

runMe: bin/main.exe
	bin/main.exe

clean:
	rm -rf bin/main.exe  bin/*.o bin/main.dSYM pdfs/*.pdf

valgrind:	all
		valgrind ${VALGRIND_FLAGS} bin/main.exe