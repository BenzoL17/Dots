#pragma once


#define WINDOW_WIDTH  560 //600
#define WINDOW_HEIGHT 560

class IScreenManager
{
public:
	IScreenManager() {};
	virtual void Init() = 0;
	virtual void Update(sf::RenderWindow &window, sf::Event ev) = 0;
	virtual void Draw(sf::RenderWindow &window) = 0;
	//virtual void setScreen(int screenType) = 0;
	virtual ~IScreenManager() {};
};