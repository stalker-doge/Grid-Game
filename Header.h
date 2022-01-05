#pragma once
#include <iostream>
using namespace std;


const int NUMBER_OF_ROWS = 20;
const int NUMBER_OF_COLLUMNS = 20;
const int NUMBER_OF_ENEMIES = 10;

class Player
{
	int playerRow, playerCollumn;
	bool playerGoal = false;
	int playerHP = 0;
	int playerLives = 0;
	int playerDifficulty = 0;

public:
	int getPlayerRow();
	int getPlayerCollumn();
	int getPlayerHP();
	bool getPlayerGoal();
	int getPlayerDifficulty();
	int getPlayerLives();


	void setPlayerRow(int Row);
	void setPlayerCollumn(int Collumn);
	void initializePlayerRow(int Row);
	void initializePlayerCollumn(int Collumn);
	void setPlayerHP(int HP);
	void setPlayerLives(int Lives);
	void changePlayerHP(int HP);
	void setPlayerGoal(bool Goal);
	void setPlayerDifficulty(int Difficulty);
};
class Goal
{
	int goalRow, goalCollumn;

public:
	int getGoalRow();
	int getGoalCollumn();

	void setGoalRow(int Row);
	void setGoalCollumn(int Collumn);

};
class Enemy
{
	int enemyRow, enemyCollumn;

public:
	int getEnemyRow();
	int getEnemyCollumn();

	void setEnemyRow(int Row);
	void setEnemyCollumn(int Collumn);
	void changeEnemyRow(int Row);
	void changeEnemyCollumn(int Collumn);

};