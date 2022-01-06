#include <iostream>
#include "Header.h"
#include "Colour.h"
#include <fstream>
using namespace std;

Player p1;
Goal g1;
Enemy enemy[NUMBER_OF_ENEMIES];
string gameBoard[NUMBER_OF_ROWS][NUMBER_OF_COLLUMNS];
string hiddenBoard[NUMBER_OF_ROWS][NUMBER_OF_COLLUMNS];
void PlayerMove(int x, int y);
void CreateGrid();
void DisplayGrid();
void EnemyMove(int x, int y, int currentEnemy);
void EnemyRandomMove();
void WriteHighScore(string playerName,string playerScore);
void ShowHighScores();
void DetectEnemy();
void DetectGoal();

void main()
{
	CreateGrid();
	int playerChoice = 0;
	int playerDifficulty = 4;
	int playAgain = 1;
	int playerLives = 0;
	int playerMenuChoice = 0;
	string playerName;
	int playerScore;
	int playerHP;
	bool saveScore = false;
	do
	{
		cout <<dye::light_yellow( "\nMenu\n\n");
		cout << dye::light_green("\n1.Play the game");
		cout << dye::light_aqua("\n2.View HighScores then play");
		cout << dye::light_red("\n3.Exit Game\n");
		cin >> playerMenuChoice;
		switch (playerMenuChoice)
		{
		case 1:
			cout << "\nStarting game...";
			break;
		case 2:
			ShowHighScores();
			system("pause");
			break;
		case 3:
			break;
		default:
			cout << "\n Input not recognized, starting game...";
			break;

		}
		if (playerMenuChoice != 3)
		{
			do
			{
				while (playerDifficulty > 3 || playerDifficulty < 0)
				{
					cout << "\nWhat difficulty do you want: 0 for Very Easy, 1 for Easy, 2 for Medium,3 for Hard\n"; //DIFFICULTY: VERY EASY CAN SEE BOARD, 200 HEALTH, EASY CAN SEE BOARD, 150 HP, MEDIUM NO BOARD, 100 HP, HARD NO BOARD, 50 HP
					cin >> playerDifficulty;

					switch (playerDifficulty)
					{
					case 0:
					{
						p1.setPlayerDifficulty(0);
						p1.setPlayerHP(200);
						playerHP = 200;
						p1.setPlayerLives(4);
						break;
					}
					case 1:
					{
						p1.setPlayerDifficulty(1);
						p1.setPlayerHP(150);
						playerHP = 150;
						p1.setPlayerLives(3);
						break;
					}
					case 2:
					{	p1.setPlayerDifficulty(2);
					p1.setPlayerHP(100);
					playerHP = 100;
					p1.setPlayerLives(2);
					break;
					}
					case 3:
					{
						p1.setPlayerDifficulty(3);
						p1.setPlayerHP(50);
						playerHP = 50;
						p1.setPlayerLives(1);
						break;
					}
					default:
					{
						cout << "\nInput not recognized, please try again\n";
						break;
					}

					}
				}
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
					cout << "Current Lives: " << p1.getPlayerLives() << "\n";
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
					case 8:
						p1.setPlayerDifficulty(1);
						break;
						//Debug to see the board
					case 9:
						CreateGrid();
						//Debug to re-generate the board
						break;
					default:
						cout << "\nInput not recognized, please try again\n";
					}
					EnemyRandomMove();
					DetectEnemy();//Finds if player is near enemy

					DetectGoal();//Finds if player is near goal

					if (p1.getPlayerGoal() == true || p1.getPlayerHP() < 1)
					{
						playerChoice = 5;
					}

				} while (playerChoice != 5);
				std::system("CLS");

				if (p1.getPlayerGoal() == true)
				{
					cout << dye::light_yellow("\nCongratulations, you have managed to complete the game!\n");
					playerScore = p1.getPlayerLives() * 100 + p1.getPlayerDifficulty() * 1000 + p1.getPlayerHP() * 50;
					cout << "\n" << dye::light_aqua("Your Score is: ");
					cout << dye::light_yellow(playerScore);
					saveScore = true;
				}

				if (p1.getPlayerHP() == 0)
				{
					cout << "\nUnfortunately, you have lost a life.\n";
					playerLives = p1.getPlayerLives() - 1;
					p1.setPlayerLives(playerLives);
				}
				cout << "\n" << dye::light_red(p1.getPlayerLives()) << " lives left\n";
				cout << "\nDo you want to play again? (1 for yes, 0 for no and saves the score)\n";
				cin >> playAgain;
				if (p1.getPlayerLives() == 0)
				{
					playerDifficulty = 4;
				}
				p1.setPlayerGoal(false);
				p1.setPlayerHP(playerHP);
				CreateGrid();
			} while (playAgain != 0);
		}
		if (saveScore=true)
		{
			cout << "What is your Name?\n";
			cin >> playerName;
			WriteHighScore(playerName, to_string(playerScore));
		}
		playerScore = 0;
		saveScore = false;
		playerDifficulty = 4;
	}while (playerMenuChoice != 3);
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
		p1.changePlayerHP(-5);
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
		p1.changePlayerHP(-1);
	}
}

