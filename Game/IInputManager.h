#pragma once
#include <SFML/Graphics.hpp>

class IInputManager
{
public:
	IInputManager() {};
	virtual ~IInputManager() {};
	virtual bool update(sf::Event event) = 0;
	virtual bool KeyPressed(sf::Keyboard::Key key) = 0;
	virtual bool KeyReleased(int key) = 0;

	virtual bool MouseKeyPressed(int button) = 0 ;
	virtual bool MouseKeyReleased(int button) = 0;
};

