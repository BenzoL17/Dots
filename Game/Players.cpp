#include "Players.h"



FirstPlayer::FirstPlayer()
{
}


FirstPlayer::~FirstPlayer()
{
}

void FirstPlayer::init()
{
	score = 0;
	color.a = 100;
	color.r = 255;
	color.g = 0;
	color.b = 0;
	numberOfPlayer = playerNumber::FIRST;
}

void FirstPlayer::clearInfo()
{
	init();
}

sf::Color FirstPlayer::getColor()
{
	return color;
}

void FirstPlayer::setColor(sf::Color color)
{
	this->color = color;
}

void FirstPlayer::increasePlayerScore()
{
	++score;
}



int FirstPlayer::getScore()
{
	return score;
}

playerNumber FirstPlayer::getPlayerNumber()
{
	return numberOfPlayer;
}











SecondPlayer::SecondPlayer()
{
}


SecondPlayer::~SecondPlayer()
{
}

void SecondPlayer::init()
{
	score = 0;
	color.a = 100;
	color.r = 0;
	color.g = 255;
	color.b = 0;
	numberOfPlayer = playerNumber::SECOND;
}

void SecondPlayer::clearInfo()
{
	init();
}

sf::Color SecondPlayer::getColor()
{
	return color;
}

void SecondPlayer::setColor(sf::Color color)
{
	this->color = color;
}

void SecondPlayer::increasePlayerScore()
{
	++score;
}


int SecondPlayer::getScore()
{
	return score;
}

playerNumber SecondPlayer::getPlayerNumber()
{
	return numberOfPlayer;
}
