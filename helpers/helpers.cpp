/*********************************************************************
** Program name: Langton's Ant
** Author: Haya Ahmed
** Date: October 10, 2018 (used 3 bonus days on this assignment)
** Description: Implememntation of helper functions, and source code of 
the helper functions.
*********************************************************************/


#include <iostream>
#include <cstdlib>
#include <string>

#include "helpers.hpp"
#include "Ant.hpp"

using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
 ** Description: mainMenu()
 ** This is a generic menu function that asks the user if they want to 
 play Langton's Ant. At the end of the game, it asks the user if they want 
 to play again.
 *********************************************************************/

void mainMenu()
{
    int chooseOption;
    cout << "Welcome to Langton's Ant!" << endl;
    cout << "Please enter an integer to choose an option below:" << endl;
    cout << "1. Start Langton's Ant simulation" << endl;
    cout << "2. Quit" << endl;
    cin >> chooseOption;

    while(cin.fail() || (chooseOption != 1 && chooseOption != 2))
    {
        cin.clear();
        cin.ignore();
        cout << "Error. Please enter a valid option." <<endl;
        cin >> chooseOption;
    }

    switch(chooseOption)
    {
        case 1:
        {
            cout << "Let's play!" << endl;
            startGame();
            mainMenu();
            break;
        }
        case 2: 
        {
            cout << "Okay then, bye!" << endl;
            break;
        }
    }
}



/*********************************************************************
 ** Description: startGame()
 ** This is the Lanton Ant simulation. First it asks the user for row size, 
 col size, ect. Then it creates the Langton the Ant and runs through the 
 simulation.
 *********************************************************************/

void startGame()
{
    //Ask user to input row and column size of board
  cout << "Choose the dimentions for your board (tip: 70x70 to 100x100 looks the best): " << endl;
  int rowBoard = getRowSize(); 
  int colBoard = getColSize();
  
  //Asks user for starting position of Ant
  cout << "Where do you want the Ant to start?" << endl;
  int xCoord;
  int yCoord; 
  getAntCoords(&xCoord, &yCoord, rowBoard, colBoard); 

  //Asks user for how many steps the Ant should take 
  cout << "How many steps do you want the Ant to take? (tip: Do over 10000 if you want to see the highway!)" << endl;
  int stepCounter = getSteps(); 

  //Create the board based on entered row size and column size
  int** boardPtr = createBoard(rowBoard, colBoard); 

  //Create Ant object named Langton
  //Initialise the board, and the Ant's starting location
  Ant Langton(boardPtr, rowBoard, colBoard, xCoord, yCoord); 
  
  //Print board with Ant's starting location
  cout << "Here is your Ant's starting position: " << endl;
  printBoard(boardPtr, rowBoard, colBoard);

  //Langton's Ant Simulation
  int i = 0; 
  while (i < stepCounter) 
  { 
    i++; 
    cout << "STEPS: " << i << std::endl;
    Langton.turnAnt(); //First the Ant turnes
    Langton.flipSquare(); //Flip the square the Ant was standing on
    Langton.moveForward(); //Ant moves forward
    if (Langton.isFacingWall()) //If the ant is facing a wall it should turn
      {
        Langton.turnAnt();
      }
    printBoard(boardPtr, rowBoard, colBoard); 

  }

  //delete dynamically allocated board
  deleteBoard(boardPtr, rowBoard, colBoard); 
}


/*********************************************************************
 ** Description: getRowSize()
 ** This function asks the user for a number to be used to set the row
 size of the matrix and validates that input using validateInput().
 *********************************************************************/

int getRowSize() 
{
    cout << "Row size: " << endl;
    std::string usrInput ;
    cin >> usrInput ;
    int rowSize = validateInput(usrInput);
    return rowSize;
}

/*********************************************************************
 ** Description: getColSize()
 ** This function asks the user for a number to be used to set the column
 size of the matrix and validates that input using validateInput().
 *********************************************************************/

int getColSize()
{
    cout << "Col size: " << endl;
    std::string usrInput ;
    cin >> usrInput ;
    int colSize = validateInput(usrInput);
    return colSize;
}

/*********************************************************************
 ** Description: getSteps()
 ** This function asks the user for the number of steps the ant will take.
 The number of steps is passed through the validateInput function to
 ensure that a positive valid integer was entered.
 *********************************************************************/

