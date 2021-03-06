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

int Player::getPlayerDifficulty()
{
	return playerDifficulty;
}

int Player::getPlayerLives()
{
	return playerLives;
}

void Player::setPlayerRow(int Row)
{
	playerRow =playerRow+ Row;
}

void Player::setPlayerCollumn(int Collumn)
{
	playerCollumn = playerCollumn+ Collumn;
}

void Player::initializePlayerRow(int Row)
{
	if (Row < 20)
	{
		playerRow = Row;
	}
}

void Player::initializePlayerCollumn(int Collumn)
{
	if (Collumn < 20)
	{
		playerCollumn = Collumn;
	}
}

void Player::setPlayerHP(int HP)
{
	playerHP = HP;
}

void Player::setPlayerLives(int Lives)
{
	playerLives = Lives;
}

void Player::changePlayerHP(int HP)
{
	playerHP = playerHP + HP;
}

void Player::setPlayerGoal(bool Goal)
{
	playerGoal = Goal;
}

void Player::setPlayerDifficulty(int Difficulty)
{
	playerDifficulty = Difficulty;
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
	goalRow = Row;
}

void Goal::setGoalCollumn(int Collumn)
{
	goalCollumn = Collumn;
}
int Enemy::getEnemyRow()
{
	return enemyRow;
}

int Enemy::getEnemyCollumn()
{
	return enemyCollumn;
}

void Enemy::setEnemyRow(int Row)
{
	enemyRow = Row;
}

void Enemy::setEnemyCollumn(int Collumn)
{
	enemyCollumn = Collumn;
}

void Enemy::changeEnemyRow(int Row)
{
	enemyRow = enemyRow+ Row;
}

void Enemy::changeEnemyCollumn(int Collumn)
{
	enemyCollumn = enemyCollumn+ Collumn;
}
