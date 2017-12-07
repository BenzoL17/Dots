#include "GameScreenUpdater.h"


GameScreenUpdater::GameScreenUpdater()
{
}


GameScreenUpdater::~GameScreenUpdater()
{
}

void GameScreenUpdater::init()
{
	arrBox[0] = new Box();
	arrCircle[0] = new Circle(5, arrBox[0]->getPosition(), true);
	int row = 10;
	for (short int i = 1; i < 100; i++)
	{
		if (i == row) {
			row += 10;
			arrBox[i] = new Box(arrBox[i - 10]->getLeftBottomPosition().x, arrBox[i - 10]->getLeftBottomPosition().y /*+ 1*/);
		}
		else
			arrBox[i] = new Box(arrBox[i - 1]->getPosition().x + BOX_SIZE /*+ 1*/, arrBox[i - 1]->getPosition().y);
		arrCircle[i] = new Circle(5, arrBox[i]->getPosition(), true);
	}
	for (int i = 100; i < 110; i++)
	{
		arrCircle[i] = new Circle(5, arrBox[i-10]->getLeftBottomPosition(), true);
	}
	for (int i = 110; i < 120; i++)
	{
		arrCircle[i] = new Circle(5, arrBox[9 + 10 * (119 - i)]->getRightTopPosition(), true);
	}
	arrCircle[120] = new Circle(5, arrBox[99]->getRightBottomPosition(), true);

	background.setTexture(Loader::getInstance()->getTexture(textureName::GAME_BACKGROUND));
	border.setTexture(Loader::getInstance()->getTexture(textureName::GAME_BOADER));
	border.setPosition(33, 0);

	initColor();
	initText();

}

sf::RectangleShape GameScreenUpdater::getBox(int boxNumber)
{
	return arrBox[boxNumber]->getRect();
}

sf::RectangleShape GameScreenUpdater::getLine(int boxNumber, int side)
{
	return arrBox[boxNumber]->getLine(side);
}

sf::CircleShape GameScreenUpdater::getCircle(int circleNumber)
{
	return arrCircle[circleNumber]->circle;
}

sf::Text GameScreenUpdater::getScore(playerNumber number)
{

	switch (number)
	{
	case FIRST:
		return arrTextScore[0];
	case SECOND:
		return arrTextScore[1];
	}
}

sf::Text GameScreenUpdater::getTextPlayer(playerNumber number)
{
	switch (number)
	{
	case FIRST:
		return arrTextPlayer[0];
	case SECOND:
		return arrTextPlayer[1];
	}
}

sf::Sprite GameScreenUpdater::getSprite(textureName sName)
{
	switch (sName)
	{
	case GAME_BACKGROUND:
		return background;
	case GAME_BOADER:
		return border;
	}
}

void GameScreenUpdater::fillLine(int mousePosX, int mousePosY)
{
	if (isValidLine() && isValidBox()) {
		fillLine(lineSide);
		if (!isBoxGetFilled(boxNumber)) { //если не закрасили клетку, ход переходит другому игроку
			PlayerManager::getInstance()->setOppositePlayer();
			setPlayerColor(PlayerManager::getInstance()->getPlayerNumber());
		}
		else {	//закрасили, увеличиваем очки
			setTextScore();
		}
	}
}

void GameScreenUpdater::update(int mousePosX, int mousePosY)
{
	clearTransparentLine();
	if (isInArea(mousePosX, mousePosY) == true) {
		boxNumber = boxClicked(mousePosX, mousePosY);   //Получаем номер квадрата, на который кликнули
		if (boxNumber == 101)
			return;
		if (isLineClicked(mousePosX, mousePosY)) {      //если кликнули по линии, закрашиваем ее
			transparentFillLine(lineSide);
		}
	}
}

void GameScreenUpdater::unload()
{
	for (int i = 0; i < 100; i++)
	{
		delete arrBox[i];
	}
	for (int i = 0; i < 121; i++)
	{
		delete arrCircle[i];
	}
}

