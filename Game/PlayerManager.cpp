#include "PlayerManager.h"

IPlayer *player;
IPlayer *firstPlayer;
IPlayer *secondPlayer;

PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

PlayerManager * PlayerManager::getInstance()
{
	static PlayerManager *instance;
	if (!instance)
		instance = new PlayerManager();
	return instance;

}

void PlayerManager::init()
{
	firstPlayer = new FirstPlayer();
	secondPlayer = new SecondPlayer();
	firstPlayer->init();
	secondPlayer->init();
}

void PlayerManager::clearPlayerInfo()
{
	firstPlayer->clearInfo();
	secondPlayer->clearInfo();
}

void PlayerManager::setPlayer(int playerNumber)
{
	switch (playerNumber)
	{
	case FIRST:
		init();
		player = firstPlayer;
		break;
	case SECOND:
		init();
		player = secondPlayer; 
		break;
	}
}

void PlayerManager::setOppositePlayer()
{
	if (player->getPlayerNumber() == FIRST) {
		player = secondPlayer;
		return;
	}
	else if (player->getPlayerNumber() == SECOND) {
		player = firstPlayer;
	}
}

void PlayerManager::plusScore()
{
	player->increasePlayerScore();
}

sf::Color PlayerManager::getPlayerColor()
{
	return player->getColor();
}

int PlayerManager::getPlayerNumber()
{
	return player->getPlayerNumber();
}

int PlayerManager::getPlayerScore()
{
	return player->getScore();
}
