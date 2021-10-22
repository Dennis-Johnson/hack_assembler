c++ = clang++
flags = -Wall -pedantic -std=c++11
target = assembler

all: $(target)

$(target): main.o
	$(c++) $(flags) main.o -o $(target)

main: main.cpp
	$(c++) $(flags) -c main.cpp

clean:
	rm -rf .dSYM *.o $(target)