#include "ScreenManager.h"
#include "GameScreen.h"
#include "GameScreenUpdater.h"
#include "Loader.h"



GameScreen::GameScreen(){}
GameScreen::~GameScreen(){}


void GameScreen::Init()
{
	gameUpdater = new GameScreenUpdater();
	gameUpdater->init();
	PlayerManager::getInstance()->setPlayer(FIRST);
	screeType = GAME;
}

void GameScreen::Unload()
{
	gameUpdater->unload();
	delete gameUpdater;
	PlayerManager::getInstance()->clearPlayerInfo();
}

void GameScreen::Update(sf::RenderWindow &window, sf::Event ev)
{
	if (input.update(ev)) {
		if (ev.type == sf::Event::MouseMoved) {
			gameUpdater->update(ev.mouseMove.x, ev.mouseMove.y);
		}
		if (input.MouseKeyReleased(sf::Mouse::Left)) {
			gameUpdater->fillLine(ev.mouseButton.x, ev.mouseButton.y);
		}
		if (input.KeyReleased(sf::Keyboard::Escape)) {
			ScreenManager::getInstance()->setScreen(PAUSE_MENU);
		}
	}
}

void GameScreen::Draw(sf::RenderWindow &window)
{
	window.draw(gameUpdater->getSprite(textureName::GAME_BACKGROUND));
	window.draw(gameUpdater->getSprite(textureName::GAME_BOADER));
	//sf::Text text;

	//text.setFont(Loader::getInstance()->getFont(fontName::ARIALI)); // font is a sf::Font
	//if(PlayerManager::getInstance()->getPlayerNumber() == FIRST)
	//	text.setString("FIRST red " + std::to_string(PlayerManager::getInstance()->getPlayerScore()));
	//else
	//	text.setString("second green " + std::to_string(PlayerManager::getInstance()->getPlayerScore()));
	//text.setCharacterSize(14); // in pixels, not points!
	//text.setPosition(450, 50);
	//						   // set the color
	//text.setColor(sf::Color::Blue);

	for (short int i = 0; i < 100; i++)	{
		window.draw(gameUpdater->getBox(i));
		window.draw(gameUpdater->getLine(i, LEFT));
		window.draw(gameUpdater->getLine(i, RIGHT));
		window.draw(gameUpdater->getLine(i, TOP));
		window.draw(gameUpdater->getLine(i, BOTTOM));
	}
	for (short int i = 0; i < 121; i++)	{
		window.draw(gameUpdater->getCircle(i));
	}
	window.draw(gameUpdater->getTextPlayer(playerNumber::FIRST));
	window.draw(gameUpdater->getTextPlayer(playerNumber::SECOND));
	window.draw(gameUpdater->getScore(playerNumber::FIRST));
	window.draw(gameUpdater->getScore(playerNumber::SECOND));
}

