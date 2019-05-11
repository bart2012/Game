#include "Player.h"
#include "doublenumberssupport.h"

Player::Player(b2World &world, FloatRect rect,float x, float y, float width):_rect(rect), _width(width)
{
	_speed = 5;
	_speedUp = -9;
	_speedAnimation = 0.02;
	_kilkistCadriv = 6;
	_numberCadr = 0;
	createb2Body(world,x,y);
	createGrafic(x,y);
}

void Player::createb2Body(b2World &world, float x, float y)
{
	b2BodyDef b2DefPlayer;
	b2DefPlayer.fixedRotation = true;
	b2DefPlayer.type = b2_dynamicBody;
	b2DefPlayer.position.Set(x / scale, y / scale);
	_b2Player = world.CreateBody(&b2DefPlayer);
	b2PolygonShape b2ShapePlayerP;
	b2ShapePlayerP.SetAsBox(_width / 2.f / scale, (_rect.height / 2.f - 10)/ scale,b2Vec2(0,10 / scale),0);
	b2FixtureDef b2FixPlayer;
	b2FixPlayer.density = 1.0f;
	b2FixPlayer.friction = 0.1f;
	b2FixPlayer.userData = &pl2;
	b2FixPlayer.shape = &b2ShapePlayerP;
	b2PolygonShape b2ShapePlayerP2;
	b2ShapePlayerP2.SetAsBox(_width / 2.f / scale, 10 / scale,b2Vec2(0,-(_rect.height/2.f - 10) / scale),0);
	b2FixtureDef b2FixPlayer2;
	b2FixPlayer2.density = 1.0f;
	b2FixPlayer2.friction = 0.1f;
	b2FixPlayer2.userData = &pl;
	b2FixPlayer2.shape = &b2ShapePlayerP2;
	_b2Player->CreateFixture(&b2FixPlayer);
	_b2Player->CreateFixture(&b2FixPlayer2);
}

void Player::createGrafic(float x, float y)
{
	_tPlayer.loadFromFile("D:/Game/character/all.png");
	_sPlayer.setTexture(_tPlayer);
	_sPlayer.setTextureRect(IntRect(_rect.left,_rect.top, _width,_rect.height));
	_sPlayer.setPosition(x, y);
	_sPlayer.setOrigin(_width / 2.f, _rect.height / 2.f);
}

//void Player::move()
//{
//	b2Vec2 vecspeed = _b2Player->GetLinearVelocity();
//	if (dy < 0)
//	{
//		_b2Player->SetLinearVelocity(b2Vec2(vecspeed.x,_speedUp));
//		dy = 0;
//	}
//	if (dx != 0)
//	{
//		b2Vec2 vecspeed = _b2Player->GetLinearVelocity();
//		if (vecspeed.x<3&& vecspeed.x > 3)
//		_b2Player->SetLinearVelocity(b2Vec2(vecspeed.x + dx, vecspeed.y));
//		else 
//			_b2Player->SetLinearVelocity(b2Vec2(dx, vecspeed.y));
//		b2Player->SetAngularDamping(dx, vecspeed.y);
//		b2Player->ApplyLinearImpulseToCenter(b2Vec2(dx, vecspeed.y), true);
//		_numberCadr += _speedAnimation;
//		if (_numberCadr > kilkist_cadriv)
//			_numberCadr = 0;
//		if (dx > 0)
//			_sPlayer.setTextureRect(IntRect(_rect.width*int(_numberCadr), _rect.top, _rect.width, _rect.height));
//		else
//			_sPlayer.setTextureRect(IntRect(_rect.width*int(_numberCadr+1), _rect.top, -_rect.width, _rect.height));
//		dx = 0;
//	}
//
//
//}

