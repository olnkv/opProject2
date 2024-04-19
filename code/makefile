
output: main.o func.o
	g++ -O3 main.o func.o -o output

main.o: main.cpp
	g++ -O3 -c main.cpp

func.o: func.cpp func.h
	g++ -O3 -c func.cpp

clean:
	rm *.o output
