#include "Game.h"
//#include "doublenumberssupport.h"


Game::Game(b2World &world)
{
	level = new Level(world, 1);
}

void Game::keyPressed(b2World &world)
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		level->player->goRight();
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		level->player->goLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::Space) && level->player->canJump())
	{
		level->player->jump();
	}
	if (!Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A))
	{
		level->player->gorisontalMoveStop();
	}
	//if (!DoubleCompare::fuzzyIsNull(level->player->dx) || !DoubleCompare::fuzzyIsNull(level->player->dy))
	////if(level->player->dx!=0|| level->player->dy!=0)
	//{
	//	level->player->move();
	//}

	//if (Keyboard::isKeyPressed(Keyboard::RControl)&&canShoot)
	//{
	//	level->bullet.push_back(Bullet(world,level->player->direction,level->player->_b2Player->GetPosition(),"q"));
	//	canShoot = false;
	//}
	//if (!canShoot&&!Keyboard::isKeyPressed(Keyboard::RControl))
	//{
	//	canShoot = true;
	//}
}

void Game::logic(b2World &world)
{
	keyPressed(world);
	logicCoin(world);
	logicMoveLPlatrotm();
	logicChasm();
}

void Game::logicCoin(b2World &world)
{
	for (b2ContactEdge *ContactList = level->player->b2body()->GetContactList(); ContactList != nullptr; ContactList = ContactList->next)
	{
		for (int i = 0; i < level->coins.size(); i++)
		{
			if (ContactList->other == level->coins[i].b2Coins&&ContactList->contact->IsTouching())
			{
				world.DestroyBody(level->coins[i].b2Coins);
				score += 100;
				std::cout << score << std::endl;
				level->coins.erase(level->coins.begin() + i);
				i--;
				ContactList = level->player->b2body()->GetContactList();
				break;
			}
		}
		if (ContactList == nullptr)
			break;
	}
}

void Game::logicMoveLPlatrotm()
{
	for (int i = 0; i < level->ground.size(); i++)
	{
		if (level->ground[i].number == 3)
		{
			b2Vec2 pos = level->ground[i].b2Body->GetPosition();
			if (level->ground[i].vector == 'v' && (pos.y*scale - level->ground[i].rect.height / 2.f <= level->ground[i].t1 || pos.y*scale + level->ground[i].rect.height / 2.f >= level->ground[i].t2))
			{
				b2Vec2  Velocity = level->ground[i].b2Body->GetLinearVelocity();
				level->ground[i].b2Body->SetLinearVelocity(-Velocity);
			}
			if (level->ground[i].vector == 'b' && (pos.x*scale - level->ground[i].rect.width / 2.f <= level->ground[i].t1 || pos.x*scale + level->ground[i].rect.width / 2.f >= level->ground[i].t2))
			{
				b2Vec2  Velocity = level->ground[i].b2Body->GetLinearVelocity();
				level->ground[i].b2Body->SetLinearVelocity(-Velocity);
			}

			b2Vec2 platformSpeed = level->ground[i].b2Body->GetLinearVelocity();
			b2Vec2 playerSpeed = level->player->b2body()->GetLinearVelocity();
			for (b2ContactEdge *ContactList = level->ground[i].b2Body->GetContactList(); ContactList != nullptr; ContactList = ContactList->next)
			{
				if (ContactList->other == level->player->b2body())
				{
					//ContactList->contact->SetFriction(10);
					//level->player->b2Player->SetLinearVelocity(b2Vec2(platformSpeed.x + playerSpeed.x, playerSpeed.y));
				}
			}
		}
	}

}

void Game::logicChasm()
{
	for (int i = 0; i < level->ground.size(); i++)
	{
		if (level->ground[i].number == 7)
			for (b2ContactEdge *ContactList = level->ground[i].b2Body->GetContactList(); ContactList != nullptr; ContactList = ContactList->next)
				if (ContactList->other == level->player->b2body())
				{
					std::cout << "You lossss" << std::endl;
					level->player->b2body()->SetTransform(b2Vec2(0, 0), 0);
				}
	}
}

void Game::logicBullet(b2World &world)
{
	for (int i = 0; i < level->bullet.size(); i++)
	{

	}
}

Game::~Game()
{
}
