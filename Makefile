all: Part1 Part2

Part1: Part1.o  # test program for Weiss' Vector class.
	g++ -Wall -o Part1 Part1.o  

Part2: Part2.o  # test program for Int Minimal Vector class.
	g++ -Wall -o Part2 Part2.o  

Part1.o: Part1.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o Part1.o -c Part1.cpp 

Part2.o: Itest.cpp BinarySearchTree.h AvlTree.h dsexceptions.h
	g++ -Wall -o Part2.o -c Part2.cpp 

clean:
	rm -f Part1 Part2 *.o