int getSteps() 
{
    cout << "Steps: " << endl;
    std::string usrInput ;
    cin >> usrInput ;
    int steps = validateInput(usrInput);
    return steps;
}



/*********************************************************************
 ** Description: validateInput()
 ** This function asks the user for an integer value from 0 tp 20000 and
 validates the input (making sure it is an integer. It repeatedly asks
 the user for valid input until the user enters valid input. It returns
 the validated input.
 *********************************************************************/


int validateInput(std::string usrInput)
{
    int userInput = atoi(usrInput.c_str());

        while (containChar(usrInput) || (!withinRange(userInput)))
        {
            cout << "Invalid input. Please enter a positive integer between." << endl;
            cin >> usrInput ;
            userInput = atoi(usrInput.c_str());
        }
        return userInput;   
}



/*********************************************************************
 ** Description: containChar()
 ** This boolean function takes a string as an an inout and iterated it to
 see if it has an alphabet character. Using this, validateInput() only accepts
 numeric values.
 *********************************************************************/

bool containChar(std::string usrInput)
{
    for (int i = 0; i < usrInput.length(); i++)
    {
        if(isalpha(usrInput[i]))
        {
            return true;
        }
    }
}



/*********************************************************************
 ** Description: containChar()
 ** This boolean function takes an integer and tests if it is within range,
 ensuring that the value passed through validateInput() is within range and
 a positive number.
 *********************************************************************/

bool withinRange(int userInput)
{

    if (userInput > 0 && userInput < 20000)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*********************************************************************
 ** Description: getStartCoords()
 ** This function asks the user to enter the starting coordinates of the
 Ant. It takes in two pointers representing starting coordinates of the ant
 as well as rowSize and colSize. The x coordinate is validated against the
 rowSize and the y coordinate is validated against the colSize
 *********************************************************************/

void getAntCoords(int *xPtr, int *yPtr, int rowSize, int colSize) 
{
    cout << "X coordinate: " << endl;
    cin >> *xPtr;
    while (cin.fail() || *xPtr < 1 || *xPtr > (rowSize-1))
    {
        cin.clear();
        cin.ignore();
        cout << "Error. Please put the Ant inside the board" << endl;
        cin >> *xPtr;
    }
    
    cout << "Y coordinate: " << endl;
    cin >> *yPtr;
    while (cin.fail() || *yPtr < 1 || *yPtr > (colSize-1))
    {
        cin.clear();
        cin.ignore();
        cout << "Error. Please put the Ant inside the board" << endl;
        cin >> *yPtr;
    }
    
}


/*********************************************************************
 ** Description: createBoard()
 ** This function creates and returns a 2D dynamic array of the dimentions
 specified by the parameter rowSize and colSize.
 *********************************************************************/

int** createBoard(int rowSize, int colSize) 
{
    int** board = new int*[rowSize];
    for (int i = 0; i < rowSize; i++)
    {
        board[i] = new int[colSize];
    }
    return board;
}



/*********************************************************************
 ** Description: printBoard()
 ** This function displays the board created by creatBoard(), with added
 borders. The switch statements with integer cases represent which character
 should be printed since this is an integer 2D array.
 *********************************************************************/

void printBoard(int** board, int rowBoard, int colBoard) 
{
    for (int i = 0; i < (rowBoard + 1); i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < rowBoard; i++)
    {
        cout << "|";
        for (int j = 0; j < colBoard; j++)
        {
            switch (int squareColor = board[i][j])
            {
                case 0: //represent white square
                    cout << " ";
                    break;
                case 1: //represent black square
                    cout << "#";
                    break;
                case 2:
                    cout << "*"; //represent Ant
                    break;
            }
        } cout << "|" << endl;
    }
    for (int i = 0; i < (colBoard + 1); i++)
    {
        cout << "_";
    }
}



/*********************************************************************
 ** Description: deleteBoard()
 ** This function deallocates the memory that was used in creating the
 2D dynamic board.
 *********************************************************************/

void deleteBoard(int** board, int rowBoard, int colCoard) 
{
    for (int i = 0; i < rowBoard; i++)
    {
        delete [] board[i]; // loop through the array and deallocate each array pointer
    }
    delete [] board;
}
