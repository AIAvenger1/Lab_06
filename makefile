all: lab

lab: main.o flag.o exercise.o
	g++ -std=c++20 main.o flag.o exercise.o -o lab
	rm *.o

exercise.o: exercise.cpp
	g++ -std=c++20 -c exercise.cpp
	
flag.o: flag.cpp
	g++ -std=c++20 -c flag.cpp

main.o: main.cpp
	g++ -std=c++20 -c main.cpp
