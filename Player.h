#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include"Box2D/Box2D.h"
#include <iostream>

using namespace sf;

class Player
{
public:
	Player(b2World &world, FloatRect rect, float x, float y);
	void move();
	bool canJump();
	void setDirectionRight();
	void setDirectionLeft();
	bool directionRignt();
	bool directionLeft();
	void jump();
	void goRight();
	void goLeft();
	void gorisontalMoveStop();
	void setSpriteKickback();
	void setAnimationCadr();
	Sprite* sprite();
	b2Body* b2body();
	~Player();
private:
	bool _directionRight;
	Sprite _sPlayer;
	FloatRect _rect;
	Texture _tPlayer;
	b2Body *_b2Player;
	double _speed;
	double _speedUp;
	double _speedAnimation;
	double _numberCadr;
	float scale = 30;
	int kilkist_cadriv;
	void createb2Body(b2World &world, float x, float y);
	void createGrafic(float x, float y);
	std::string pl = "pverx";
	std::string pl2 = "pdown";
};


#endif
