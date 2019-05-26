#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include <vector>
#include <conio.h>
#include <string>
#include <iostream>
#include "Level.h"
#include "Menu.h"
#include "Game.h"
#include "Camera.h"

using namespace sf;

int main()
{
	b2World world(b2Vec2(0.f,3.f));
	RenderWindow window(VideoMode(1366, 768), "Game");
	Camera *camera = nullptr;
	Game *game = nullptr;
	Menu *menu = new Menu(window, "1");
	b2Timer time;
	bool play = false;
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e));
		{
			if (e.type == Event::Closed)
				window.close();
		}
		if (play)
		{
			game->logic(world);
			world.Step(1 / 60.f, 8, 3);
			camera->draw(world, window, game->level,game->score);
		}
		if (!play)
		{
			menu->draw(window);
			if (menu->kliled(window))
			{
				play = true;
				game = new Game(world,menu->startLevel);
				camera = new Camera(menu->startLevel);
				delete menu;
			}
		}
		//std::cout << time.GetMilliseconds();
		//std::cout << std::endl;
		//std::cout << std::endl;
		//game.logic(world);
		time.Reset();
	}
	return 0;
}