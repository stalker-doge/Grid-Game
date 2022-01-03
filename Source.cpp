#include <iostream>
#include "Header.h"
#include "Colour.h"
using namespace std;

Player p1;
Goal g1;
string gameBoard[NUMBER_OF_ROWS][NUMBER_OF_COLLUMNS];
string hiddenBoard[NUMBER_OF_ROWS][NUMBER_OF_COLLUMNS];
void PlayerMove(int x, int y);
void CreateGrid();
void DisplayGrid();
void main()
{
	CreateGrid();

	int playerChoice = 0;
	int playAgain = 1;
	
	do
	{
		do
		{
			cout << dye::green("\nGame board: \n");
			DisplayGrid();
			cout << "\n\n";
			cout << "\nMenu:";
			cout << "\n1. Move Player North";
			cout << "\n2. Move Player South";
			cout << "\n3. Move Player East";
			cout << "\n4. Move Player West";
			cout << "\n5.Exit game\n";
			cout << "Current HP: " << p1.getPlayerHP() << "\n";
			cin >> playerChoice;
			std::system("CLS");
			switch (playerChoice)
			{
			case 1:
				PlayerMove(-1, 0);
				break;
			case 2:
				PlayerMove(1, 0);
				break;
			case 3:
				PlayerMove(0, 1);
				break;
			case 4:
				PlayerMove(0, -1);
				break;
			case 5:
				break;
			case 9:
				CreateGrid();
				break;
			default:
				cout << "\nInput not recognized, please try again\n";
			}
			if (gameBoard[p1.getPlayerRow() + 1][p1.getPlayerCollumn()] == "2" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerRow() + 1 < 20)
			{
				cout << dye::light_red("\nWARNING: YOU ARE 1 MOVE AWAY FROM AN ENEMY");
				hiddenBoard[p1.getPlayerRow() + 1][p1.getPlayerCollumn()] = "2";
			}
			if (gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + 1] == "2" && p1.getPlayerCollumn() + 1 > -1 && p1.getPlayerCollumn() + 1 < 20)
			{
				cout << dye::light_red("\nWARNING: YOU ARE 1 MOVE AWAY FROM AN ENEMY");
				hiddenBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + 1] = "2";
			}
			if (gameBoard[p1.getPlayerRow() - 1][p1.getPlayerCollumn()] == "2" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerRow() + 1 < 20)
			{
				cout << dye::light_red("\nWARNING: YOU ARE 1 MOVE AWAY FROM AN ENEMY");
				hiddenBoard[p1.getPlayerRow() - 1][p1.getPlayerCollumn()] = "2";
			}
			if (gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + -1] == "2" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerCollumn() + 1 < 20)
			{
				cout << dye::light_red("\nWARNING: YOU ARE 1 MOVE AWAY FROM AN ENEMY");
				hiddenBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + -1] = "2";
			}
			//Above finds if player is near enemy
			if (gameBoard[p1.getPlayerRow() + 1][p1.getPlayerCollumn()] == "G" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerRow() + 1 < 20)
			{
				hiddenBoard[p1.getPlayerRow() + 1][p1.getPlayerCollumn()] = "G";
			}
			if (gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + 1] == "G" && p1.getPlayerCollumn() + 1 > -1 && p1.getPlayerCollumn() + 1 < 20)
			{
				hiddenBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + 1] = "G";
			}
			if (gameBoard[p1.getPlayerRow() - 1][p1.getPlayerCollumn()] == "G" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerRow() + 1 < 20)
			{
				hiddenBoard[p1.getPlayerRow() - 1][p1.getPlayerCollumn()] = "G";
			}
			if (gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + -1] == "G" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerCollumn() + 1 < 20)
			{
				hiddenBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + -1] = "G";
			}
			//Finds if player is next to the goal
			if (p1.getPlayerGoal() == true || p1.getPlayerHP() < 1)
			{
				playerChoice = 5;
			}

		} while (playerChoice != 5);
		std::system("CLS");

		if (p1.getPlayerGoal() == true)
		{
			cout << "\nCongratulations, you have managed to complete the game!\n";
		}

		if (p1.getPlayerHP() == 0)
		{
			cout << "\nUnfortunately, you have lost the game.\n";
		}
		cout << "\nDo you want to play again? (1 for yes, 0 for no)\n";
		cin >> playAgain;
		CreateGrid();
	} while (playAgain != 0);
	
	std::system("pause");
}

