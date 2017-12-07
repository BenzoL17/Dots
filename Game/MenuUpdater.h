#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include "ScreenManager.h"


enum textType {
	GAME_CONTINUE,
	GAME_NEW,
	GAME_EXIT
};

class MenuUpdater
{
public:
	MenuUpdater();
	~MenuUpdater();
	void init(bool isPauseMenu);
	sf::Text &getText(int textIndex);
	sf::Sprite &getBackground();
	sf::RectangleShape &getTextBox();
	void update(int mousePosX, int mousePosY, bool isPauseMenu);
	void goToScreen(sf::RenderWindow &window);
	void unload();
private:
	//sf::RectangleShape testBox;
	sf::Texture backgroundTexture;
	sf::Sprite background;
	sf::Color textColor;
	//sf::Font font;
	sf::Text *arrText[3];
	int textIndex = 4;
	bool isInArea(int mousePosX, int mousePosY, bool isPauseMenu);
	int boxClicked(int mousePosX, int mousePosY, bool isPauseMenu);
	void fillText(int textIndex);
};

