#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include"Box2D/Box2D.h"
#include <vector>
#include "Coins.h";
#include"Ground.h"
#include "Player.h"
using namespace sf;
class Level
{
public:
	int raxynok = 0;
	Player *player;
	std::vector<Coins> coins;
	std::vector<Ground> ground;
	Level(b2World &world,int location);
	~Level();
};

#endif
