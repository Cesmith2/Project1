/* Charles Smith II
	CMSC 389
	Dr. Blaheta
	(c) Charles Smith II
*/

#ifndef AI_H
#define AI_H

#include <cstdlib>

using namespace std;

class ai
{
	int player;
   int choice;
   int y;
   int x;
   char field[6][7];
   bool winner;

	public:

		/*struct boardView{
			char grid[6][7];
		};
		
		boardView guessChildren(int p, char grid[][7]) {
			//generates a list of possible moves..
			for(int i=0; i<7; ++i) {
				for(int j=5; j>=0; --j) {
					if(grid[j][i] == '.') {
						if(p==1)			
							grid[j][i] = 'X';
						else
							grid[j][i] = 'O';
						break;
					}
				}
			}
		}*/
		
		//AI generated moves
		void aiPlayer() {
		//randomly generates a choice
			srandom(time(NULL));
			choice = random()%7;

			/*bool isOwin=false;
			for(int i=0; i<7; ++i) {
				choice = i;
				for(int j=5; j>=0; --j) {
					if(field[j][choice] == '.') {
						field[j][choice] = 'O';
						checkIfWinner();
						if(winner) {
							isOwin=true;
							break;
						}
						else
							keepPlaying();
					}
				}
			}
			if(!isOwin){		
				for(int i=0; i<7; ++i) {
					choice = i;
					for(int j=5; j>=0; --j) {
						if(field[j][choice] == '.') {
							field[j][choice] = 'X';
							checkIfWinner();
							if(winner) {
								field[j][choice] = 'O';
								break;
							}
							else
								keepPlaying();
						}
					}
				}
			}*/
		}

		//class constructor
		ai(const char* inFile) {
         y = 6;
         x = 7;

         //set # of players (2)
         player = 1;
         //there is no winner yet so...
         winner = false;
   
         //read in and draw the field
         ifstream fin;
         fin.open(inFile);
         for(int i=0; i<y; ++i) {
            for(int j=0; j<x; ++j) {
               fin >> field[i][j];
            }   
         }   
             
         fin.close();
      }   
          
      //print the field to the screen/
      void printField() {
         y = 6;
         x = 7;

         clear();
         cout << "1 v AI\n0 1 2 3 4 5 6" << endl;
         for(int i=0; i<y; ++i) {
            for(int j=0; j<x;++j) {
            cout <<  field[i][j] << " ";
            }   
            cout << endl;
         }   
      }   

      //clears the screen/
      void clear() {
         for(int i=0; i<80; ++i) {
            cout << endl;
         }   
      }   
	
		//Da(Rulez/
		void keepPlaying() {
			int fullSpace = 0;
			cout << "It's player " << player << "'s turn." << endl;
			if(player == 1) {
				cin >> choice;
				if(cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Correct input is a #: 0-6" << endl;
					keepPlaying();
				}
			}
			else
				aiPlayer();

			//if the player's choice it 0>x>7 set choice equal to the bounds (7 or 0)
			while(choice >= 7 || choice < 0) {
				cout << "Column does not exist, try again" << endl;
				keepPlaying();
			}   
			//if the bottom most row is full place the players token in the row above
			for(int i=5; i>=0; --i) {
				if(field[i][choice] == '.') {
					//if player 1 put a "O"
					if(player == 1) {
						field[i][choice] = 'X';
						break;
					}   
					//if player 2 put a "X"
					else if(player == 2) {
						field[i][choice] = 'O';
						break;
					}   
				}   
				else
					//increase the # of spaces filled
					fullSpace += 1;
			}   

			//if the column is full let the player know
			if(fullSpace == 6) {
				cout << "Row " << choice << " is full!" << endl;
				keepPlaying();
			}   

			//change players
			if(player == 1) {
				player = 2;
			}
			else
				player = 1;

			//start the next players turn
			turns();
		}   

		//check for a winning state/
		void checkIfWinner() {
			int start = 0;
			int count = 0;			

			//win vertically
			for(int i=0; i<7; ++i) {
				for(start; start<=2; ++start) {
					if(field[start][i] != '.' &&
						(field[start][i] == field[start+1][i] &&
						field[start+1][i] == field[start+2][i] &&
						field[start+2][i] == field[start+3][i])) {
						winner = true;
						player = field[start][i];
						break;
					}
				}
				start = 0;
			}

			// win horizontally
			for(int i=0; i<6; ++i) {
				for(start; start<=3; ++start) {
					if(field[i][start] != '.' &&
						(field[i][start] == field[i][start+1] &&
						field[i][start+1] == field[i][start+2] &&
						field[i][start+2] == field[i][start+3])) {
						winner = true;
						player = field[i][start];
						break;
					}
				}
				start = 0;
			}

			//win diagonally (lower-left to upper-right)
			for(int i = 3; i < 6; ++i) {
          	for(start; start <= 3; ++start) {
            	if(field[i][start] != '.' &&
						(field[i][start] == field[i-1][start+1] &&
					 	field[i-1][start+1] == field[i-2][start+2] &&
						field[i-2][start+2] == field[i-3][start+3])) {
                  winner = true;
                  player = field[i][start];
                  break;
					}
           	}
				start = 0;
        	}

			//win diagonally (upper-left t0 lower-right)
			for(int i=0; i<3; ++i) {
				for(start; start <= 4; ++start) {
					if(field[i][start] != '.' &&
						(field[i][start] == field[i+1][start+1] &&
					 	field[i+1][start+1] == field[i+2][start+2] &&
						field[i+2][start+2] == field[i+3][start+3])) {
                  winner = true;
                  player = field[i][start];
                  break;
					}
				}
				start = 0;
			}	

			//draw
			/*for(int i=0; i<6; ++i) {
				for(int j=0; j<7; ++j) {
					if(field[i][j] != ".") {
						++count;
					}
				}
			}
			if(count == 42) {
				cout << "The game is a draw!" << endl;
				
			}*/
		}

		//what happens on each turn/
		void turns() {
			//check if a player has won
			checkIfWinner();
			//if a player has won, 
			//clear the screen, print the winning instance, and let them know
			if(winner == true) {
				printField();
				player = (player%2)+1;
				cout << "Player " << player << " has won!" << endl;
			}
			//if niether player has won,
			//print the board and continue the game.
			else {
				printField();
				keepPlaying();
			}
		}
};

#endif
