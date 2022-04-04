#Alan Benitez
run: main.o Calculations.o Customer.o Simulation.o
	g++ -Wall -o $@ $^
test.o: main.cpp
	g++ -Wall -c main.cpp
Calculations.o: Calculations.hpp Calculations.cpp
	g++ -Wall -c Calculations.cpp
Customer.o: Customer.hpp Customer.cpp
	g++ -Wall -c Customer.cpp
Simulation.o: Simulation.hpp Simulation.cpp
	g++ -Wall -c Simulation.cpp