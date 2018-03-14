all: tracker.x

tracker.x: tracker.o vehicles.o shapes.o
	g++ -std=c++11 -o tracker.x tracker.o vehicles.o shapes.o

tracker.o: tracker.cpp vehicles.h
	g++ -std=c++11 -c tracker.cpp

vehicles.o: vehicles.cpp vehicles.h
	g++ -std=c++11 -c vehicles.cpp

shapes.o: shapes.cpp shapes.h
	g++ -std=c++11 -c shapes.cpp
