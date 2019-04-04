#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "Player.h"
#include "Coins.h"
#include "Camera.h"
#include <conio.h>
#include <string>
#include <iostream>
#include "Location.h"
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
	double m = 30.f;
	b2Vec2 gravity(0.f, 3.f);
	b2World world(gravity);
	RenderWindow window(VideoMode(1366, 768), "Game");
	Player player(world, FloatRect(0, 227, 112, 199), 1366 / 2.f, 402);
	Camera camera;
	Location *location = new Location(world,1);
	while (window.isOpen())
	{
		world.Step(1 / 60.f, 8, 3);
		player.keyPressed();
		Event e;
		while (window.pollEvent(e));
		{
			if (e.type == Event::Closed)
				window.close();
		}
		location->loc_update(world, player);
		camera.draw(world, window, player,location->coins, location->ground);
	}
	delete location;
	return 0;
}