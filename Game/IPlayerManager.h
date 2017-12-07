#pragma once
#include <SFML/Graphics.hpp>

class IPlayerManager
{
public:
	IPlayerManager() {};
	virtual ~IPlayerManager() {};
	virtual void init() = 0;
	virtual void clearPlayerInfo() = 0;
	virtual void setPlayer(int playerNumber) = 0;
	virtual void setOppositePlayer() = 0;
	virtual void plusScore() = 0;
	virtual sf::Color getPlayerColor() = 0;
	virtual int getPlayerNumber() = 0;
	virtual int getPlayerScore() = 0;
};

