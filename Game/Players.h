#pragma once
#include "IPlayer.h"


class FirstPlayer :
	public IPlayer
{
public:
	FirstPlayer();
	~FirstPlayer();
	void init();
	void clearInfo();
	sf::Color getColor();
	int getScore();
	playerNumber getPlayerNumber();
	void setColor(sf::Color color);
	void increasePlayerScore();
private:
	playerNumber numberOfPlayer;
	int score;
	sf::Color color;
};


class SecondPlayer :
	public IPlayer
{
public:
	SecondPlayer();
	~SecondPlayer();
	void init();
	void clearInfo();
	sf::Color getColor();
	int getScore();
	playerNumber getPlayerNumber();
	void setColor(sf::Color color);
	void increasePlayerScore();
private:
	playerNumber numberOfPlayer;
	int score;
	sf::Color color;
};