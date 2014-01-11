//ticTac.cpp
//game of tic tac toe from command line 
//Restructrued to be class based

#include <iostream>

using namespace std;

//Really I need to strip everything out
//I can hack a class-based implementation together but really I should 
//Take everything out 
//Split into 2 files: For game and for board. Lets me use 

//NEED
//Board class

//Game class? 

class board
{

public:
	board();
	~board(){};

	bool checkVictory(); //Check if the board is in a victory state & set getVictor											
	void printBoard(); // Print the board with characters separated by | and _
	bool makeMove(char place);
	char getVictor(){return *victor;}
	void resetBoard();

private: 
	bool testArray(char array[3]); //As part of checkVictory: Test if an array of 3 characters are all equal
	char * victor; //Char which shows which made the winning move, set via pointer through checkVictory
	char boardArray[3][3];
};


board::board()
{
	cout << "Board constructor call\n Initialising array with values: ";

	for (int i = 0; i<10; i++)  
		{
			int row = i/3;
			int collumn = i%3;
			int val = i+1;
			char cVal = '0' + val;
			cout << cVal << " ";
			boardArray[row][collumn] = cVal;
		}
	cout << "\nConstructor complete\n";
}


//=================================CHECKVICTORY=================================
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
			cout<<"\tRow Complete"<<endl;
			return true; 
		}

		if(board::testArray(testC))
		{	
			cout<<"\tColumn Complete"<<endl;
			return true;
		}

		if(board::testArray(testD1))
		{
			cout << "\tDiagonal Complete" << endl;
			return true;
		}

		if(board::testArray(testD2))
		{
			cout << "\tDiagonal Complete" << endl;
			return true;
		}
	
	}

	
	return false;
}

bool board::testArray(char array[3])
{
	if(array[0]==array[1] && array[1]==array[2])
		return true;

	return false;
}

bool board::makeMove(char piece)//Needs to change to take int, move logic to game methods
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
	
	move--; //Array measured from 0
	r = move/3;
	c = move%3;
	if((boardArray[r][c] == 'X')||(boardArray[r][c] == 'O'))
	{
		cout << "\nThat space is already taken, enter another: ";
		return false;
	}
	
		//Int/3 always rounds down, 
	boardArray[r][c] = piece;
	printBoard();
	return true;
}

//==============Print Board Function====================
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





//Eventually move this to a separate file

void turn()
{

}

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
		board gameBoard = board();
		cout << "Back to main" << endl;
		
		char cont = '\0'; //Char will be set to y or n
		char victory = '\0'; //Char will be set to X or O
	
		int move;
		int turn = 0;

		gameBoard.printBoard();
		
		
		
		while(true)
		{

			//Nought's Turn
			turn++;
			cout << "\n\tNought: ";
			while(!gameBoard.makeMove( 'O'))
			{}

			if(gameBoard.checkVictory())
			{
				victory = 'O';
				break;
			}

			if(turn==9) //Awkward, but this loop has to stop after 9 turns
				break;

			//Cross' Turn
			turn++;
			cout << "\n\tCross: ";
			while(!gameBoard.makeMove('X'))
			{}

			if(gameBoard.checkVictory())
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


