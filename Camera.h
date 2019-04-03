#pragma once
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "Player.h"
//#include "Location.h"
#include <iostream>
#include "Coins.h"
#include <vector>
#include "Ground.h"
using namespace sf;
class Camera
{
public:
	Texture tGround, tCoins, tPlatform, tRocket, tFGoru,tFPlanet,tFStars,tFpolosky,tStina,tFGoruPid,tFGoruSpusk,tSpusk,tPid;
	Camera();
	void draw(b2World &world, RenderWindow &window, Player &player,std::vector<Coins> coins , std::vector<Ground> ground);
	~Camera();
private:
	double m = 30.f;
	float offsetX = 0;
	float offsetY = 0;
	Sprite sCoins, sGround,sPlatform, sRocket, sStar, sMountain, sLocation, sFGoru, sFPlanet, sFStars, sFpolosky, sStina, sFGoruPid, sFGoruSpusk, sSpusk, sPid;
};

