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
	Texture tFog,tFon,tLBullet,tRBullet, tGround, tCoins, tPlatform, tRocket, tFGoru,tFPlanet,tFStars,tFpolosky,tStina,tFGoruPid,tFGoruSpusk,tSpusk,tPid;
	Camera(int Location);
	void draw(b2World &world, RenderWindow &window, Level *level, int score);
	~Camera();
	bool display = true;
private:
	class Fon
	{
	public:
		Sprite sprite;
		float x;
		float y;
		Fon (Sprite sprite, float x, float y)
		{
			this->sprite = sprite;
			this->x = x;
			this->y = y;
			sprite.setPosition(x, y);
		}
	};
	float scale = 30;
	float offsetX = 0;
	float offsetYg = 0;
	float offsetYl = 0;
	Sprite sFog,sFon,sLBullet,sRBullet, sCoins, sGround,sPlatform, sRocket, sStar, sMountain, sLocation, sFGoru, sFPlanet, sFStars, sFpolosky, sStina, sFGoruPid, sFGoruSpusk, sSpusk, sPid;
	void moveFon(Level *level);
	std::vector <Fon>  goru;
	std::vector <Fon>  stars;
	std::vector <Fon>  polosky;
	std::vector <Fon>  fog;
	Text text;
	Font font;
	int _location;
	void setY(Level *level);
};

#endif


