test: main.o test.o header.h
	gcc -o test main.c test.o

main.o: main.c header.h
	gcc -c -o main.o -Wall main.c

test.o: test.c header.h
	gcc -c -o test.o -Wall test.c

