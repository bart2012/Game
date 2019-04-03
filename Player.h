#pragma once
#include <SFML/Graphics.hpp>
#include"Box2D/Box2D.h"
#include <iostream>
using namespace sf;
class Player
{
public:
	void keyPressed();
	Texture tPlayer;
	Player(b2World &world, FloatRect rect, double x, double y);
	std::string pl = "player";
	FloatRect rect;
	Sprite sPlayer;
	b2Body *b2Player;
	double x = 0;
	double y{ 1 };
	~Player();
private:
	double dx;
	double dy;
	double speed;
	double speed_up;
	double speed_animation;
	double number_cadr;
	double  m = 30.f;
	int kilkist_cadriv;


	void move();
};

