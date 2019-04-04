#pragma once
#include <SFML/Graphics.hpp>
#include"Box2D/Box2D.h"
#include <vector>
#include "Coins.h";
#include"Ground.h"
using namespace sf;
class Location
{
public:
	int raxynok = 0;
	std::vector<Coins> coins;
	std::vector<Ground> ground;
	Location(b2World &world,int location);
	void loc_update(b2World &world, Player &player);
	~Location();
};

