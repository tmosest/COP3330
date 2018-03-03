LIB     = /home/courses/cop3330p/LIB
CC      = g++ -std=c++11 -I. -I$(LIB)/cpp -Wall -Wextra

all:    fbitvect.x fprime.x prime_below.x

fprime.x: prime.o bitvect.o fprime.o
        $(CC) -o fprime.x prime.o bitvect.o fprime.o

fbitvect.x: bitvect.o fbitvect.o
        $(CC) -o fbitvect.x bitvect.o fbitvect.o

prime_below.x: prime_below.o prime.o bitvect.o
        $(CC) -o prime_below.x prime_below.o prime.o bitvect.o

bitvect.o: bitvect.cpp # bitvect.h
        $(CC) -c bitvect.cpp
