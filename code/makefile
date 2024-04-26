output: main.o func.o person.o
	g++ -O3 main.o func.o person.o -o output

main.o: main.cpp
	g++ -O3 -c main.cpp

func.o: func.cpp func.h
	g++ -O3 -c func.cpp

person.o: person.cpp person.h
	g++ -O3 -c person.cpp

clean:
	rm *.o output