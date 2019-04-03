#pragma once
#include <SFML/Graphics.hpp>
#include"Box2D/Box2D.h"
using namespace sf;
class Location
{
public:
	Texture tGround, tMCoins, tPlatform, tRocket, tStar, tMountain, tLocation, tPlayer;
	Location(int location);
	~Location();
};

