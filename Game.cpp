#include "Game.h"
#include "doublenumberssupport.h"

Game::Game(b2World &world)
{
	level = new Level(world, 1);
}

void Game::keyPressed()
{
	b2Vec2 vecSpeed = level->player->b2Player->GetLinearVelocity();
	//std::cout <<"s "<<"  "<< vecspeed.x << "  " << vecspeed.y << std::endl;
	if (Keyboard::isKeyPressed(Keyboard::D))
		level->player->dx = level->player->speed;
	if (Keyboard::isKeyPressed(Keyboard::A))
		level->player->dx = - level->player->speed;
	//	b2Vec2 vecspeed = b2Player->GetLinearVelocity();
	//if (vecspeed.y < 0 && (vecspeed.y > -0.0001))
	//	vecspeed.y = 0;
	if (Keyboard::isKeyPressed(Keyboard::W) && DoubleCompare::doubleEquals(0, vecSpeed.y))
	{
		level->player->dy = level->player->speed_up;
	}
		if (!Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A))
			level->player->b2Player->SetLinearVelocity(b2Vec2(0, vecSpeed.y));
	if (!DoubleCompare::fuzzyIsNull(level->player->dx) || !DoubleCompare::fuzzyIsNull(level->player->dy))
		level->player->move();
}

void Game::logic(b2World &world)
{
	keyPressed();
	logicCoin(world);
	logicMoveLPlatrotm();
	logicChasm();
}

void Game::logicCoin(b2World &world)
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
			b2Vec2 playerSpeed = level->player->b2Player->GetLinearVelocity();
			for (b2ContactEdge *ContactList = level->ground[i].b2Body->GetContactList(); ContactList != nullptr; ContactList = ContactList->next)
			{
				if (ContactList->other == level->player->b2Player)
				{
					//ContactList->contact->SetFriction(10);
					level->player->b2Player->SetLinearVelocity(b2Vec2(platformSpeed.x + playerSpeed.x, playerSpeed.y));
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
				if (ContactList->other == level->player->b2Player)
				{
					std::cout << "You lossss" << std::endl;
					level->player->b2Player->SetTransform(b2Vec2(0, 0), 0);
				}
	}
}

Game::~Game()
{
}
