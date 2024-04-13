
output: main.o func.o
	g++ main.o func.o -o output

main.o: main.cpp
	g++ -c main.cpp

func.o: func.cpp func.h
	g++ -c func.cpp

clean:
	rm *.o output