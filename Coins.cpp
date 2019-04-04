#include "Coins.h"



Coins::Coins(b2World &world, double x, double y):x(x),y(y)
{
	b2BodyDef b2DefCoins;
	b2DefCoins.position.Set(x /m, y /m);
	b2CircleShape b2ShapeCoins;
	b2ShapeCoins.m_radius = 22/m;
	b2FixtureDef b2FixCoins;
	b2FixtureDef b2FixCoins1;
	b2FixCoins.isSensor = true;
	b2FixCoins.density = 0;
	b2FixCoins.shape = &b2ShapeCoins;
	b2Coins = world.CreateBody(&b2DefCoins);
	b2Coins->CreateFixture(&b2FixCoins);
	//b2Coins->SetUserData(&p);
}


Coins::~Coins()
{
}
