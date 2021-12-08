/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - main.cpp */

/*
Main file for Assignment6
*/

//these statements include the user defined files into this file to be used
#include "Simulation.h"
#include "DatabaseOperations.h"
#include "GenStack.h"
#include "bst.h"
// standard namespace library in C++
using namespace std;
/*
Function: main
Return: int (returns a 0 or -1 based on if the main method runs correctly)
Parameters: int (argc, number of command line arguments), char** (argv, array of char pointers which is pretty much an array of the command line arguments)
Exceptions: none
*/
int main(int argc, char** argv){
  cout << "start test" << endl;
  BST<int> *bst = new BST<int>();
  bst->insert(4);
  //bst->insert(2);
  //bst->insert(3);
  //bst->insert(6);
  /*
  Simulation *sim = new Simulation();

  sim->start();
  sim->simulate();

  delete sim;
  */
  cout << "end test" << endl;
  return 0;
}
