#include "Player.h"

Player::Player(b2World &world, FloatRect rect,double x,double y):x(x),y(y), rect(rect)
{
	dx = 0;
	dy = 0;
	speed = 5;
	speed_up = -10;
	speed_animation = 0.02;
	kilkist_cadriv = 6;
	number_cadr = 0;
	tPlayer.loadFromFile("D:/Game/character/all.png");
	sPlayer.setTexture(tPlayer);
	sPlayer.setTextureRect(IntRect(rect));
	sPlayer.setPosition(x, y);
	sPlayer.setOrigin(rect.width / 2.f, rect.height / 2.f);
	b2BodyDef b2DefPlayer;
	b2DefPlayer.fixedRotation = true;
	b2DefPlayer.type = b2_dynamicBody;
	//b2DefPlayer.linearDamping = 0.1;
	b2DefPlayer.position.Set(x / m, y / m);
	b2Player = world.CreateBody(&b2DefPlayer);
	b2PolygonShape b2ShapePlayerP;
	b2ShapePlayerP.SetAsBox(rect.width / 2.f / m, rect.height / 2.f / m);
	b2FixtureDef b2FixPlayer;
	b2FixPlayer.density = 1.0;
	b2FixPlayer.friction = 0.3;
	b2FixPlayer.shape = &b2ShapePlayerP;
	b2Player->CreateFixture(&b2FixPlayer);
	b2Player->SetUserData(&pl);
}


void Player::move()
{
	b2Vec2 vecspeed = b2Player->GetLinearVelocity();
	if (dy < 0)
	{
		b2Player->SetLinearVelocity(b2Vec2(vecspeed.x,speed_up));
		dy = 0;
	}
	if (dx != 0)
	{
		b2Vec2 vecspeed = b2Player->GetLinearVelocity();
		if (vecspeed.x<3&& vecspeed.x > 3)
		b2Player->SetLinearVelocity(b2Vec2(vecspeed.x + dx, vecspeed.y));
		else 
			b2Player->SetLinearVelocity(b2Vec2(dx, vecspeed.y));
		//b2Player->SetAngularDamping(dx, vecspeed.y);
		//b2Player->ApplyLinearImpulseToCenter(b2Vec2(dx, vecspeed.y), true);
		number_cadr += speed_animation;
		if (number_cadr > kilkist_cadriv)
			number_cadr = 0;
		if (dx > 0)
			sPlayer.setTextureRect(IntRect(rect.width*int(number_cadr), rect.top, rect.width, rect.height));
		else
			sPlayer.setTextureRect(IntRect(rect.width*int(number_cadr+1), rect.top, -rect.width, rect.height));
		dx = 0;
	}


}

Player::~Player()
{
}
