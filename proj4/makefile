CC      = g++ -std=c++11 -I. -Wall -Wextra

all:    stester.x vtester.x

stester.x: stester.o shapes.o
	$(CC) -o stester.x stester.o shapes.o

vtester.x: vtester.o vehicles.o shapes.o
	$(CC) -o vtester.x vtester.o vehicles.o shapes.o

stester.o: stester.cpp
	$(CC) -c stester.cpp

vtester.o: vtester.cpp vehicles.h
	$(CC) -c vtester.cpp vehicles.cpp

vehicles.o: vehicles.cpp vehicles.h shapes.h
	$(CC) -c vehicles.cpp shapes.cpp

shapes.o: shapes.cpp shapes.h
	$(CC) -c shapes.cpp

