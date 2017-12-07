#pragma once
#include "IScreenState.h"
#include "MenuUpdater.h"

class MenuScreen :
	public IScreenState
{
private:
	MenuUpdater *menuUpdater;
	sf::RectangleShape upTitle;
	//sf::Color color;
	sf::Vector2f size;
	/*sf::Texture backgroundTexture;
	sf::Sprite background;*/
	//sf::Font font;
	//sf::Text textContinueGame;
	//sf::Text textNewGame;
	//sf::Text textExit;
public:
	MenuScreen();
	~MenuScreen();
	void Init();
	void Unload();
	void Update(sf::RenderWindow &window, sf::Event ev);
	void Draw(sf::RenderWindow &window);
};

