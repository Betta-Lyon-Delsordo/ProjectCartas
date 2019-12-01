# ******************************************************
#
# Computer Programming I. Academic Year 2019-2020
# Compilation of exercise #6 in the introduction to project session
#
# ******************************************************

CC   = gcc -Wall

all: ex7

operation07.o: operation07.c operation07.h
	$(CC) -c operation07.c

inout07.o: inout07.c inout07.h
	$(CC) -c inout07.c

ex7: ex7.c inout07.o operation07.o
	$(CC) ex7.c inout07.o operation07.o -o ex7

clean:
	rm -f ex7 *.o *~ *.bak
