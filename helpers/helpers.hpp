/*********************************************************************
** Program name: Langton's Ant
** Author: Haya Ahmed
** Date: October 10, 2018 (used 3 bonus days on this assignment)
** Description: Protoypes of the helper functions.
*********************************************************************/

#ifndef HELPERS_HPP
#define HELPERS_HPP
#include <string>

  void mainMenu();
  void startGame();
  int getRowSize(); // used to get the size of the matrix/board from the user
  int getColSize();
  int getSteps(); // used to get the max number of moves from the user
  void getAntCoords(int* xCoord,int* yCoord, int rowSize, int colSize); // used to set the starting coordinates
  int** createBoard(int rowSize, int colSize); // creates a AxA matrix where A is matrixSize
  void printBoard(int** board, int rowSize, int colSize); // displays the current state of the board to the screen
  int validateInput(std::string userInput);
  bool containChar(std::string usrInput);
  bool withinRange(int userInput);
  void deleteBoard(int** board, int row, int col); // deallocates memory for a matrix created by createMatrix

#endif
