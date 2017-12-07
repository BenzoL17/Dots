#pragma once
//#include "EndScreen.h"
//#include "GameScreen.h"
//#include "MenuScreen.h"
#include "IScreenState.h"
#include "IScreenManager.h"


class ScreenManager: public IScreenManager
{
private:

	ScreenManager();
	ScreenManager(const ScreenManager &scr);  //copy constructor
	//ScreenManager &operator = (const ScreenManager &scr);
	
	
public:
	static ScreenManager *getInstance();
	void Init();
	void Update(sf::RenderWindow &window, sf::Event ev);
	void Draw(sf::RenderWindow &window);
	void setScreen(int screenType);
	~ScreenManager();
};

