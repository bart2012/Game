#ifndef CAMERA_H
#define CAMERA_H
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include <iostream>
#include <vector>
#include "Level.h"
using namespace sf;
class Camera
{
public:
	Texture tGround, tCoins, tPlatform, tRocket, tFGoru,tFPlanet,tFStars,tFpolosky,tStina,tFGoruPid,tFGoruSpusk,tSpusk,tPid;
	Camera();
	void draw(b2World &world, RenderWindow &window, Level *level);
	~Camera();
private:
	double m = 30.f;
	float offsetX = 0;
	float offsetY = 0;
	Sprite sCoins, sGround,sPlatform, sRocket, sStar, sMountain, sLocation, sFGoru, sFPlanet, sFStars, sFpolosky, sStina, sFGoruPid, sFGoruSpusk, sSpusk, sPid;
};

#endif


