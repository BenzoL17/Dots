#pragma once
#include <SFML/Graphics.hpp>

enum fontName {
	HARNGTON,
	HARLOWSI,
	ARIALI
};

enum textureName {
	MENU_BACKGROUND,
	GAME_BACKGROUND,
	GAME_BOADER,
	END_BACKGROUND_FIRST,
	END_BACKGROUND_SECOND,
	END_BACKGROUND_DRAW
};



class Loader 
{
private:
	Loader() {};
	sf::Font harngton; 
	sf::Font harlowsi;
	sf::Font ariali;
	sf::Texture menuBackground;
	sf::Texture gameBackground;
	sf::Texture gameBoader;
	sf::Texture endBackgroundFirst;
	sf::Texture endBackgroundSecond;
	sf::Texture endBackgroundDraw;
public:
	bool init();
	void unload();
	static Loader *getInstance();
	sf::Font &getFont(fontName fName);
	sf::Texture &getTexture(textureName tName);
};