bool GameScreenUpdater::isInArea(int mousePosX, int mousePosY)
{
	if (mousePosX >= arrBox[0]->getLeftTopPosition().x - 3 && mousePosX <= arrBox[9]->getRightTopPosition().x + 3) {
		if (mousePosY >= arrBox[0]->getLeftTopPosition().y - 3 && mousePosY <= arrBox[99]->getRightBottomPosition().y + 3) {
			return true;
		}
	}
	else
		return false;
}

void GameScreenUpdater::initText()
{
	arrTextPlayer[0].setFont(Loader::getInstance()->getFont(fontName::HARNGTON));
	arrTextPlayer[1].setFont(Loader::getInstance()->getFont(fontName::HARNGTON));
	arrTextScore[0].setFont(Loader::getInstance()->getFont(fontName::HARNGTON));
	arrTextScore[1].setFont(Loader::getInstance()->getFont(fontName::HARNGTON));

	arrTextPlayer[0].setStyle(sf::Text::Bold);
	arrTextPlayer[1].setStyle(sf::Text::Bold);
	arrTextScore[0].setStyle(sf::Text::Bold);
	arrTextScore[1].setStyle(sf::Text::Bold);

	arrTextPlayer[0].setPosition(40, 35);
	arrTextPlayer[1].setPosition(380, 35);
	arrTextScore[0].setPosition(200, 36);
	arrTextScore[1].setPosition(328, 36);

	arrTextPlayer[0].setCharacterSize(35);
	arrTextPlayer[1].setCharacterSize(35);
	arrTextScore[0].setCharacterSize(35);
	arrTextScore[1].setCharacterSize(35);

	arrTextPlayer[0].setColor(colorNonActive);
	arrTextPlayer[1].setColor(colorNonActive);
	arrTextScore[0].setColor(colorNonActive);
	arrTextScore[1].setColor(colorNonActive);

	arrTextPlayer[0].setString("Player 1");
	arrTextPlayer[1].setString("Player 2");
	arrTextScore[0].setString("0");
	arrTextScore[1].setString("0");

	if (PlayerManager::getInstance()->getPlayerNumber() == playerNumber::FIRST) {
		arrTextPlayer[0].setColor(colorFirstPlayer);
		arrTextScore[0].setColor(colorFirstPlayer);
	}
	else {
		arrTextPlayer[1].setColor(colorSecondPlayer);
		arrTextScore[1].setColor(colorSecondPlayer);
	}
}

void GameScreenUpdater::initColor()
{
	colorNonActive.a = 255;
	colorNonActive.r = 128;
	colorNonActive.g = 128;
	colorNonActive.b = 128;
	PlayerManager::getInstance()->setPlayer(playerNumber::FIRST);
	colorFirstPlayer = PlayerManager::getInstance()->getPlayerColor();
	colorFirstPlayer.a = 210;
	PlayerManager::getInstance()->setPlayer(playerNumber::SECOND);
	colorSecondPlayer = PlayerManager::getInstance()->getPlayerColor();
	colorSecondPlayer.a = 210;
	PlayerManager::getInstance()->setOppositePlayer();
}

int GameScreenUpdater::boxClicked(int mousePosX, int mousePosY)
{
	for (short int i = 0; i < 100; i++)
	{
		if (arrBox[i]->getFilledState())
			continue;
		if (mousePosX >= arrBox[i]->getLeftTopPosition().x - 3 && mousePosX <= arrBox[i]->getRightTopPosition().x + 3) {
			if (mousePosY >= arrBox[i]->getLeftTopPosition().y - 3 && mousePosY <= arrBox[i]->getRightBottomPosition().y + 3)
				return i;
		}
	}
	return 101;
}

bool GameScreenUpdater::isLineClicked(int mousePosX, int mousePosY)
{
	for (short int i = 0; i < 4; i++)
	{
		if (arrBox[boxNumber]->getLineFilledState(i))
			continue;
		if (mousePosX >= arrBox[boxNumber]->getLineTopPos(i).x && mousePosX <= arrBox[boxNumber]->getLineBottomPos(i).x) {
			if (mousePosY >= arrBox[boxNumber]->getLineTopPos(i).y && mousePosY <= arrBox[boxNumber]->getLineBottomPos(i).y) {
				lineSide = i;
				return true;
			}
		}
	}
	lineSide = 4;
	return false;
}

