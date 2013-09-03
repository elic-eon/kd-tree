all: kdtree.a

example: kdtree.a
	g++ test.cpp kdtree.a -o test

kdtree.a: kdtree.o
	ar rcs kdtree.a kdtree.o

kdtree.o: kdtree.cpp
	g++ -c kdtree.cpp -o kdtree.o

clean:
	rm -f *.o *.a test
