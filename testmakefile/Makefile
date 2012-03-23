main: main.o my1.o my2.o
	gcc -o main main.o my1.o my2.o
main.o: main.c my1.h my2.h
	gcc -c main.c
my1.o: my1.c my1.h my2.h
	gcc -c my1.c
my2.o: my2.c my2.h
	gcc -c my2.c
