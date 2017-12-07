#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenManager.h"



class EndSceneupdater
{
public:
	EndSceneupdater();
	~EndSceneupdater();
	void init();
	sf::Text *getScore(int scoreIndex);
	sf::Sprite &getBackground();
	sf::RectangleShape &getPlayerBox();
	sf::RectangleShape &getBackToMenuBox();
	void update(int mousePosX, int mousePosY);
	void boxClicked(int mousePosX, int mousePosY);
	void unload();
private:
	sf::RectangleShape *playerBox;
	sf::RectangleShape *backToMenuBox;
	sf::Vector2f *size;
	sf::Texture *backgroundTexture;
	sf::Sprite *background;
	sf::Color *textColor;
	sf::Color *backToMenuColor;
	sf::Text *arrTextScore[3];
	int scoreIndex = 0;
	int score;
	void setTextScore();
	bool isInArea(int mousePosX, int mousePosY);
	void fillText();
};

