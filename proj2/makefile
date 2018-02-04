#
# makefile distributed for cstringsort project
#

all: producttest1.x producttest2.x

producttest1.x:  producttest1.o product.o
	g++ -std=c++11 -Wall -Wextra -o producttest1.x producttest1.o product.o

producttest2.x: producttest2.o product.o
	g++ -std=c++11 -Wall -Wextra -o producttest2.x producttest2.o product.o

producttest1.o: producttest1.cpp product.h
	g++ -std=c++11 -Wall -Wextra -c -I. producttest1.cpp

producttest2.o: producttest2.cpp product.h
	g++ -std=c++11 -Wall -Wextra -c -I. producttest2.cpp

product.o: product.h product.cpp
	g++ -std=c++11 -Wall -Wextra -c -I. product.cpp
