CC=gcc
CFLAGS = -g

qjbprog: qjbprog.o
	$(CC) -o qjbprog qjbprog.o

clean:
	-rm -f qjbprog *.o *~ core a b c d qjbprog-clean.c qjbprog-clean

qjbprog-clean: qjbprog-clean.o
	$(CC) -o qjbprog-clean qjbprog-clean.o

qjbprog-clean.c: RCS/qjbprog.c,v
	co -p1.5 qjbprog.c > qjbprog-clean.c

test: qjbprog-clean qjbprog
	-rm -f a b c d
	./qjbprog-clean -6 > a
	./qjbprog-clean 6 > b
	./qjbprog -6 > c
	./qjbprog 6 > d
	-./qjbprog;
	-./qjbprog 0;
	-./qjbprog 1 1;
	-./qjbprog -129
	-./qjbprog 128
	-diff a c
	-diff b d
