/* simple Connect-Four game using a 2-dimensional array - [row][column]
 The player wins by connecting four of their spots in one of four directions
        - Horizontal
        | Veritcal
        / Diagonal
        \ Diagonal
 
 To be added: AI as an OPTION for player 2
 
 Date:   2-5-2012
 Author: Zach Daily
 */
 
#include <iostream>
using namespace std;
 
 
//The workings of Connect Four
class connectFour{
        int player;
        int score[2];
        int board[6][7];  //6 = Rows, 7 = Columns
        int move;
        bool win;
       
public:
        //Set the player number to one and the scores to zero
        connectFour(){
                player = 1;
                score[0] = 0;
                score[1] = 0;
                win = false;
               
                //Initialize board array
                for (int i = 0; i < 6; i++){
                        for (int x = 0; x < 7; x++){
                                board[i][x] = 0;
                        }
                }
        }
       
        //Setup the turn by first checking for a win
        //If there is no win, continue by displaying the board
        //and getting the player's move
        void startTurn(){
                checkWin();
                if (win == true){
                        clearScreen();
                        display();
                        cout<< "Player #" << player << " has won!" <<endl <<endl;
                }
                else{
                        display();
                        gatherMove();
                }
        }
       
        //Display the board
        void display(){
                clearScreen();
                cout<< " 1  2  3  4  5  6  7 " <<endl;
                for (int i = 0; i < 6; i++){
                        for (int x = 0; x < 7; x++){
                                cout<< "[" << board[i][x] << "]";
                        }
                        cout<< endl;
                }
        }
       
        //Gather the player's move
        void gatherMove(){
                int emptySpots = 0;
                cout<< endl << "Player #" << player << ": Move to which space? ";
                cin>> move;
               
                //If the player enters anything above 7, set it to 7
                if (move > 7){move = 7;}
                //If the player enters anything below 0, set it to 0
                if (move < 0){move = 0;}
               
                //Determine where the player's piece falls
                //If something occupies the lowest point already, put it above
                for (int i = 5; i >= 0; i--){
                        if (board[i][move - 1] == 0){
                                board[i][move - 1] = player;
                                break;
                        }
                        else{
                                emptySpots += 1;
                        }
                }
               
                //If there are no more rows in a column, tell the player to try again
                if (emptySpots == 6){
                        cout<< endl << "There are no empty spots on #" << move << "! Try again!";
                        gatherMove();
                }
               
                //Set the next player to move
                if (player == 1){player = 2;}
                else {player = 1;}
               
                //Call start of next turn
                startTurn();
        }
       
        //Check for any winning combinations
        void checkWin(){
                int start = 0;
               
                //Horizontal Win
                for (int i = 0; i < 6; i ++){
                        for (start = 0; start <= 3; start++){
                                if ((board[i][start] == board[i][start+1] && board[i][start+1] == board[i][start+2] && board[i][start+2] == board[i][start+3]) && (board[i][start] != 0)){
                                        win = true;
                                        player = board[i][start];
                                        break;
                                }
                        }
                }
               
                //Vertical Win
                for (int i = 0; i < 7; i ++){
                        for (start = 0; start <= 2; start++){
                                if ((board[start][i] == board[start+1][i] && board[start+1][i] == board[start+2][i] && board[start+2][i] == board[start+3][i]) && (board[start][i] != 0)){
                                        win = true;
                                        player = board[start][i];
                                        break;
                                }
                        }
                }
               
                //Diagonal Win - "/"
                for (int i = 3; i < 6; i ++){
                        for (start = 0; start <= 3; start++){
                                if ((board[i][start] == board[i-1][start+1] && board[i-1][start+1] == board[i-2][start+2] && board[i-2][start+2] == board[i-3][start+3]) && (board[i][start] != 0)){
                                        win = true;
                                        player = board[i][start];
                                        break;
                                }
                        }
                }
               
                //Diagonal Win - "\"
                for (int i = 0; i < 3; i ++){
                        for (start = 0; start <= 4; start++){
                                if ((board[i][start] == board[i+1][start+1] && board[i+1][start+1] == board[i+2][start+2] && board[i+2][start+2] == board[i+3][start+3]) && (board[i][start] != 0)){
                                        win = true;
                                        player = board[i][start];
                                        break;
                                }
                        }
                }
        }
       
        //Clear the screen
        //Set for OSX currently - Change the inner system call for Windows or Linux
        void clearScreen(){
            for(int i=0; i<100; ++i) { 
               //system("clear"); 
               cout << "" << endl;
            }
        }
       
};
 
//Main function - Nice and small just like I like it!
int main (int argc, char * const argv[]) {
    connectFour play;
        play.startTurn();
       
    return 0;
}
