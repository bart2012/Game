#include "Bullet.h"



Bullet::Bullet(b2World &world,char direction, b2Vec2 position, std::string type):direction(direction)
{
	b2BodyDef b2Def;
	b2Def.position.Set(position.x, position.y);
	b2Def.type = b2_kinematicBody;
	b2Bullet = world.CreateBody(&b2Def);
	b2PolygonShape b2Shape;
	b2Shape.SetAsBox(7 / scale, 3 / scale);
	b2FixtureDef b2Fix;
	b2Fix.isSensor = true;
	b2Fix.density = 1.0;
	b2Fix.shape = &b2Shape;
	b2Bullet->CreateFixture(&b2Fix);
	if (direction == 'r')
	{
		b2Bullet->SetLinearVelocity(b2Vec2(1, 0));
	}
	if (direction == 'l')
	{
		std::cout << "1";
		b2Bullet->SetLinearVelocity(b2Vec2(-1, 0));
	}
}


Bullet::~Bullet()
{
}
