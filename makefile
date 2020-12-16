main: src/main.o src/calculate_SD.o
	g++ -std=c++11 src/main.o src/calculate_SD.o -o main

main.o: src/main.cpp src/calculate_SD.cpp
	g++ -c src/main.cpp src/calculate_SD.cpp

clean:
	rm src/*.o main
