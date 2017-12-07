#pragma once
#include "IScreenState.h"
#include "Object.h"
#include "EndSceneupdater.h"

class EndScreen :
	public IScreenState
{
private:
	EndSceneupdater *endSceneUpdater;
public:
	EndScreen();
	~EndScreen();
	void Init();
	void Unload();
	void Update(sf::RenderWindow &window, sf::Event ev);
	void Draw(sf::RenderWindow &window);

};

