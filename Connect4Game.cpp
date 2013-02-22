/* Charles Smith II
   CMSC 389
   Dr. Blaheta
   (c) Charles Smith II
*/

#include <iostream>
#include "connect4Game.h"

using namespace std;

// Main
int main(int argc, char** argv)
{
   connect4Game(argv[1]).turns();
   return 0;   
}
