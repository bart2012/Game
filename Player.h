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
	Player(b2World &world, FloatRect rect, float x, float y);
	FloatRect rect;
	Sprite sPlayer;
	b2Body *b2Player;
	float x;
	float y;
	double dx;
	double dy;
	double speed;
	double speed_up;
	void move();
	~Player();
private:
	double speed_animation;
	double number_cadr;
	float scale = 30;
	int kilkist_cadriv;
	void creatb2Body(b2World &world);
	void creatGrafic();
};


#endif
