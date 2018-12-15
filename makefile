all: LangtonAnt

LangtonAnt: main.o Ant.o helpers.o
	g++ -std=c++11 main.o Ant.o helpers.o -o LangtonAnt

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -std=c++11 -c Ant.cpp

helpers.o: helpers.cpp helpers.hpp 
	g++ -std=c++11 -c helpers.cpp 

clean:
	rm *.o LangtonAnt