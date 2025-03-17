build:
	g++ -Wall -std=c++17 src/*.cpp -lSDL2 -llua5.3 -o GameEngine;

run:
	./GameEngine 

clean:
	rm GameEngine