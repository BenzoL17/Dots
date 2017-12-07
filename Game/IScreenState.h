#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "InputManager.h"

#define WINDOW_WIDTH 560 //600
#define WINDOW_HEIGHT 560

enum screenType {
	MENU,
	PAUSE_MENU,
	NEW_GAME,
	GAME,
	END
};

 
class IScreenState {
public:
	int screeType;
	IScreenState() {};
	virtual ~IScreenState() {};
	virtual void Init() = 0;
	virtual void Unload() = 0;
	virtual void Update(sf::RenderWindow &window, sf::Event ev) = 0;
	virtual void Draw(sf::RenderWindow &window) = 0;
protected:
	InputManager input;
};