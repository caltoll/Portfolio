//board.cpp
//Board class implementation
#include <iostream>
#include <string>
#include "board.h"
using std::cout;
using std::endl;



//=================================Constructors=================================
//
//==============================================================================



board::board()
{
	victor = '\0';
	cout << "Board constructor call";//Debug

	for (int i = 0; i<10; i++)  
		{
			int row = i/3;
			int collumn = i%3;

			char cVal = '0' + i;
			
			boardArray[row][collumn] = cVal;
		}
	cout << "\nConstructor complete\n";//Debug
}


//=================================CHECKVICTORY=================================
//			Loop over all rows, collumns and diagonals determine if a
//			victory state has been reached. Set char victory to the 
//			winning character (X or O)
//==============================================================================


bool board::checkVictory()
{
	char testR[3];//TestRow
	char testC[3];//TestCollumn
	char testD1[3];
	char testD2[3];
	//loop rows
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			testR[j] = boardArray[i][j];
			testC[j] = boardArray[j][i];

		

		}

		testD1[i] = boardArray[i][i];
		testD2[i] = boardArray[i][2-i];

		if(board::testArray(testR))
		{
			status = "Row Complete";
			return true; 
		}

		if(board::testArray(testC))
		{	
			status = "Column Complete";
			return true;
		}

		if(board::testArray(testD1))
		{
			status = "Diagonal Complete";
			return true;
		}

		if(board::testArray(testD2))
		{
			status = "Diagonal Complete";
			return true;
		}
	
	}

	
	return false;
}



//=================================TESTARRAY=================================
//			Test char array[3] to see if all elements are equal
//===========================================================================



bool board::testArray(char array[3])
{

	if(array[0]==array[1] && array[1]==array[2])
	{	
		victor = array[0];
		return true;
		
	}
	return false;
}

//=================================MAKEMOVE=================================
//			Take character and place it on board
//			at integer position
//==========================================================================

bool board::makeMove(char piece, int move)//Needs to change to take int, move logic to game methods
{
    if (move>8)
        return false;

    int r,c;

    r = move/3;
    c = move%3;
    if((boardArray[r][c] == 'X')||(boardArray[r][c] == 'O'))
    {
            return false;
    }

            //Int/3 always rounds down, 
    boardArray[r][c] = piece;

    return true;
}

//=================================RESETBOARD=================================
//			Resets the game without destroying everything and starting over
//============================================================================
void board::resetBoard()
{
	victor = '\0';
	//cout << "Board constructor call\n Initialising array with values: ";//Debug

	for (int i = 0; i<10; i++)  
	{
		int row = i/3;
		int collumn = i%3;
		char cVal = '0' + i;
	
		boardArray[row][collumn] = cVal;
	}
}
//=================================PRINTBOARD=================================
//			Prints out boardArray to the command line
//============================================================================
void board::printBoard()
{
	cout << "\n\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "\t\t";
		for (int j = 0; j < 5; j++)
		{
			//EVEN rows & colums print i/2,j/2
			if ( (i % 2 == 0) && (j % 2 == 0))
				cout << boardArray[i/2][j/2];

			//EVEN row & ODD colum print |
			else if ((i % 2 == 0) && !(j % 2 == 0))
				cout << " | ";

			//ODD row & EVEN colum print _
			else if (!(i % 2 == 0) && (j % 2 == 0))
				cout << "__";

			//ODD row & ODD colum print |_
			else
				cout << "|_";
		}

		cout <<" \n";
	}
}
