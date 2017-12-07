#include "EndSceneupdater.h"
#include "PlayerManager.h"
#include "Loader.h"

EndSceneupdater::EndSceneupdater()
{
}


EndSceneupdater::~EndSceneupdater()
{
}

void EndSceneupdater::init()
{
	playerBox = new sf::RectangleShape();
	backToMenuBox  = new sf::RectangleShape();
	backgroundTexture = new sf::Texture();
	size = new sf::Vector2f();

	background = new sf::Sprite();
	textColor = new sf::Color();
	backToMenuColor = new sf::Color();

	arrTextScore[0] = new sf::Text();
	arrTextScore[1] = new sf::Text();
	arrTextScore[2] = new sf::Text();
	if (PlayerManager::getInstance()->getPlayerNumber() != playerNumber::FIRST)
		PlayerManager::getInstance()->setOppositePlayer();
	score = PlayerManager::getInstance()->getPlayerScore();
	playerBox->setPosition(50, 130);
	size->x = 250;
	size->y = 50;
	playerBox->setSize(*size);
	backToMenuBox->setPosition(264, 470);
	size->x = 323;
	size->y = 45;
	backToMenuBox->setSize(*size);
	if (score > 50) {
		*backgroundTexture = Loader::getInstance()->getTexture(textureName::END_BACKGROUND_FIRST);
		*textColor = PlayerManager::getInstance()->getPlayerColor();
		textColor->a = 255;
		playerBox->setFillColor(*textColor);
		setTextScore();
	}
	else if (score < 50) {
		PlayerManager::getInstance()->setOppositePlayer();
		*backgroundTexture = Loader::getInstance()->getTexture(textureName::END_BACKGROUND_SECOND);
		score = PlayerManager::getInstance()->getPlayerScore();
		*textColor = PlayerManager::getInstance()->getPlayerColor();
		textColor->a = 255;
		playerBox->setFillColor(*textColor);
		setTextScore();
	}
	else { //draw
		*backgroundTexture = Loader::getInstance()->getTexture(textureName::END_BACKGROUND_DRAW);
		arrTextScore[0] = nullptr;
		arrTextScore[1] = nullptr;
		arrTextScore[2] = nullptr;

	}
	background->setTexture(*backgroundTexture);
	background->setTextureRect(sf::IntRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	backToMenuColor->a = 255;
	backToMenuColor->r = 128;
	backToMenuColor->g = 128;
	backToMenuColor->b = 128;
	backToMenuBox->setFillColor(*backToMenuColor);
}

sf::Text * EndSceneupdater::getScore(int scoreIndex)
{
	return arrTextScore[scoreIndex];
}

sf::Sprite & EndSceneupdater::getBackground()
{
	return *background;
}

sf::RectangleShape & EndSceneupdater::getPlayerBox()
{
	return *playerBox;
}

sf::RectangleShape & EndSceneupdater::getBackToMenuBox()
{
	return *backToMenuBox;
}

void EndSceneupdater::update(int mousePosX, int mousePosY)
{

	if (isInArea(mousePosX, mousePosY)) {
		fillText();
	}
	else {
		backToMenuColor->a = 255;
		backToMenuColor->r = 128;
		backToMenuColor->g = 128;
		backToMenuColor->b = 128;
		backToMenuBox->setFillColor(*backToMenuColor);
	}

}

void EndSceneupdater::unload()
{
	for (int i = 0; i < 3; i++)
	{
		delete arrTextScore[i];
	}
	delete background;
	delete backToMenuBox;
	delete backToMenuColor;
	delete backgroundTexture;
	delete textColor;
	delete playerBox;
	delete size;
}

void EndSceneupdater::setTextScore()
{
	arrTextScore[0] = new sf::Text();
	arrTextScore[1] = new sf::Text();
	arrTextScore[2] = new sf::Text();
	arrTextScore[0]->setFont(Loader::getInstance()->getFont(fontName::HARNGTON));
	arrTextScore[1]->setFont(Loader::getInstance()->getFont(fontName::HARNGTON));
	arrTextScore[2]->setFont(Loader::getInstance()->getFont(fontName::HARNGTON));
	arrTextScore[0]->setStyle(sf::Text::Bold);
	arrTextScore[1]->setStyle(sf::Text::Bold);
	arrTextScore[2]->setStyle(sf::Text::Bold);
	arrTextScore[0]->setPosition(100, 360);
	arrTextScore[1]->setPosition(142, 360);
	arrTextScore[2]->setPosition(185, 360);
	arrTextScore[0]->setCharacterSize(50);
	arrTextScore[1]->setCharacterSize(50);
	arrTextScore[2]->setCharacterSize(50);
	arrTextScore[0]->setColor(*textColor);
	arrTextScore[1]->setColor(*textColor);
	arrTextScore[2]->setColor(*textColor);
	if (score == 100) {
		arrTextScore[0]->setString("1");
		arrTextScore[1]->setString("0");
		arrTextScore[2]->setString("0");
	}
	else {
		arrTextScore[0]->setString("0");
		std::to_string(score % 10);
		arrTextScore[1]->setString(std::to_string((score - (score % 10)) / 10));
		arrTextScore[2]->setString(std::to_string(score % 10));
	}
}

bool EndSceneupdater::isInArea(int mousePosX, int mousePosY)
{
	if (mousePosX >= backToMenuBox->getPosition().x && mousePosX <= backToMenuBox->getPosition().x + backToMenuBox->getSize().x) {
		if (mousePosY >= backToMenuBox->getPosition().y && mousePosY <= backToMenuBox->getPosition().y + backToMenuBox->getSize().y) {
			return true;
		}
	}
	return false;
}

void EndSceneupdater::boxClicked(int mousePosX, int mousePosY)
{
	if (isInArea(mousePosX, mousePosY))
		ScreenManager::getInstance()->setScreen(screenType::MENU);
}

void EndSceneupdater::fillText()
{	
	backToMenuColor->a = 255;
	backToMenuColor->r = 0;
	backToMenuColor->g = 255;
	backToMenuColor->b = 191;
	backToMenuBox->setFillColor(*backToMenuColor);
}
