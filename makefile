start:
	g++ -o main.o -c main.cpp
	g++ -o find_two_num main.o
clean:
	rm -rf find_two_num main.o
