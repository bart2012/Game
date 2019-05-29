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
	int level=0;
	b2World *world = nullptr;
	RenderWindow window(VideoMode(1366, 768), "Game");
	Camera *camera = nullptr;
	Game *game = nullptr;
	Menu *menu = new Menu(window, "main");
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
			if (!game->pause)
			{
				game->logic(world);
				world->Step(1 / 60.f, 8, 3);
				camera->draw(world, window, game->level, game->score);
			}
			if (game->pause&&menu == nullptr)
			{
				menu = new Menu(window, "pause");
				camera->display = false;
			}
			if (game->pause)
			{
				camera->draw(world, window, game->level, game->score);
				menu->draw(window);
				if (menu->kliked(window))
				{
					game->pause = false;
					camera->display = true;
					if (menu->ExitToMenu)
					{
						play = false;
						delete game;
						game = nullptr;
						delete world;
						world = nullptr;
					}
					delete menu; 
					menu = nullptr;
				}		
			}	
			if (game!=nullptr&&!game->game)
			{
				if (menu == nullptr)
				{
					menu = new Menu(window, "los");		
					delete game;
					game = nullptr;
					delete world;
					world = nullptr;
					play = false;
				}
			}
			if (game != nullptr&&game->theEnd(window))
			{
				menu = new Menu(window, "final");
   				menu->finalLoad(game);
				delete game;
				delete world;
				world = nullptr;
				game = nullptr;
				play = false;
			}
		}
		if (!play)
		{
			if (menu == nullptr)
			{
				menu = new Menu(window, "main");
			}
			if (menu->type == "final")
			{
				if (menu->kliked(window) && menu->ExitToMenu)
				{
					delete menu;
					menu = nullptr;
					menu = new Menu(window, "main");
				}
			}
			menu->draw(window);
			if (menu->kliked(window)&&!menu->ExitToMenu)
			{
				if (menu->type == "main")
				{
					level = menu->startLevel;
					camera = new Camera(menu->startLevel);
				}
				play = true;
				delete menu;
				menu = nullptr;
				world = new b2World(b2Vec2(0.f, 3.f));
				game = new Game(world, level);
			}

		}
		//std::cout << time.GetMilliseconds();
		time.Reset();
	}
	return 0;
}