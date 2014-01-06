//ticTac.cpp
//game of tic tac toe from command line

#include <iostream>

using namespace std;

bool checkVictory(char board[3][3]); //Check if the board is in a victory state 											
bool testArray(char array[3]); //As part of checkVictory: Test if an array of 3 characters are all equal
void printBoard(char board[3][3]); // Print the board with characters separated by | and _
bool makeMove(char board[3][3], char place);

//=================================MAIN=================================
int main()
{
	cout 	<<"\n\n\t==================================== \n"
			<<"\t Noughts and Crosses (1986 version) \n" 
			<<" \t====================================\n"
			<<"\n\n\t *For two players \n\n\t *Enter the number shown on the square you want"
			<<"\n\n\t *Continue taking turns until one or the other completes\n\t  a row, a column or a diagonal"
			<<"\n\n\n\t\t--Press enter to start a game--"
			<< endl;

			cin.ignore();
	while(true)
	{	
		char boardArray[3][3] = {'1','2','3','4','5','6','7','8','9'};
		
		char cont = '\0'; //Char will be set to y or n
		char victory = '\0'; //Char will be set to X or O
	
		int move;
		int turn = 0;

		printBoard(boardArray);
		
		
		
		while(true)
		{

			//Nought's Turn
			turn++;
			cout << "\n\tNought: ";
			while(!makeMove(boardArray, 'O'))
			{}

			if(checkVictory(boardArray))
			{
				victory = 'O';
				break;
			}

			if(turn==9) //Awkward, but this loop has to stop after 9 turns
				break;

			//Cross' Turn
			turn++;
			cout << "\n\tCross: ";
			while(!makeMove(boardArray, 'X'))
			{}

			if(checkVictory(boardArray))
			{
				victory = 'X';
				break;
			}
		}
		
		cout << "\n\t *****Game Over*****"<<endl;
		if(victory=='O')
		{
			cout << "\n\t Nought is the winner!"<<endl;
		}

		if(victory=='X')
		{
			cout << "\n\t Cross is the winner! "<<endl;
		}

		cout << "\n\tWould you like another game?" << endl;
		
		while(cont != 'y' && cont != 'n')
		{
			cout << "\t(y/n): ";
			cin >> cont;
		}

		if (cont == 'n')
			break;
		
	} 

	cout << "\tGoodbye" << endl;
	return 0;

	
}


//=================================CHECKVICTORY=================================
bool checkVictory(char board[3][3])
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
			testR[j] = board[i][j];
			testC[j] = board[j][i];

		

		}

		testD1[i] = board[i][i];
		testD2[i] = board[i][2-i];

		if(testArray(testR))
		{
			cout<<"\tRow Complete"<<endl;
			return true; 
		}

		if(testArray(testC))
		{	
			cout<<"\tColumn Complete"<<endl;
			return true;
		}

		if(testArray(testD1))
		{
			cout << "\tDiagonal Complete" << endl;
			return true;
		}

		if(testArray(testD2))
		{
			cout << "\tDiagonal Complete" << endl;
			return true;
		}
	
	}

	
	return false;
}

bool testArray(char array[3])
{
	if(array[0]==array[1] && array[1]==array[2])
		return true;

	return false;
}

bool makeMove(char board[3][3], char piece)
{
	int r,c;
	int move;
	if (!(cin >> move) || move > 9) //Check that its a valid integer
	{
		cout << "\nEnter a valid square to move to: ";
	
		cin.clear();
		cin.ignore();
		return false;

	}
	 //Add error checking here!
	//ensure move is int
	//ensure array location has not already been taken
	move--; //Array measured from 0
	r = move/3;
	c = move%3;
	if((board[r][c] == 'X')||(board[r][c] == 'O'))
	{
		cout << "\nThat space is already taken, enter another: ";
		return false;
	}
	
		//Int/3 always rounds down, 
	board[r][c] = piece;
	printBoard(board);
	return true;
}

//==============Print Board Function====================
void printBoard(char board[3][3])
{
	cout << "\n\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "\t\t";
		for (int j = 0; j < 5; j++)
		{
			//EVEN rows & colums print i/2,j/2
			if ( (i % 2 == 0) && (j % 2 == 0))
				cout << board[i/2][j/2];

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

