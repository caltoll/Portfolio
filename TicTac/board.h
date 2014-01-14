//board.h
//Header file for the board class
#include <iostream>
#include <string>

class board
{

public:
	board();
	

	bool checkVictory(); //Check if the board is in a victory state & set getVictor											
	void printBoard(); // Print the board with characters separated by | and _
	bool makeMove(char place, int move);
        void resetBoard();
        
	char getVictor(){return victor;}
        std::string getStatus(){return status;}

private: 
	bool testArray(char array[3]); //As part of checkVictory: Test if an array of 3 characters are all equal
	char victor; //Char which shows which made the winning move
        std::string status;
	char boardArray[3][3];
};