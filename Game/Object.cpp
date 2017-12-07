#include "Object.h"


Box::Box() {
	size.x = BOX_SIZE;
	size.y = BOX_SIZE;
	position.x = 80;
	position.y = 120;
	filled = false;
	Rect.setPosition(position);
	Rect.setSize(size);
	color.a = 0;
	color.r = 240;
	color.g = 255;
	color.b = 255;
	Rect.setFillColor(color);
	initLine();
	initLinePosition();
	initLineSize();
}

Box::Box(int posX, int posY) {
	size.x = BOX_SIZE;
	size.y = BOX_SIZE;
	position.x = posX;
	position.y = posY;
	filled = false;
	Rect.setPosition(position);
	Rect.setSize(size);
	color.a = 0;
	color.r = 240;
	color.g = 255;
	color.b = 255;
	Rect.setFillColor(color);
	initLine();
	initLinePosition();
	initLineSize();
}

void Box::initLine()
{
	line[LEFT] = new Line();
	line[RIGHT] = new Line();
	line[TOP] = new Line();
	line[BOTTOM] = new Line();

}

void Box::initLinePosition()
{
	line[LEFT]->setPosition(getLineTopPos(LEFT));
	line[TOP]->setPosition(getLineTopPos(TOP));
	line[RIGHT]->setPosition(getLineTopPos(RIGHT));
	line[BOTTOM]->setPosition(getLineTopPos(BOTTOM));
}

void Box::initLineSize()
{
	line[LEFT]->setSize(getLineBottomPos(LEFT) - getLineTopPos(LEFT));
	line[TOP]->setSize(getLineBottomPos(TOP) - getLineTopPos(TOP));
	line[RIGHT]->setSize(getLineBottomPos(RIGHT) - getLineTopPos(RIGHT));
	line[BOTTOM]->setSize(getLineBottomPos(BOTTOM) - getLineTopPos(BOTTOM));
}

void Box::fillColor() {
	filled = true;
	Rect.setFillColor(PlayerManager::getInstance()->getPlayerColor());
}

sf::Vector2f Box::getLineTopPos(int sideLine)
{
	sf::Vector2f pos;
	switch (sideLine)
	{
	case LEFT: {
		pos.x = getLeftTopPosition().x - 3;
		pos.y = getLeftTopPosition().y + 3;
		return pos;
	}
	case TOP: {
		pos.x = getLeftTopPosition().x + 3;
		pos.y = getLeftTopPosition().y - 3;
		return pos;
	}
	case RIGHT: {
		pos.x = getRightTopPosition().x - 3;
		pos.y = getRightTopPosition().y + 3;
		return pos;
	}
	case BOTTOM: {
		pos.x = getLeftBottomPosition().x + 3;
		pos.y = getLeftBottomPosition().y - 3;
		return pos;
	}
	default:
		break;
	}
}

sf::Vector2f Box::getLineBottomPos(int sideLine)
{
	sf::Vector2f pos;
	switch (sideLine)
	{
	case LEFT: {
		pos.x = getLeftBottomPosition().x + 3;
		pos.y = getLeftBottomPosition().y - 3;
		return pos;
	}
	case TOP: {
		pos.x = getRightTopPosition().x - 3;
		pos.y = getRightTopPosition().y + 3;
		return pos;
	}
	case RIGHT: {
		pos.x = getRightBottomPosition().x + 3;
		pos.y = getRightBottomPosition().y - 3;
		return pos;
	}
	case BOTTOM: {
		pos.x = getRightBottomPosition().x - 3;
		pos.y = getRightBottomPosition().y + 3;
		return pos;
	}
	}
}


sf::Vector2f Box::getSize() { return size; }

sf::Vector2f Box::getPosition() { return position; }

#pragma region getBoxPos
sf::Vector2f Box::getLeftTopPosition() { return position; }
sf::Vector2f Box::getRightTopPosition() { sf::Vector2f pos; pos.x = position.x + BOX_SIZE; pos.y = position.y; return pos; }
sf::Vector2f Box::getLeftBottomPosition() { sf::Vector2f pos; pos.x = position.x; pos.y = position.y + BOX_SIZE; return pos; }
sf::Vector2f Box::getRightBottomPosition() { sf::Vector2f pos; pos.x = position.x + BOX_SIZE; pos.y = position.y + BOX_SIZE; return pos; }
#pragma endregion getBoxPos


