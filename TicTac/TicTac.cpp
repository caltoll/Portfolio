//ticTac.cpp
//game of tic tac toe from command line 
//Goal: Separate game implementation and board implementation. No board method should
//print to the command line.



#include <iostream>
#include <string>
#include "board.h"

using namespace std;

class game
{
public:
	game();
	

	void playerTurn(char player);
	void gameTurn();
	void resetGame();
	int playerInput();

	bool isOver(){return gameOver;}
	char getVictor(){return victor;}
        string getStatus();

private:
	int turnNumber;
	bool gameOver;
	char victor;
	board gameBoard;
        
};

game::game()
{
	turnNumber = 0;
	gameOver = false;
	victor = '\0';
	

}

void game::resetGame()
{
	turnNumber = 0;
	gameOver = false;
	victor = '\0';
	gameBoard.resetBoard();
	gameBoard.printBoard();
}



void game::gameTurn()
{
	if (!gameOver)
		playerTurn('O');

	if ( turnNumber == 9) 
	{
		gameOver = true;
		return;
	}

	if (!gameOver)
		playerTurn('X');
}

string game::getStatus()
{
    string temp = gameBoard.getStatus();
    return temp;
}

void game::playerTurn(char player)
{
	turnNumber++;

	if(player == 'O')
		cout << "Nought: ";
	else if (player == 'X')
		cout << "Cross: ";
	int move = playerInput();

	while (!gameBoard.makeMove(player, move))
	{cout << "Invalid move, make another";}

	if (gameBoard.checkVictory())
		{
			gameOver = true;
			victor = gameBoard.getVictor();
		}

	gameBoard.printBoard();

}

int game::playerInput()
{
	int move;
	while(!(cin >> move) || move > 8) //Check that its a valid integer
	{
		cout << "\nEnter a valid square to move to: ";
	
		cin.clear();
		cin.ignore();
	}

	return move;
}

//=================================MAIN=================================
int main()
{
	cout 	<<"\n\n\t==================================== \n"
			<<"\t Noughts and Crosses \n" 
			<<" \t====================================\n"
			<<"\n\n\t *For two players \n\n\t *Enter the number shown on the square you want"
			<<"\n\n\t *Continue taking turns until one or the other completes\n\t  a row, a column or a diagonal"
			<<"\n\n\n\t\t--Press enter to start a game--"
			<< endl;

	cin.ignore();

	game thisGame = game();

	while(true)
	{	
		
		thisGame.resetGame();

		while(!thisGame.isOver()) //two segments : GAME and TURN
		{
			thisGame.gameTurn();
		}
		
		
		char cont = '\0';


		cout << "\n\t" << thisGame.getStatus() << "\n\n\t *****Game Over*****"<<endl;

		if(thisGame.getVictor() =='O')
		{
			cout << "\n\t Nought is the winner!"<<endl;
		}

		else if(thisGame.getVictor() =='X')
		{
			cout << "\n\t Cross is the winner! "<<endl;
		}

		else 
		{
			cout << "Tie game!";
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


