/* Charles Smith II
   CMSC 389
   Dr. Blaheta
   (c) Charles Smith II
*/

#include <iostream>
#include "connect4Game.h"
#include "ai.h"

using namespace std;

// Main
int main(int argc, char** argv)
{
	int type;
	cout << "Select a game type\n  (0) for 2 player\n  (1) for an AI player" << endl;
	cin >> type;
	if(type == 1)
		ai(argv[1]).turns();
	else if(type == 0)
   	connect4Game(argv[1]).turns();
	else
		return 1;
   return 0;   
}
