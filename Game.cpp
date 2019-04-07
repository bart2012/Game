#include "Game.h"



Game::Game()
{
}

void Game::keyPressed(Level *level)
{
	b2Vec2 vecspeed = level->player->b2Player->GetLinearVelocity();
	//std::cout <<"s "<<"  "<< vecspeed.x << "  " << vecspeed.y << std::endl;
	if (Keyboard::isKeyPressed(Keyboard::D))
		level->player->dx = level->player->speed;
	if (Keyboard::isKeyPressed(Keyboard::A))
		level->player->dx = - level->player->speed;
	//	b2Vec2 vecspeed = b2Player->GetLinearVelocity();
	if (vecspeed.y < 0 && (vecspeed.y > -0.0001))
		vecspeed.y = 0;
	if (Keyboard::isKeyPressed(Keyboard::W) && vecspeed.y == 0)
	{
		level->player->dy = level->player->speed_up;
	}
		if (!Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A))
			level->player->b2Player->SetLinearVelocity(b2Vec2(0, vecspeed.y));
	if (level->player->dx != 0 || level->player->dy != 0)
		level->player->move();
}

void Game::logic(b2World &world, Level *level)
{
	keyPressed(level);
	logicCoin(world, level);
	logicMoveLPlatrotm(world, level);
	logicYama(world, level);

}

void Game::logicCoin(b2World &world,Level *level)
{
	for (b2ContactEdge *ContactList = level->player->b2Player->GetContactList(); ContactList != nullptr; ContactList = ContactList->next)
	{
		for (int i = 0; i < level->coins.size(); i++)
		{
			if (ContactList->other == level->coins[i].b2Coins)
			{
				world.DestroyBody(level->coins[i].b2Coins);
				score += 100;
				std::cout << score << std::endl;
				level->coins.erase(level->coins.begin() + i);
				i--;
				ContactList = level->player->b2Player->GetContactList();
				break;
			}
		}
		if (ContactList == nullptr)
			break;
	}
}

void Game::logicMoveLPlatrotm(b2World &world, Level *level)
{
	for (int i = 0; i < level->ground.size(); i++)
	{
		if (level->ground[i].number == 3)
		{
			b2Vec2 pos = level->ground[i].b2Body->GetPosition();
			if (level->ground[i].vector == 'v' && (pos.y*m - level->ground[i].rect.height / 2.f <= level->ground[i].t1 || pos.y*m + level->ground[i].rect.height / 2.f >= level->ground[i].t2))
			{
				b2Vec2  Velocity = level->ground[i].b2Body->GetLinearVelocity();
				level->ground[i].b2Body->SetLinearVelocity(-Velocity);
			}
			if (level->ground[i].vector == 'b' && (pos.x*m - level->ground[i].rect.width / 2.f <= level->ground[i].t1 || pos.x*m + level->ground[i].rect.width / 2.f >= level->ground[i].t2))
			{
				b2Vec2  Velocity = level->ground[i].b2Body->GetLinearVelocity();
				level->ground[i].b2Body->SetLinearVelocity(-Velocity);
			}

			//b2Vec2 speed = level->ground[i].b2Body->GetLinearVelocity();
			//b2Vec2 speed2 = level->player->b2Player->GetLinearVelocity();
			for (b2ContactEdge *ContactList = level->ground[i].b2Body->GetContactList(); ContactList != nullptr; ContactList = ContactList->next)
			{
				if (ContactList->other == level->player->b2Player)
				{
					ContactList->contact->SetFriction(10);
					//level->player->b2Player->SetLinearVelocity(b2Vec2(speed.x + speed2.x, 0));
				}
			}
		}
	}

}

void Game::logicYama(b2World &world, Level *level)
{
	for (int i = 0; i < level->ground.size(); i++)
	{
		if (level->ground[i].number == 7)
			for (b2ContactEdge *ContactList = level->ground[i].b2Body->GetContactList(); ContactList != nullptr; ContactList = ContactList->next)
				if (ContactList->other == level->player->b2Player)
				{
					std::cout << "vse pogano" << std::endl;
					level->player->b2Player->SetTransform(b2Vec2(0, 0), 0);
				}
	}
}

Game::~Game()
{
}