void PlayerMove(int x, int y)
{
	if (p1.getPlayerRow() + x == -1 || p1.getPlayerCollumn() + y == -1 || p1.getPlayerRow() + x == 20 || p1.getPlayerCollumn() + y == 20)
	{
		cout << "\nInvalid move, please try again\n";
	}
	else if (gameBoard[p1.getPlayerRow()+x][p1.getPlayerCollumn()+y] == "2")
	{
		gameBoard[p1.getPlayerRow() ][p1.getPlayerCollumn()] = "0";
		p1.setPlayerRow(x);
		p1.setPlayerCollumn(y);
		gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "1";
		hiddenBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "1";
		p1.setPlayerHP(-5);
	}
	else if (gameBoard[p1.getPlayerRow() + x][p1.getPlayerCollumn() + y] == "G")
	{
		gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "0";
		p1.setPlayerRow(x);
		p1.setPlayerCollumn(y);
		gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "1";
		hiddenBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "1";
		p1.setPlayerGoal(true);
	}
	else
	{
		gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "0";
		p1.setPlayerRow(x);
		p1.setPlayerCollumn(y);
		gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "1";
		hiddenBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "1";
		p1.setPlayerHP(-1);
	}
}
void CreateGrid()
{
	for (int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (int col = 0; col < NUMBER_OF_COLLUMNS; col++)
		{
			gameBoard[row][col] = "0";
			hiddenBoard[row][col] = "#";
		}
	}
	int enemyRow, enemyCollumn;
	srand(time(NULL));
	p1.initializePlayerRow(rand() % 20);
	p1.initializePlayerCollumn(rand() % 20);
	g1.setGoalRow(rand() % 20);
	g1.setGoalCollumn(rand() % 20);
	enemyRow = rand() % 20;
	enemyCollumn = rand() % 20;
	gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "1";
	hiddenBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "1";
	for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
	{
		if (gameBoard[enemyRow][enemyCollumn] == "1")
		{
			enemyRow = rand() % 20;
			enemyCollumn = rand() % 20;
		}
		else
		{
			gameBoard[enemyRow][enemyCollumn] = "2";
		}
		enemyRow = rand() % 20;
		enemyCollumn = rand() % 20;
	}
	do
	{
		if (gameBoard[rand() % 20][rand() % 20] == "1")
		{
			g1.setGoalRow(rand() % 20);
			g1.setGoalCollumn(rand() % 20);
		}
		else if (gameBoard[rand() % 20][rand() % 20] == "2")
		{
			g1.setGoalRow(rand() % 20);
			g1.setGoalCollumn(rand() % 20);
		}
		else if (abs((g1.getGoalCollumn() + g1.getGoalRow()) - (p1.getPlayerCollumn() + p1.getPlayerRow())) < 10)
		{
			g1.setGoalRow(rand() % 20);
			g1.setGoalCollumn(rand() % 20);
		}


	} while ((abs((g1.getGoalCollumn() + g1.getGoalRow()) - (p1.getPlayerCollumn() + p1.getPlayerRow())) < 10));
	gameBoard[g1.getGoalRow()][g1.getGoalCollumn()] = "G";
	cout << "\n";

}
void DisplayGrid()
{
	for (int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (int col = 0; col < NUMBER_OF_COLLUMNS; col++)
		{
			if (gameBoard[row][col] == "1")
			{
				hiddenBoard[row][col] = "1";
				cout << "\t" << dye::aqua(hiddenBoard[row][col]);
				hiddenBoard[row][col] = ".";
			}
			else if(hiddenBoard[row][col]=="2")
			{
				cout << "\t" << dye::light_red(hiddenBoard[row][col]);
			}
			else if(hiddenBoard[row][col]=="G")
			{
				cout << "\t" << dye::yellow(hiddenBoard[row][col]);
			}
			else
			{

				cout << "\t" << hiddenBoard[row][col];
			}

		}
		cout << "\n";
	}
}//DIFFICULTY: VERY EASY CAN SEE BOARD, 150 HEALTH, 10 ENEMIES, EASY NO BOARD, 10 ENEMIES, MEDIUM NO BOARD, 20 ENEMIES, 100 HP, HARD NO BOARD, 30 ENEMIES, 50 HP