#pragma region gettingLinePos
sf::Vector2f Box::getLineLeftBottomPosition(int sideOfLine){	return line[sideOfLine]->getLeftBottomPosition();}
sf::Vector2f Box::getLineLeftTopPosition(int sideOfLine){	return line[sideOfLine]->getLeftTopPosition();}
sf::Vector2f Box::getLineRightTopPosition(int sideOfLine){	return line[sideOfLine]->getRightTopPosition();}
sf::Vector2f Box::getLineRightBottomPosition(int sideOfLine){	return line[sideOfLine]->getRightBottomPosition();}
#pragma endregion gettingLinePos

sf::RectangleShape Box::getRect() {	return Rect; }

sf::RectangleShape Box::getLine(int sideOfLine)
{
	return line[sideOfLine]->getLine();
}

bool Box::getLineFilledState(int sideOfLine)
{
	return line[sideOfLine]->getFilledState();
}

void Box::setLineFilled(int sideOfLine)
{
	line[sideOfLine]->setFilled();
}

bool Box::getFilledState() { return filled; }

bool Box::checkFilledState()
{
	if (line[LEFT]->getFilledState()
		&& line[TOP]->getFilledState()
		&& line[RIGHT]->getFilledState()
		&& line[BOTTOM]->getFilledState()) {
		fillColor();
		return true;
	}
	return false;
}

void Box::setTransparentFilledLine(int side)
{
	line[side]->setTransparentFilled();
}

void Box::resetTransparentFilledLine(int side)
{
	line[side]->resetTransparentFilled();
}







Line::Line() {
	color.a = 0;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	filled = false;
	lineRect.setFillColor(color);
	/*color.r = 210;
	color.g = 10;
	color.b = 10;*/
}


sf::Vector2f Line::getPosition()
{
	return position;
}

sf::Vector2f Line::getSize()
{
	return size;
}

sf::RectangleShape Line::getLine()
{
	return this->lineRect;
}

#pragma region getLinePos
sf::Vector2f Line::getLeftBottomPosition() { sf::Vector2f pos; pos.x = position.x; pos.y = position.y + size.y; return pos; }
sf::Vector2f Line::getLeftTopPosition(){	return position;}
sf::Vector2f Line::getRightTopPosition(){ sf::Vector2f pos; 	pos.x = position.x + size.x; pos.y = position.y; 	return pos; }
sf::Vector2f Line::getRightBottomPosition() { sf::Vector2f pos; 	pos.x = position.x + size.x; pos.y = position.y + size.y; 	return pos; }
#pragma endregion getLinePos

bool Line::getFilledState()
{
	return filled;
}

void Line::setFilled()
{
	filled = true;
	color.a = 220;
	color.r = 60;
	color.g = 43;
	color.b = 43;
	lineRect.setFillColor(color);
}

void Line::setTransparentFilled()
{
	color = PlayerManager::getInstance()->getPlayerColor();
	color.a = 100;
	lineRect.setFillColor(color);
}

void Line::resetTransparentFilled()
{
	color.a = 0;
	lineRect.setFillColor(color);
}

void Line::setPosition(sf::Vector2f pos)
{
	lineRect.setPosition(pos);
}

void Line::setSize(sf::Vector2f s)
{
	lineRect.setSize(s);
}

Circle::Circle(float rad, sf::Vector2f pos, bool enableCenterPos) {
	color.a = 255;
	color.r = 0;
	color.g = 139;
	color.b = 139;
	radius = rad;
	circle.setFillColor(color);
	if (enableCenterPos) {
		position = calcCenterPos(pos);
	
	}
	else {
		position = pos;
	}
	circle.setRadius(rad);
	circle.setPosition(position);
}

Circle::~Circle(){}

sf::Vector2f Circle::calcCenterPos(sf::Vector2f pos)
{	
	pos.x -= radius;
	pos.y -= radius;
	return pos;
}
