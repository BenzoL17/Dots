#pragma once
#include "IInputManager.h"

class InputManager// : public IInputManager
{
private:
	sf::Event event;
	int timer = 0;
public:
	InputManager();
	~InputManager();
	bool update(sf::Event event);
	bool KeyPressed(sf::Keyboard::Key key);
	bool KeyReleased(int key);

	bool MouseKeyPressed(int button);
	bool MouseKeyReleased(int button);
};

