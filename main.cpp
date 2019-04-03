#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "Player.h"
#include "Coins.h"
#include "Camera.h"
#include <conio.h>
#include <string>
#include <iostream>
//#include "Location.h"
#include "Player.h"
#include <vector>
#include "Ground.h"
using namespace sf;


// number
// 1 - Ground(1366*111)
// 2 - платформа
// 3 - літаюча платформа
// 4 - стіна
// 5 - підйом
// 6 - спуск
int main()
{
	int raxynok = 0;
	double m = 30.f;
	b2Vec2 gravity(0.f, 3.f);
	b2World world(gravity);
	std::vector<Coins> coins;
	coins.push_back(Coins(world, 400, 500));
	coins.push_back(Coins(world, 600, 500));
	coins.push_back(Coins(world, 800, 500));
	coins.push_back(Coins(world, 1000, 500));
	RenderWindow window(VideoMode(1366, 768), "Game");
	std::vector<Ground> ground;
	ground.push_back(Ground(world, FloatRect(0, 625, 1366, 111),1));
	ground.push_back(Ground(world, FloatRect(1366, 625, 1366, 111), 1));
	ground.push_back(Ground(world, FloatRect(1366, 425, 121, 39), 2));
	ground.push_back(Ground(world, FloatRect(1566, 325, 121, 39), 2));
	ground.push_back(Ground(world, FloatRect(1966, 325, 121, 39), 3,1766,2166,'b'));
	ground.push_back(Ground(world, FloatRect(1166, 325, 121, 39), 3, 125, 425, 'v'));
	ground.push_back(Ground(world, FloatRect(-405, 120, 405, 755), 4));
	ground.push_back(Ground(world, FloatRect(2712, 225, 1298, 1158), 5));
	ground.push_back(Ground(world, FloatRect(4010, 120, 1298, 1158), 6));
	Player player(world, FloatRect(0, 227, 112, 199), 1366 / 2.f, 402);
	Camera camera;
	while (window.isOpen())
	{
		world.Step(1 / 60.f, 20,10 );
		player.keyPressed();
		Event e;
		while (window.pollEvent(e));
		{
			if (e.type == Event::Closed)
				window.close();
		}




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


		ground[4].moveLPlatform();
		ground[5].moveLPlatform();
		ground[4].isToush(world,player);
		camera.draw(world, window, player,coins,ground);
	}
	return 0;
}