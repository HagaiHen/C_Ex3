all: str stringProg

stringProg: main.o lib.a
		gcc -Wall -g -o stringProg main.o lib.a

str: lib.a

lib.a: function.o
		ar -rcs lib.a function.o

function.o: function.c function.h
		gcc -Wall -g -c function.c

main.o: main.c function.c function.h
		gcc -Wall -g -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a stringProg