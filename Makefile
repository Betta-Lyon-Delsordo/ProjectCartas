# ******************************************************
#
# Computer Programming I. Academic Year 2019-2020
# Final Project for Betta and Eloy
#
# ******************************************************

CC   = gcc -Wall

all: letters

operation.o: operation.c operation.h
	$(CC) -c operation.c

inout.o: inout.c inout.h operation.h
	$(CC) -c inout.c

letters: letters.c inout.o operation.o
	$(CC) letters.c inout.o operation.o -o letters

clean:
	rm -f letters *.o *~ *.bak