bool Player::canJump()
{
	b2Vec2 speed = _b2Player->GetLinearVelocity();
	//std::cout << speed.y << std::endl;
	b2ContactEdge *contactList = _b2Player->GetContactList();
		//std::string str = "LPlatform";
		//b2Vec2 speed = b2Player->GetLinearVelocity();
		//std::cout << speed.y<<std::endl;
		if (contactList != nullptr)
		{
			//std::cout << contactList->contact->GetFixtureA()->GetUserData() << "  1 " << std::endl;
			//std::cout << contactList->contact->GetFixtureB()->GetUserData() << "  2 " << std::endl;
			std::string* str1 = static_cast<std::string*> (contactList->contact->GetFixtureA()->GetUserData());
			//std::string* str2 = static_cast<std::string*> (contactList->contact->GetFixtureB()->GetUserData());
			//if (str1 != nullptr)
			//std::cout << *str1 << "  1 " << std::endl;
			//if (str2 != nullptr)
			//std::cout << *str2 << "  2 " << std::endl;
			//std::cout << contactList->contact->GetFriction()<< "  3 " << std::endl;
			if (DoubleCompare::doubleEquals(0, speed.y, 0.55) && contactList->contact->GetFixtureB()->GetUserData() != nullptr)
			{
				return true;
			}
			if (DoubleCompare::doubleEquals(0, speed.y)&& *str1=="pdown")
			{
				return true;
			}
		}
	if (contactList == nullptr)
		return false;
}

void Player::setDirectionRight() 
{
	_directionRight=true;
}
void Player::setDirectionLeft()
{
	_directionRight = false;

}
bool Player::directionRignt() const
{
	return _directionRight;
}
bool Player::directionLeft() const
{
	return !_directionRight;
}
void Player::jump()
{
	b2Vec2 vecspeed = _b2Player->GetLinearVelocity();
	_b2Player->SetLinearVelocity(b2Vec2(vecspeed.x, _speedUp));
}
void Player::goRight()
{
	setDirectionRight();
	b2Vec2 vecspeed = _b2Player->GetLinearVelocity();
	_b2Player->SetLinearVelocity(b2Vec2(_speed, vecspeed.y));
	setAnimationCadr();
	_sPlayer.setTextureRect(IntRect(_rect.width*int(_numberCadr), _rect.top, _width, _rect.height));
}

void Player::goLeft()
{
	setDirectionLeft();
	b2Vec2 vecspeed = _b2Player->GetLinearVelocity();
	_b2Player->SetLinearVelocity(b2Vec2(-_speed, vecspeed.y));
	setAnimationCadr();
	_sPlayer.setTextureRect(IntRect(_rect.width*int(_numberCadr)+ _width, _rect.top, -_width, _rect.height));
}
void Player::gorisontalMoveStop()
{
	b2Vec2 vecSpeed = _b2Player->GetLinearVelocity();
	_b2Player->SetLinearVelocity(b2Vec2(0, vecSpeed.y));
	_numberCadr = 0;
	if (directionRignt())
	{
		_sPlayer.setTextureRect(IntRect(_rect.left, _rect.top, _width, _rect.height));
	}
	if (directionLeft())
	{
		_sPlayer.setTextureRect(IntRect(_width, _rect.top, -_width, _rect.height));
	}
}
void Player::setSpriteKickback()
{

}
void Player::setAnimationCadr()
{
	_numberCadr += _speedAnimation;
	if (_numberCadr > _kilkistCadriv)
		_numberCadr = 0;
}

Sprite* Player::sprite()
{
	return &_sPlayer;
}
b2Body* Player::b2body()
{
	return _b2Player;
}

void Player::pistol(b2World &world, std::vector<Bullet> &bullet)
{
	if (time.GetMilliseconds() > 1000)
	{
		b2Vec2 position = _b2Player->GetPosition();
		if (_directionRight)
		{
			position.x += 60 / scale;
			position.y -= 38 / scale;
		}
		if (!_directionRight)
		{
			position.x -= 60 / scale;
			position.y -= 38 / scale;
		}
		bullet.push_back(Bullet(world, position, _directionRight));
		time.Reset();
	}
}

Player::~Player()
{
}
