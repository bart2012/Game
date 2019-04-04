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
		b2Element = world.CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(rect.width / 2.f / m, rect.height / 2.f / m);
		b2Element->CreateFixture(&b2Shape, 0);
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
		b2Element = world.CreateBody(&b2Def);
		b2Element->CreateFixture(&b2Shape, 0);
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
		b2Element = world.CreateBody(&b2Def);
		b2Element->CreateFixture(&b2Shape, 0);
	}
	if (number == 7)
	{
		b2BodyDef b2Def;
		b2Def.position.Set((rect.left + rect.width / 2.f) / m, (rect.top + rect.height / 2.f) / m);
		b2Element = world.CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(rect.width / 2.f / m, rect.height / 2.f / m);
		b2FixtureDef b2Fix;
		b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Element->CreateFixture(&b2Fix);
	}
}

Ground::Ground(b2World &world, FloatRect rect, int number, int t1, int t2, char vector) :rect(rect), number(number), t1(t1), t2(t2), vector(vector)
{
	b2BodyDef b2Def;
	b2Def.position.Set((rect.left + rect.width / 2.f) / m, (rect.top + rect.height / 2.f) / m);
	b2Def.type = b2_kinematicBody;
	b2Element = world.CreateBody(&b2Def);
	b2PolygonShape b2Shape;
	b2Shape.SetAsBox(rect.width / 2.f / m, rect.height / 2.f / m);
	b2Element->CreateFixture(&b2Shape,0);
		if (vector == 'v')
		b2Element->SetLinearVelocity(b2Vec2(0, 0.5));
	if (vector == 'b')
		b2Element->SetLinearVelocity(b2Vec2(0.5, 0));
}
void Ground::moveLPlatform()
{
	b2Vec2 pos = b2Element->GetPosition();
	if (vector == 'v'&&(pos.y*m-rect.height /2.f<=t1|| pos.y*m + rect.height / 2.f >= t2))
	{
		b2Vec2  Velocity = b2Element->GetLinearVelocity();
		b2Element->SetLinearVelocity(-Velocity);
	}
		if (vector == 'b'&&(pos.x*m - rect.width / 2.f <= t1 || pos.x*m + rect.width / 2.f >= t2))
		{
			b2Vec2  Velocity = b2Element->GetLinearVelocity();
			b2Element->SetLinearVelocity(-Velocity);
		}
}
void Ground::isToush(b2World &world,Player &player)
{
	b2Vec2 speed = b2Element->GetLinearVelocity();
	b2Vec2 speed2 = player.b2Player->GetLinearVelocity();
	for (b2ContactEdge *c = b2Element->GetContactList(); c != nullptr; c = c->next)
		if (c->other == player.b2Player && c->contact->IsTouching())
		{
			player.b2Player->SetLinearVelocity(b2Vec2(speed.x + speed2.x, 0));
		}
}

Ground::~Ground()
{
}
