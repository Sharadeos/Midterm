all: mid19 unittest

mid19: mid19.cpp
	g++ mid19.cpp -DTEST2 -Wall -o mid19

unittest: mid19.cpp
	g++ mid19.cpp -DTEST -Wall -o unittest
	

clean:
	rm -f mid19
	rm -f unitest
	rm -f *.o
