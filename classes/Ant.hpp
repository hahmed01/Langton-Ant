/*********************************************************************
** Program name: Langton's Ant
** Author: Haya Ahmed
** Date: October 10, 2018 (used 3 bonus days on this assignment)
** Description: Specification of Ant class, protoypes of the Ant member 
functions.
*********************************************************************/
#include <iostream>

#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
  private:
    int** board; 
    int rowSize;
    int colSize; 
    int xCoord; 
    int yCoord; 
    int direction; //0 is north, 1 is east, 2 is south, 3 is west 
    int squareColor; //0 is white, 1 is black, 2 is Ant

  public:
    Ant();
    Ant(int** boardPtr, int boardRow, int boardCol, int antX, int antY); //initialises board
    void turnAnt(); //turn Ant's direction
    void flipSquare(); //flip square
    void moveForward(); //Moves ant forward
    bool isFacingWall(); //If Ant is facing wall, returns true
};
#endif