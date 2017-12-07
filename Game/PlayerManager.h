#pragma once
#include "IPlayer.h"
#include "Players.h"
#include "IPlayerManager.h"

class PlayerManager : public IPlayerManager
{
private:
	PlayerManager();
public:
	~PlayerManager();
	static PlayerManager *getInstance();
	void init();
	void clearPlayerInfo();
	void setPlayer(int playerNumber);
	void setOppositePlayer();
	void plusScore();
	sf::Color getPlayerColor();
	int getPlayerNumber();
	int getPlayerScore();
};

