
vending: main.o dispenser.o register.o
	g++ main.o dispenser.o register.o -o vending

main.o: main.cpp
	g++ -c main.cpp

dispenser.o: dispenser.cpp dispenser.h
	g++ -c dispenser.cpp

register.o: register.cpp register.h
	g++ -c register.cpp