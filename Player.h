#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include"Box2D/Box2D.h"
#include <iostream>
using namespace sf;
class Player
{
public:
	Texture tPlayer;
	Player(b2World &world, FloatRect rect, double x, double y);
	std::string pl = "player";
	FloatRect rect;
	Sprite sPlayer;
	b2Body *b2Player;
	double x = 0;
	double y{ 1 };
	double dx;
	double dy;
	double speed;
	double speed_up;
	void move();
	~Player();
private:
	double speed_animation;
	double number_cadr;
	double  m = 30.f;
	int kilkist_cadriv;
};


#endif
