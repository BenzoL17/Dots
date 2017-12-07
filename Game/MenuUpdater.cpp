#include "MenuUpdater.h"
#include <Windows.h>
#include "Loader.h"

MenuUpdater::MenuUpdater(){}
MenuUpdater::~MenuUpdater(){}


void MenuUpdater::init(bool isPauseMenu)
{
	textColor.a = 255;
	textColor.r = 128;
	textColor.g = 128;
	textColor.b = 128;
	arrText[textType::GAME_CONTINUE] = new sf::Text();
	arrText[textType::GAME_NEW] = new sf::Text();
	arrText[textType::GAME_EXIT] = new sf::Text();
	if (isPauseMenu) {
		arrText[textType::GAME_CONTINUE]->setFont(Loader::getInstance()->getFont(fontName::HARLOWSI));
		arrText[textType::GAME_CONTINUE]->setString("Continue Game");
		arrText[textType::GAME_CONTINUE]->setCharacterSize(30);
		arrText[textType::GAME_CONTINUE]->setColor(textColor);
		arrText[textType::GAME_CONTINUE]->setPosition(50, 200);
	}

arrText[textType::GAME_NEW]->setFont(Loader::getInstance()->getFont(fontName::HARLOWSI));
arrText[textType::GAME_NEW]->setString("New Game");
arrText[textType::GAME_NEW]->setCharacterSize(30);
arrText[textType::GAME_NEW]->setColor(textColor);
if (isPauseMenu)
arrText[textType::GAME_NEW]->setPosition(arrText[textType::GAME_CONTINUE]->getPosition().x, arrText[textType::GAME_CONTINUE]->getPosition().y + arrText[textType::GAME_CONTINUE]->getCharacterSize() + 20);
else
arrText[textType::GAME_NEW]->setPosition(50, 200);

arrText[textType::GAME_EXIT]->setFont(Loader::getInstance()->getFont(fontName::HARLOWSI));
arrText[textType::GAME_EXIT]->setString("Exit Game");
arrText[textType::GAME_EXIT]->setCharacterSize(30);
arrText[textType::GAME_EXIT]->setColor(textColor);
arrText[textType::GAME_EXIT]->setPosition(arrText[textType::GAME_NEW]->getPosition().x, arrText[textType::GAME_NEW]->getPosition().y + arrText[textType::GAME_NEW]->getCharacterSize() + 20);

background.setTexture(Loader::getInstance()->getTexture(textureName::MENU_BACKGROUND));
background.setTextureRect(sf::IntRect(300, 400, WINDOW_WIDTH, WINDOW_HEIGHT));
textColor.a = 100;
//testBox.setFillColor(textColor);  //box for testing
//testBox.setPosition(50, 200);
sf::Vector2f size;

if (isPauseMenu) {
	size.x = (185/*arrText[textType::GAME_CONTINUE]->getPosition().x - arrText[textType::GAME_EXIT]->getPosition().x*/);
	size.y = (arrText[textType::GAME_EXIT]->getPosition().y - arrText[textType::GAME_CONTINUE]->getPosition().y + 40);
}
else {
	size.x = (140/*arrText[textType::GAME_NEW]->getPosition().x - arrText[textType::GAME_EXIT]->getPosition().x*/);
	size.y = (arrText[textType::GAME_EXIT]->getPosition().y - arrText[textType::GAME_NEW]->getPosition().y);
}
//testBox.setSize(size);
}

sf::Text &MenuUpdater::getText(int textIndex)
{
	return *arrText[textIndex];
}

sf::Sprite & MenuUpdater::getBackground()
{
	return background;
}

//sf::RectangleShape & MenuUpdater::getTextBox()
//{
//	return testBox;
//}

void MenuUpdater::update(int mousePosX, int mousePosY, bool isPauseMenu)
{
	textColor.a = 255;
	textColor.r = 128;
	textColor.g = 128;
	textColor.b = 128;
	arrText[textType::GAME_CONTINUE]->setColor(textColor);
	arrText[textType::GAME_EXIT]->setColor(textColor);
	arrText[textType::GAME_NEW]->setColor(textColor);
	if (isInArea(mousePosX, mousePosY, isPauseMenu) == true) {
		textIndex = boxClicked(mousePosX, mousePosY, isPauseMenu);   //ѕолучаем номер квадрата, на который кликнули
		if (textIndex == 4)
			return;
		fillText(textIndex);
	}
	else
		textIndex = 4;
}

void MenuUpdater::goToScreen(sf::RenderWindow &window)
{
	if (textIndex != 4) {
		if (textIndex == textType::GAME_CONTINUE) {
			ScreenManager::getInstance()->setScreen(screenType::GAME);
		}
		if (textIndex == textType::GAME_NEW)
			ScreenManager::getInstance()->setScreen(screenType::NEW_GAME);
		if (textIndex == textType::GAME_EXIT)
			window.close();
	}
}

void MenuUpdater::unload()
{
	for (int i = 0; i < 3; i++)
	{
		delete arrText[i];
	}
}

bool MenuUpdater::isInArea(int mousePosX, int mousePosY, bool isPauseMenu)
{
	if (isPauseMenu) {
		if (mousePosX >= arrText[textType::GAME_CONTINUE]->getPosition().x && mousePosX <= arrText[textType::GAME_CONTINUE]->getPosition().x + 185) {
			if (mousePosY >= arrText[textType::GAME_CONTINUE]->getPosition().y && mousePosY <= arrText[textType::GAME_EXIT]->getPosition().y + 40) {
				return true;
			}
		}
		else
			return false;
	}
	else {
		if (mousePosX >= arrText[textType::GAME_NEW]->getPosition().x && mousePosX <= arrText[textType::GAME_NEW]->getPosition().x + 140) {
			if (mousePosY >= arrText[textType::GAME_NEW]->getPosition().y && mousePosY <= arrText[textType::GAME_EXIT]->getPosition().y + 45) {
				return true;
			}
		}
		else
			return false;
	}
}

int MenuUpdater::boxClicked(int mousePosX, int mousePosY, bool isPauseMenu)
{
	if (isPauseMenu) {
		if (mousePosX >= arrText[textType::GAME_CONTINUE]->getPosition().x && mousePosX <= arrText[textType::GAME_CONTINUE]->getPosition().x + 185) {
			if (mousePosY >= arrText[textType::GAME_CONTINUE]->getPosition().y && mousePosY <= arrText[textType::GAME_NEW]->getPosition().y) {
				return textType::GAME_CONTINUE;
			}
		}
	}
	for (int i = GAME_NEW; i <= GAME_EXIT; i++) {
		if (mousePosX >= arrText[i]->getPosition().x && mousePosX <= arrText[i]->getPosition().x + 140) {
			if (mousePosY >= arrText[i]->getPosition().y && mousePosY <= arrText[i]->getPosition().y + 40) {
				return i;
			}
		}
	}
	return 4;
}

void MenuUpdater::fillText(int textIndex)
{
	textColor.r = 0;
	textColor.g = 255;
	textColor.b = 191;
	arrText[textIndex]->setColor(textColor);
}
