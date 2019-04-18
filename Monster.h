#ifndef MONSTER_H
#define MONSTER_H
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
class Monster
{
public:
	Monster();
	sf::FloatRect rect;
	int speed;
	b2Body b2Monster;
	~Monster();
};
#endif

