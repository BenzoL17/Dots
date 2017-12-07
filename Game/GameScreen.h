#pragma once
#include "IScreenState.h"
#include "Object.h"
#include "GameScreenUpdater.h"


class GameScreen :
	public IScreenState
{
private:
	GameScreenUpdater *gameUpdater;
	sf::Sprite background;
	bool once = false;
public:

	GameScreen();
	~GameScreen();
	void Init();
	void Unload();
	void Update(sf::RenderWindow &window, sf::Event ev);
	void Draw(sf::RenderWindow &window);
};

