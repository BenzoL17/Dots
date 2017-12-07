#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include "Loader.h"

class GameScreenUpdater
{
public:
	GameScreenUpdater();
	~GameScreenUpdater();
	void init();
	sf::RectangleShape getBox(int boxNumber);
	sf::RectangleShape getLine(int boxNumber, int side);
	sf::CircleShape getCircle(int circleNumber);
	sf::Text getScore(playerNumber number);
	sf::Text getTextPlayer(playerNumber number);
	sf::Sprite getSprite(textureName sName);
	void fillLine(int mousePosX, int mousePosY);
	void update(int mousePosX, int mousePosY);
	void unload();
private:
	Box *arrBox[100];
	Circle *arrCircle[121];
	int boxNumber;
	int lineSide;
	sf::Color colorNonActive;
	sf::Color colorFirstPlayer;
	sf::Color colorSecondPlayer;
	sf::Sprite background;
	sf::Sprite border;
	sf::Text arrTextScore[2];
	sf::Text arrTextPlayer[2];
	void initText();
	void initColor();
	int boxClicked(int mousePosX, int mousePosY);
	void transparentFillLine(int side);
	void fillLine(int side);
	void fillConnected(int side);

	void setTextScore();
	void setPlayerColor(const int player);
	void clearTransparentLine();

	bool isInArea(int mousePosX, int mousePosY);
	bool isLineClicked(int mousePosX, int mousePosY);
	bool isBoxGetFilled(int number);
	bool isValidBox();
	bool isValidBox(int boxIndex);
	bool isValidLine();
	bool isValidLine(int side);
};

