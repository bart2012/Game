#ifndef COINS_H
#define COINS_H
#include  "Box2D/Box2D.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Coins
{
public:
	b2Body *b2Coins;
	double  m = 30;
	double x;
	double y;
	std::string p = "coin";
	Coins(b2World &world, double x, double y);
	~Coins();
private:
};

#endif

