#include "Player.h"
#include "doublenumberssupport.h"

Player::Player(b2World &world, FloatRect rect,float x, float y):x(x),y(y), rect(rect)
{
	dx = 0;
	dy = 0;
	speed = 5;
	speed_up = -9;
	speed_animation = 0.02;
	kilkist_cadriv = 6;
	number_cadr = 0;
	creatb2Body(world);
	creatGrafic();
}

void Player::creatb2Body(b2World &world)
{
	b2BodyDef b2DefPlayer;
	b2DefPlayer.fixedRotation = true;
	b2DefPlayer.type = b2_dynamicBody;
	b2DefPlayer.position.Set(x / scale, y / scale);
	b2Player = world.CreateBody(&b2DefPlayer);
	b2PolygonShape b2ShapePlayerP;
	b2ShapePlayerP.SetAsBox(rect.width / 2.f / scale, (rect.height / 2.f - 10)/ scale,b2Vec2(0,10 / scale),0);
	b2FixtureDef b2FixPlayer;
	b2FixPlayer.density = 1.0f;
	b2FixPlayer.friction = 0.1f;
	b2FixPlayer.userData = &pl2;
	b2FixPlayer.shape = &b2ShapePlayerP;
	b2PolygonShape b2ShapePlayerP2;
	b2ShapePlayerP2.SetAsBox(rect.width / 2.f / scale, 10 / scale,b2Vec2(0,-(rect.height/2.f - 10) / scale),0);
	b2FixtureDef b2FixPlayer2;
	b2FixPlayer2.density = 1.0f;
	b2FixPlayer2.friction = 0.1f;
	b2FixPlayer2.userData = &pl;
	b2FixPlayer2.shape = &b2ShapePlayerP2;
	b2Player->CreateFixture(&b2FixPlayer);
	b2Player->CreateFixture(&b2FixPlayer2);
}

void Player::creatGrafic()
{
	tPlayer.loadFromFile("D:/Game/character/all.png");
	sPlayer.setTexture(tPlayer);
	sPlayer.setTextureRect(IntRect(rect));
	sPlayer.setPosition(x, y);
	sPlayer.setOrigin(rect.width / 2.f, rect.height / 2.f);
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

void Player::OnGround()
{
	b2Vec2 speed = b2Player->GetLinearVelocity();
	//std::cout << speed.y << std::endl;
	b2ContactEdge *contactList = b2Player->GetContactList();
	if (!onGround)
	{
		//std::string str = "LPlatform";
		//b2Vec2 speed = b2Player->GetLinearVelocity();
		//std::cout << speed.y<<std::endl;
		if (contactList != nullptr)
		{
			std::cout << contactList->contact->GetFixtureA()->GetUserData() << "  1 " << std::endl;
			std::cout << contactList->contact->GetFixtureB()->GetUserData() << "  2 " << std::endl;
			std::string* str1 = static_cast<std::string*> (contactList->contact->GetFixtureA()->GetUserData());
			std::string* str2 = static_cast<std::string*> (contactList->contact->GetFixtureB()->GetUserData());
			if (str1 != nullptr)
			std::cout << *str1 << "  1 " << std::endl;
			//if (str2 != nullptr)
			//std::cout << *str2 << "  2 " << std::endl;
			//std::cout << contactList->contact->GetFriction()<< "  3 " << std::endl;
			if (DoubleCompare::doubleEquals(0, speed.y, 0.55) && contactList->contact->GetFixtureB()->GetUserData() != nullptr)
			{
				onGround = true;
			}
			if (DoubleCompare::doubleEquals(0, speed.y)&& *str1=="pdown")
			{
				onGround = true;
			}
		}
	}
	if (onGround && contactList == nullptr)
		onGround = false;
}

Player::~Player()
{
}
