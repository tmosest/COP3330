# 
# makefile distributed for cstringsort project
#

all:      ssort.x diffcalc.x # test.x

ssort.x:  main.o cstringsort.o cstringdiff.o
	g++ -std=c++11 -Wall -Wextra -o ssort.x main.o cstringsort.o cstringdiff.o

diffcalc.x:  diffcalc.o cstringdiff.o
	g++ -std=c++11 -Wall -Wextra -o diffcalc.x diffcalc.o cstringdiff.o

test.x:   main_i.o cstringsort.o cstringdiff.o
	g++ -std=c++11 -Wall -Wextra -o test.x main_i.o cstringsort.o cstringdiff.o

main_i.o: /home/courses/cop3330p/LIB/area51/main_i.o
	cp   /home/courses/cop3330p/LIB/area51/main_i.o main_i.o

main.o:   main.cpp cstringsort.h cstringdiff.h
	g++ -std=c++11 -Wall -Wextra -c -I. main.cpp

diffcalc.o:   diffcalc.cpp cstringdiff.h
	g++ -std=c++11 -Wall -Wextra -c -I. diffcalc.cpp

cstringdiff.o:   cstringdiff.h cstringdiff.cpp
	g++ -std=c++11 -Wall -Wextra -c -I. cstringdiff.cpp

cstringsort.o:   cstringdiff.h cstringsort.h cstringsort.cpp
	g++ -std=c++11 -Wall -Wextra -c -I. cstringsort.cpp

