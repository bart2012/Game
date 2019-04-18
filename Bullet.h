#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include <iostream>
class Bullet
{
public:
	b2Body *b2Bullet;
	char direction;
	Bullet(b2World &world,char direction,b2Vec2 position,std::string type);
	~Bullet();
private:
	float scale = 30;
};

#endif


