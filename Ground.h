#ifndef GROUND_H
#define GROUND_H
#include "Box2D\Box2D.h"
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
class Ground
{
public:
	Ground(b2World &world, FloatRect rect, int number);
	Ground(b2World &world, FloatRect rect, int number, int t1, int t2, char vector);
	~Ground();
	int number;
	int t1;
	int t2;
	char vector;
	b2Body *b2Body;
	FloatRect rect;
	std::string platform = "LPlatform";
private:
	double  m = 30;
};

#endif
