#pragma once
#include <SFML/Graphics.hpp>


enum playerNumber {
	FIRST,
	SECOND
};

class IPlayer
{

public:
	IPlayer() {};
	virtual ~IPlayer() {};
	virtual void init() = 0;
	virtual void clearInfo() = 0;
	virtual sf::Color getColor() = 0;
	virtual int getScore() = 0;
	virtual playerNumber getPlayerNumber() = 0;
	virtual void increasePlayerScore() = 0;
	virtual void setColor(sf::Color) = 0;	
};

