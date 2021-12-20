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
	int playerHP = 100;

public:
	int getPlayerRow();
	int getPlayerCollumn();
	int getPlayerHP();
	bool getPlayerGoal();


	void setPlayerRow(int Row);
	void setPlayerCollumn(int Collumn);
	void initializePlayerRow(int Row);
	void initializePlayerCollumn(int Collumn);
	void setPlayerHP(int HP);
	void setPlayerGoal(bool Goal);

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