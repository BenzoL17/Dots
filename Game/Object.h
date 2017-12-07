#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "PlayerManager.h"

#define BOX_SIZE 40


enum {
	LEFT,
	TOP,
	RIGHT,
	BOTTOM
};


class Line {
private:
	sf::RectangleShape lineRect;
	sf::Vector2f size;
	sf::Vector2f position;
	sf::Color color;
	bool filled;// = false;
	void fillColor();
public:
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	sf::RectangleShape getLine();
	sf::Vector2f getLeftBottomPosition();
	sf::Vector2f getLeftTopPosition();
	sf::Vector2f getRightTopPosition();
	sf::Vector2f getRightBottomPosition();

	bool getFilledState();
	void setFilled();
	void setTransparentFilled();
	void resetTransparentFilled();
	void setPosition(sf::Vector2f pos);
	void setSize(sf::Vector2f s);
	Line(/*int sideOfLine, int PosX, int posY*/);
	~Line() {};
};


class Box {
private:
	sf::RectangleShape Rect;
	sf::Vector2f size;
	sf::Vector2f position;
	sf::Color color;
	bool filled;// = false;
	
	
	void initLine();
	void initLinePosition();
	void initLineSize();
	void fillColor();
	
public:
	Line *line[4];
	Line temp;
	Box();
	Box(int posX, int posY);
	~Box() {
		
	}
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	sf::Vector2f getLeftBottomPosition();
	sf::Vector2f getLeftTopPosition();
	sf::Vector2f getRightTopPosition();
	sf::Vector2f getRightBottomPosition();

	//Line Pos
	sf::Vector2f getLineLeftBottomPosition(int sideOfLine);
	sf::Vector2f getLineLeftTopPosition(int sideOfLine);
	sf::Vector2f getLineRightTopPosition(int sideOfLine);
	sf::Vector2f getLineRightBottomPosition(int sideOfLine);

	sf::Vector2f getLineTopPos(int sideLine);
	sf::Vector2f getLineBottomPos(int sideLine);

	sf::RectangleShape getRect();
	bool getFilledState();
	bool checkFilledState();

	void setTransparentFilledLine(int side);
	void resetTransparentFilledLine(int side);

	sf::RectangleShape getLine(int sideOfLine);
	bool getLineFilledState(int sideOfLine);
	void setLineFilled(int sideOfLine);
};


class Circle {
public:
	Circle(float rad, sf::Vector2f pos, bool enableCenterPos);
	~Circle();
	sf::CircleShape circle;
	sf::Vector2f position;
	sf::Color color;
	float radius;
private:
	sf::Vector2f calcCenterPos(sf::Vector2f pos);
};

