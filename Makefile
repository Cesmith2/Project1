all: connect4read example
connect4read: Connect4Game.cpp connect4Game.h
	g++ Connect4Game.cpp -g -o c4read
example: connect4exp.cpp
	g++ connect4exp.cpp -g -o connectFour