void GameScreenUpdater::transparentFillLine(int side)
{
	if (!arrBox[boxNumber]->getLineFilledState(side)) {
		arrBox[boxNumber]->setTransparentFilledLine(side);
	}
}

void GameScreenUpdater::fillLine(int side)
{
	arrBox[boxNumber]->setLineFilled(side);
	fillConnected(side);
}

void GameScreenUpdater::fillConnected(int side)
{
	switch (side)
	{
	case LEFT:
		if (boxNumber % 10 == 0)
			return;
		arrBox[boxNumber - 1]->setLineFilled(RIGHT);
		break;
	case TOP:
		if (boxNumber < 10)
			return;
		arrBox[boxNumber - 10]->setLineFilled(BOTTOM);
		break;
	case RIGHT:
		if (boxNumber % 10 == 9)
			return;
		arrBox[boxNumber + 1]->setLineFilled(LEFT);
		break;
	case BOTTOM:
		if (boxNumber > 89)
			return;
		arrBox[boxNumber + 10]->setLineFilled(TOP);
		break;
	};
}

void GameScreenUpdater::setTextScore()
{	
	switch (PlayerManager::getInstance()->getPlayerNumber())
	{
	case playerNumber::FIRST:
		arrTextScore[playerNumber::FIRST].setString(std::to_string(PlayerManager::getInstance()->getPlayerScore()));
		break;
	case playerNumber::SECOND:
		arrTextScore[playerNumber::SECOND].setString(std::to_string(PlayerManager::getInstance()->getPlayerScore()));
		break;
	}
}

void GameScreenUpdater::setPlayerColor(const int player)
{

	if (player == playerNumber::FIRST) {
		arrTextPlayer[playerNumber::SECOND].setColor(colorNonActive);
		arrTextScore[playerNumber::SECOND].setColor(colorNonActive);
		arrTextPlayer[playerNumber::FIRST].setColor(colorFirstPlayer);
		arrTextScore[playerNumber::FIRST].setColor(colorFirstPlayer);
	}
	else
	{
		arrTextPlayer[playerNumber::FIRST].setColor(colorNonActive);
		arrTextScore[playerNumber::FIRST].setColor(colorNonActive);
		arrTextPlayer[playerNumber::SECOND].setColor(colorSecondPlayer);
		arrTextScore[playerNumber::SECOND].setColor(colorSecondPlayer);
	}
}

void GameScreenUpdater::clearTransparentLine()
{
	if (isValidBox() && isValidLine()) {
		if (!arrBox[boxNumber]->getLineFilledState(lineSide))
			arrBox[boxNumber]->resetTransparentFilledLine(lineSide);
	}
}

bool GameScreenUpdater::isBoxGetFilled(int number)
{
	int filledBoxes = 0;
	bool filled = false;
	for (short int i = 0; i < 100; i++)
	{
		if (arrBox[i]->getFilledState()) {
			filledBoxes++;
			continue;
		}
		if (arrBox[i]->checkFilledState()) {
			PlayerManager::getInstance()->plusScore();
			filledBoxes++;
			filled = true;
		}
	}
	if (filledBoxes == 100) {
		ScreenManager::getInstance()->setScreen(screenType::END);
	}
	return filled;
}

bool GameScreenUpdater::isValidBox()
{
	if (boxNumber >= 0 && boxNumber <= 100)
		return true;
	return false;
}

bool GameScreenUpdater::isValidBox(int boxIndex)
{
	if (boxIndex >= 0 && boxIndex <= 100)
		return true;
	return false;
}

bool GameScreenUpdater::isValidLine()
{
	if (lineSide >= 0 && lineSide <= 3)
		return true;
	return false;
}

bool GameScreenUpdater::isValidLine(int side)
{
	if (side >= 0 && side <= 3)
		return true;
	return false;
}
