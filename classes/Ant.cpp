/*********************************************************************
** Program name: Langton's Ant
** Author: Haya Ahmed
** Date: October 10, 2018 (used 3 bonus days on this assignment)
** Description: Implementation of Ant class, and the source code for 
the Ant class functions.  
*********************************************************************/

#include <iostream>
#include "Ant.hpp"
#include "helpers.hpp"

using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
** Description: Ant()
** Default contructor, with default values.
*********************************************************************/

Ant::Ant() 
{
  board = createBoard(10, 10); //create a 10x10 board
  xCoord = 5;
  yCoord = 5;
  direction = 0; //North
  squareColor = board[xCoord][yCoord];
  board[xCoord][yCoord] = 2;
}


/*********************************************************************
** Description: Ant()
** This is the constructor, initialising all board, rowsize, colSize, 
and starting coordinated of the Ant by the parameters that are passed 
through it. It also initialises the direction as north and the sets the 
squareColor as the Ant's starting location.
*********************************************************************/

Ant::Ant(int** boardPtr, int boardRow, int boardCol, int antX, int antY) 
{
  board = boardPtr;
  rowSize = boardRow;
  colSize = boardCol;
  xCoord = antX;
  yCoord = antY;
  direction = 0; //North
  squareColor = board[xCoord][yCoord];
  board[xCoord][yCoord] = 2; //Ant is '*'
}


/*********************************************************************
** Description: flipSqaure()
** This function flips the square.   
*********************************************************************/

void Ant::flipSquare() 
{
  board[xCoord][yCoord] = !squareColor;
}


/*********************************************************************
** Description: turnAnt()
** This function turns the Ant by taking in the squareColor as the argument.
If it's the same squareColor it moves up the same direction, clockwise, (ie, north to 
east) and if it's a different square color it moves in the opposite direction 
(ie, counterclockwise).   
*********************************************************************/

void Ant::turnAnt() 
{
  if (squareColor) 
 {
    direction++;

    if (direction > 3) //set clockwise
    	{
    		direction = 0;
    	}
    }
  else 
  {
    direction--; //set counterclockwise

    if (direction < 0)
    { 
    	direction = 3;
    }
 }
}


/*********************************************************************
** Description: isFacingWall()
** This function used a switch statement to make the Ant move forward, 
taking in the Ant's direction as the condition.   
*********************************************************************/

void Ant::moveForward() 
{
  switch (direction) 
  {
    case 0: // north
        xCoord--;
      	break;
    case 1: //east
        yCoord++;
      	break;
    case 2: //south
        xCoord++;
        break;
    case 3: //west
        yCoord--;
        break;
      }
  squareColor = board[xCoord][yCoord]; //setting the new square
  board[xCoord][yCoord] = 2; //Ant is always '*'
}


/*********************************************************************
** Description: isFacingWall()
** Boolean function, returns true if the Ant is both against a wall and it
is in the direction of the wall. Edges are defined as 0 for the 0th row 
and 0th column, and rowSize-1 and colSize-1 outer edges. 
*********************************************************************/

bool Ant::isFacingWall()
{
	int maxRow = rowSize - 1;
	int maxCol = colSize - 1;

	//checking the row edge cases
	if ((xCoord == 1 && direction == 0) || (xCoord == maxRow && direction == 1))
	{
		return true;
	} //checking the column edge cases
	else if ((yCoord == 1 && direction == 3) || (yCoord == maxCol && direction == 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