void EnemyRandomMove()
{
	int enemyRandomMove;
	srand(time(NULL));
	for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
	{
		enemyRandomMove = (rand() % 5);
		switch (enemyRandomMove)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				EnemyMove(-1, 0, i);
				break;
			}
			case 2:
			{
				EnemyMove(1, 0, i);
				break;
			}
			case 3:
			{
				EnemyMove(0, -1, i);
				break;
			}
			case 4:
			{
				EnemyMove(0, 1, i);
				break;
			}
		}
	}
}

void EnemyMove(int x, int y, int currentEnemy)
{
	if (enemy[currentEnemy].getEnemyRow() + x == -1 || enemy[currentEnemy].getEnemyCollumn() + y == -1 || enemy[currentEnemy].getEnemyRow() + x == 20 || enemy[currentEnemy].getEnemyCollumn() + y == 20)
	{
		//makes it so that enemies don't go outside the array
	}
	else if (gameBoard[enemy[currentEnemy].getEnemyRow() + x][enemy[currentEnemy].getEnemyCollumn() + y] == "1")
	{
		//checks to ensure that enemies don't go in the same tile as the player
	}
	else if (gameBoard[enemy[currentEnemy].getEnemyRow() + x][enemy[currentEnemy].getEnemyCollumn() + y] == "2")
	{
		//so enemies don't go inside eachother
	}
	else if (gameBoard[enemy[currentEnemy].getEnemyRow() + x][enemy[currentEnemy].getEnemyCollumn() + y] == "G")
	{
		//enemies don't go in the same place as the goal
	}
	else
	{
		gameBoard[enemy[currentEnemy].getEnemyRow()][enemy[currentEnemy].getEnemyCollumn()] = "0";
		enemy[currentEnemy].changeEnemyRow(x);
		enemy[currentEnemy].changeEnemyCollumn(y);
		gameBoard[enemy[currentEnemy].getEnemyRow()][enemy[currentEnemy].getEnemyCollumn()] = "2";
		hiddenBoard[enemy[currentEnemy].getEnemyRow()][enemy[currentEnemy].getEnemyCollumn()] = "#";
	}
}

void DetectEnemy()
{
	if ((gameBoard[p1.getPlayerRow() + 1][p1.getPlayerCollumn()] == "2" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerRow() + 1 < 20)
		|| (gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + 1] == "2" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerCollumn() + 1 < 20)
		|| (gameBoard[p1.getPlayerRow() - 1][p1.getPlayerCollumn()] == "2" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerRow() + 1 < 20)
		|| (gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + -1] == "2" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerCollumn() + 1 < 20)) //Turns out you can bracket and write massive statements on new lines, neat
	{
		cout << dye::light_red("\nWARNING: YOU ARE 1 MOVE AWAY FROM AN ENEMY");
		hiddenBoard[p1.getPlayerRow() + 1][p1.getPlayerCollumn()] = "2";
	}

}

