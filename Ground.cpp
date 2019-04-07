#include "Ground.h"

// number
// 1 - Ground(1366*111)
// 2 - платформа
// 3 - літаюча платформа
// 4 - стіна
// 5 - підйом
// 6 - спуск
// 7 - яма
Ground::Ground(b2World &world,FloatRect rect,int number):rect(rect),number(number)
{
	if (number == 1 || number == 2 || number == 4)
	{
		b2BodyDef b2Def;
		b2Def.position.Set((rect.left + rect.width / 2.f) / m, (rect.top + rect.height / 2.f) / m);
		b2Body = world.CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(rect.width / 2.f / m, rect.height / 2.f / m);
		b2FixtureDef b2;
		b2.density = 1.0;
		b2.friction = 0.0;
		b2.shape = &b2Shape;
		b2Body->CreateFixture(&b2);
	}
	if (number == 5)
	{
		b2BodyDef b2Def;
		b2Def.position.Set((rect.left + rect.width / 2.f) / m, (rect.top + rect.height / 2.f) / m);
		b2Vec2 vertices[4];
		vertices[0].Set(rect.width /2.f / m, -rect.height / 2.f / m);
		vertices[1].Set(-rect.width / 2.f / m, -(rect.height / 2.f - 400 ) / m);
		vertices[2].Set(rect.width / 2.f / m, rect.height / 2.f / m);
		vertices[3].Set(-rect.width / 2.f / m, rect.height / 2.f / m);
		/*vertices[0].Set(649 / m, -579 / m);
		vertices[1].Set(-649 / m, -179 / m);
		vertices[2].Set(649 / m, 579 / m);
		vertices[3].Set(-649 / m, 579 / m);*/
		b2PolygonShape b2Shape;
		b2Shape.Set(vertices, 4);
		b2Body = world.CreateBody(&b2Def);
		b2Body->CreateFixture(&b2Shape, 0);
	}
	if (number == 6)
	{
		b2BodyDef b2Def;
		b2Def.position.Set((rect.left + rect.width / 2.f) / m, (rect.top + rect.height / 2.f) / m);
		b2Vec2 vertices[4];
		vertices[0].Set(-rect.width / 2.f / m, -rect.height / 2.f / m);
		vertices[1].Set(rect.width / 2.f / m, -(rect.height / 2.f - 400) / m);
		vertices[2].Set(rect.width / 2.f / m, rect.height / 2.f / m);
		vertices[3].Set(-rect.width / 2.f / m, rect.height / 2.f / m);
		/*vertices[0].Set(649 / m, -579 / m);
		vertices[1].Set(-649 / m, -179 / m);
		vertices[2].Set(649 / m, 579 / m);
		vertices[3].Set(-649 / m, 579 / m);*/
		b2PolygonShape b2Shape;
		b2Shape.Set(vertices, 4);
		b2Body = world.CreateBody(&b2Def);
		b2Body->CreateFixture(&b2Shape, 0);
	}
	if (number == 7)
	{
		b2BodyDef b2Def;
		b2Def.position.Set((rect.left + rect.width / 2.f) / m, (rect.top + rect.height / 2.f) / m);
		b2Body = world.CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(rect.width / 2.f / m, rect.height / 2.f / m);
		b2FixtureDef b2Fix;
		b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Body->CreateFixture(&b2Fix);
	}
}

Ground::Ground(b2World &world, FloatRect rect, int number, int t1, int t2, char vector) :rect(rect), number(number), t1(t1), t2(t2), vector(vector)
{
	b2BodyDef b2Def;
	b2Def.position.Set((rect.left + rect.width / 2.f) / m, (rect.top + rect.height / 2.f) / m);
	b2Def.type = b2_kinematicBody;
	b2Body = world.CreateBody(&b2Def);
	b2PolygonShape b2Shape;
	b2Shape.SetAsBox(rect.width / 2.f / m, rect.height / 2.f / m);
	b2Body->CreateFixture(&b2Shape,0);
		if (vector == 'v')
			b2Body->SetLinearVelocity(b2Vec2(0, 0.5));
	if (vector == 'b')
		b2Body->SetLinearVelocity(b2Vec2(0.5, 0));
}



Ground::~Ground()
{
}
