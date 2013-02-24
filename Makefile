all: connect4read ai example
connect4read: Connect4Game.cpp connect4Game.h
	g++ Connect4Game.cpp -g -o c4read
ai: Connect4Game.cpp ai.h
	g++ Connect4Game.cpp -g -o c4ai
example: connect4exp.cpp
	g++ connect4exp.cpp -g -o connectFour
