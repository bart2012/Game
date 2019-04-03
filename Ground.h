#pragma once
#include "Box2D\Box2D.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Player.h"
using namespace sf;
class Ground
{
public:
	Ground(b2World &world, FloatRect rect, int number);
	Ground(b2World &world, FloatRect rect, int number, int t1, int t2, char vector);
	void moveLPlatform();
	~Ground();
	int number;
	int t1;
	int t2;
	char vector;
	b2Body *b2Element;
	FloatRect rect;
	std::string platform = "LPlatform";
	void isToush(b2World &world,Player &player);
private:
	double  m = 30;
};
