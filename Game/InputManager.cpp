#include "InputManager.h"



InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

bool InputManager::update(sf::Event event)
{
	if (event.type != sf::Event::MouseWheelMoved) {
		this->event = event;
		return true;
	}
	return false;
}

bool InputManager::KeyPressed(sf::Keyboard::Key key)
{
	if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(key)) {

			return true;
		}
	}
	return false;
}

bool InputManager::KeyReleased(int key)
{
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == key) {

			return true;
		}
	}
	return false;
}


bool InputManager::MouseKeyPressed(int button)
{
	if (event.mouseButton.button == button && event.type == sf::Event::MouseButtonPressed) {
		return true;
	}
	return false;
}

bool InputManager::MouseKeyReleased(int button)
{
	if (event.mouseButton.button == button && event.type == sf::Event::MouseButtonReleased) {

		return true;
	}
	return false;
}
