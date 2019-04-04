#include "Location.h"



Location::Location(b2World &world,int location)
{
	if (location == 1)
	{
		coins.push_back(Coins(world, 400, 500));
		coins.push_back(Coins(world, 600, 500));
		coins.push_back(Coins(world, 800, 500));
		coins.push_back(Coins(world, 1000, 500));
		ground.push_back(Ground(world, FloatRect(0, 625, 1366, 111), 1));
		ground.push_back(Ground(world, FloatRect(1366, 625, 1366, 111), 1));
		ground.push_back(Ground(world, FloatRect(1366, 425, 121, 39), 2));
		ground.push_back(Ground(world, FloatRect(1566, 325, 121, 39), 2));
		ground.push_back(Ground(world, FloatRect(1966, 325, 121, 39), 3, 1766, 2166, 'b'));
		ground.push_back(Ground(world, FloatRect(1166, 325, 121, 39), 3, 125, 425, 'v'));
		ground.push_back(Ground(world, FloatRect(-405, 120, 405, 755), 4));
		ground.push_back(Ground(world, FloatRect(2712, 225, 1298, 1158), 5));
		ground.push_back(Ground(world, FloatRect(4010, 120, 1298, 1158), 6));
		ground.push_back(Ground(world, FloatRect(-705, 120, 300, 10), 7));
	}

}

void Location::loc_update(b2World &world, Player &player)
{
	for (int i = 0; i < coins.size(); i++)
	{
		for (b2ContactEdge *c = coins[i].b2Coins->GetContactList(); c != nullptr; c = c->next)
			if (c->other == player.b2Player)
			{
				raxynok += 100;
				std::cout << raxynok << std::endl;
				coins.erase(coins.begin() + i);
				i--;
			}
	}
	for (int i = 0; i < ground.size(); i++)
	{
		if (ground[i].number == 7)
			for (b2ContactEdge *c = ground[i].b2Element->GetContactList(); c != nullptr; c = c->next)
				if (c->other == player.b2Player)
				{
					std::cout << "vse pogano" << std::endl;
					player.b2Player->SetTransform(b2Vec2(0, 0), 0);
				}
	}

	ground[4].moveLPlatform();
	ground[5].moveLPlatform();
	ground[4].isToush(world, player);
}

Location::~Location()
{
}
