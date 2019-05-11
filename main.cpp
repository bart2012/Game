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
	Camera camera;
	Game game(world);
	Menu menu(window, "1");
	b2Timer time;
	while (window.isOpen())
	{
		std::cout << std::endl;
		std::cout << time.GetMilliseconds();
		std::cout << std::endl;
		Event e;
		while (window.pollEvent(e));
		{
			if (e.type == Event::Closed)
				window.close();
		}
		game.logic(world);
		world.Step(1 / 60.f, 8, 3);
		time.Reset();
		/*if (Mouse::isButtonPressed(Mouse::Left))
			std::cout << "1";*/
		//menu.kliled(window);
		//menu.draw(window);
		camera.draw(world, window, game.level);
	}
	return 0;
}