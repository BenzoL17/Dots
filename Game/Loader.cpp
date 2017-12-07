#include "Loader.h"

bool Loader::init()
{
	//harngton = new sf::Font();
	//harlowsi = new sf::Font();
	//ariali = new sf::Font();
	////menuBackground = new sf::Texture();
	//gameBackground = new sf::Texture();
	//endBackgroundFirst = new sf::Texture();
	//endBackgroundSecond = new sf::Texture();
	//endBackgroundDraw = new sf::Texture();

	if (!harngton.loadFromFile("resources\\Fonts\\HARNGTON.TTF"))
		return false;
	if (!harlowsi.loadFromFile("resources\\Fonts\\HARLOWSI.TTF"))
		return false;
	if (!ariali.loadFromFile("resources\\Fonts\\ariali.ttf"))
		return false;
	if (!menuBackground.loadFromFile("resources\\Backgrounds\\4background.jpg"))
		return false;
	if (!gameBackground.loadFromFile("resources\\Backgrounds\\gameBackground.jpg"))
		return false;
	if (!gameBoader.loadFromFile("resources\\Backgrounds\\gameBorder.png"))
		return false;
	if (!endBackgroundFirst.loadFromFile("resources\\Backgrounds\\firstEnd.png"))
		return false;
	if (!endBackgroundSecond.loadFromFile("resources\\Backgrounds\\secondEnd.png"))
		return false;
	if (!endBackgroundDraw.loadFromFile("resources\\Backgrounds\\drawEnd.png"))
		return false;
	return true;
}

void Loader::unload()
{
	//delete harngton;
	//delete harlowsi;
	//delete menuBackground;
	/*delete gameBackground;
	delete endBackgroundFirst;
	delete endBackgroundSecond;
	delete endBackgroundDraw;*/
}

Loader *Loader::getInstance()
{
	static Loader *loader;
	if (!loader)
		loader = new Loader();
	return loader;
}

sf::Font & Loader::getFont(fontName fName)
{
	switch (fName)
	{
	case HARNGTON:
		return harngton;
	case HARLOWSI:
		return harlowsi;
	}
}

sf::Texture & Loader::getTexture(textureName tName)
{
	switch (tName)
	{
	case MENU_BACKGROUND:
		return menuBackground;
	case GAME_BACKGROUND:
		return gameBackground;
	case GAME_BOADER:
		return gameBoader;
	case END_BACKGROUND_FIRST:
		return endBackgroundFirst;
	case END_BACKGROUND_SECOND:
		return endBackgroundSecond;
	case END_BACKGROUND_DRAW:
		return endBackgroundDraw;
	}
}
