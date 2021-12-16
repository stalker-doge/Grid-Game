#include <iostream>
#include "Header.h"
using namespace std;

int Player::getPlayerRow()
{
	return playerRow;
}

int Player::getPlayerCollumn()
{
	return playerCollumn;
}

int Player::getPlayerHP()
{
	return playerHP;
}

bool Player::getPlayerGoal()
{
	return playerGoal;
}

void Player::setPlayerRow(int Row)
{
	playerRow =playerRow+ Row;
}

void Player::setPlayerCollumn(int Collumn)
{
	playerCollumn = playerCollumn+ Collumn;
}

void Player::setPlayerHP(int HP)
{
	playerHP = playerHP + HP;
}

void Player::setPlayerGoal(bool Goal)
{
	playerGoal = Goal;
}

int Goal::getGoalRow()
{
	return goalRow;
}

int Goal::getGoalCollumn()
{
	return goalCollumn;
}

void Goal::setGoalRow(int Row)
{
	if (Row < 20&&Row >0)
	{
		goalRow = Row;
	}
	else
	{
		goalCollumn = 0;
	}
}

void Goal::setGoalCollumn(int Collumn)
{
	if (Collumn < 20&&Collumn>0)
	{
		goalCollumn = Collumn;
	}
	else
	{
		goalCollumn = 0;
	}
}
