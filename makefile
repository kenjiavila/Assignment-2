all: main_memory

main_memory: main
	./main

main: main.o
	g++ main.o -o main

main.o:  main.cpp
	g++ -c main.cpp
