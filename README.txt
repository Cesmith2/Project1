Charles Smith II
CMSC 389
Dr. Blaheta

Compile:
	make

Run:
	./c4ai [filename]

Desription:
	Play connect play with a friend or with and AI player! If anything but a correc input is put into the  options for 2player or AI the program will exit.

Test cases:

#./c4ai C4board.in
-starting state-
. . . . . . .
. . . . . . .
. . . . . . . 
. . . . . . .
. . . . . . .
. . . . . . .
It's player 1's turn.

#./c4ai board1.in
-starting state1-
. . . . . . .
. . . . . . .
. X . . . . .
. X O . . . . 
. X O . . . .
. X O . . . .
Player 1 has won!

#./c4ai board2.in
-starting state2-
. . . . . . . 
. . . . . . .
. . . . . . .
. . O . . . .
. X O . . . . 
. X O . . . .
X X O . . . .
Player 2 has won!

#./c4ai board3.in
-starting state3-
. . . . . . .
. . . . . . .
. X . . X . .
. O O X O . .
. X X O X . .
. X O X O O .              
Player 1 has won!

References:
	Brandon Toney helped me the structure that the ai should have.
	http://pastebin.com/2quqQrwJ
	http://pastebin.com/45RV2hzk
	http://www.daniweb.com/software-development/cpp/threads/279409/cin-to-allow-numeric-only