void DetectGoal()
{
	if ((gameBoard[p1.getPlayerRow() + 1][p1.getPlayerCollumn()] == "G" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerRow() + 1 < 20)
		|| (gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + 1] == "G" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerCollumn() + 1 < 20)
		|| (gameBoard[p1.getPlayerRow() - 1][p1.getPlayerCollumn()] == "G" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerRow() + 1 < 20)
		|| (gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + -1] == "G" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerCollumn() + 1 < 20))
	{
		cout << dye::light_yellow("\nYOU ARE 1 MOVE AWAY FROM THE GOAL");
		hiddenBoard[p1.getPlayerRow() + 1][p1.getPlayerCollumn()] = "G";
	}
	/*if (gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + 1] == "G" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerCollumn() + 1 < 20)
	{
		cout << dye::light_yellow("\nYOU ARE 1 MOVE AWAY FROM THE GOAL");
		hiddenBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + 1] = "G";
	}
	if (gameBoard[p1.getPlayerRow() - 1][p1.getPlayerCollumn()] == "G" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerRow() + 1 < 20)
	{
		cout << dye::light_yellow("\nYOU ARE 1 MOVE AWAY FROM THE GOAL");
		hiddenBoard[p1.getPlayerRow() - 1][p1.getPlayerCollumn()] = "G";
	}
	if (gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + -1] == "G" && p1.getPlayerRow() + 1 > -1 && p1.getPlayerCollumn() + 1 < 20)
	{
		cout << dye::light_yellow("\nYOU ARE 1 MOVE AWAY FROM THE GOAL");
		hiddenBoard[p1.getPlayerRow()][p1.getPlayerCollumn() + -1] = "G";
	}*/
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
	p1.initializePlayerRow(rand() % 21);
	p1.initializePlayerCollumn(rand() % 21);
	g1.setGoalRow(rand() % 21);
	g1.setGoalCollumn(rand() % 21);
	enemyRow = rand() % 21;
	enemyCollumn = rand() % 21;
	gameBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "1";
	hiddenBoard[p1.getPlayerRow()][p1.getPlayerCollumn()] = "1";
	for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
	{
		if (gameBoard[enemyRow][enemyCollumn] == "1")
		{
			enemyRow = rand() % 21;
			enemyCollumn = rand() % 21;
		}
		else
		{
			enemy[i].setEnemyCollumn(enemyCollumn);
			enemy[i].setEnemyRow(enemyRow);
			gameBoard[enemyRow][enemyCollumn] = "2";
		}
		enemyRow = rand() % 21;
		enemyCollumn = rand() % 21;
	}
	do
	{
		if (gameBoard[rand() % 21][rand() % 21] == "1")
		{
			g1.setGoalRow(rand() % 21);
			g1.setGoalCollumn(rand() % 21);
		}
		else if (gameBoard[rand() % 21][rand() % 21] == "2")
		{
			g1.setGoalRow(rand() % 21);
			g1.setGoalCollumn(rand() % 21);
		}
		else if (abs((g1.getGoalCollumn() + g1.getGoalRow()) - (p1.getPlayerCollumn() + p1.getPlayerRow())) < 10)
		{
			g1.setGoalRow(rand() % 21);
			g1.setGoalCollumn(rand() % 21);
		}


	} while ((abs((g1.getGoalCollumn() + g1.getGoalRow()) - (p1.getPlayerCollumn() + p1.getPlayerRow())) < 10));
	gameBoard[g1.getGoalRow()][g1.getGoalCollumn()] = "G";
	cout << "\n";

}
void DisplayGrid()
{
	if (p1.getPlayerDifficulty() >= 2)
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
				else if (hiddenBoard[row][col] == "2")
				{
					cout << "\t" << dye::light_red(hiddenBoard[row][col]);
				}
				else if (hiddenBoard[row][col] == "G")
				{
					cout << "\t" << dye::light_yellow(hiddenBoard[row][col]);
				}
				else
				{

					cout << "\t" << hiddenBoard[row][col];
				}

			}
			cout << "\n";
		}
	}
	else
	{
		for (int row = 0; row < NUMBER_OF_ROWS; row++)
		{
			for (int col = 0; col < NUMBER_OF_COLLUMNS; col++)
			{
				if (gameBoard[row][col] == "1")
				{
					gameBoard[row][col] = "1";
					cout << "\t" << dye::aqua(gameBoard[row][col]);
				}
				else if (gameBoard[row][col] == "2")
				{
					cout << "\t" << dye::light_red(gameBoard[row][col]);
				}
				else if (gameBoard[row][col] == "G")
				{
					cout << "\t" << dye::light_yellow(gameBoard[row][col]);
				}
				else
				{

					cout << "\t" << gameBoard[row][col];
				}

			}
			cout << "\n";
		}
	}
}
void ShowHighScores()
{
	ifstream arrayInputFile;
	string strLine;
	arrayInputFile.open("HighScore.csv", ios::in);
	do 
	{
		getline(arrayInputFile, strLine);
		cout << "\n" << strLine;
	} while (!arrayInputFile.eof());
	cout << "\n";
}

void WriteHighScore(string playerName, string playerScore)
{
	ofstream arrayInputFile;
	string strline = playerName + ", Score:" + playerScore;
	arrayInputFile.open("HighScore.csv", ios::app);
	arrayInputFile << strline << "\n";
}