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
	Camera camera;
	Game game;
	Menu menu(window, "1");
	Level *level = new Level(world,1);
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e));
		{
			if (e.type == Event::Closed)
				window.close();
		}
		world.Step(1 / 60.f, 8, 3);
		game.logic(world, level);
		/*if (Mouse::isButtonPressed(Mouse::Left))
			std::cout << "1";*/
		//menu.kliled(window);
		//menu.draw(window);
		camera.draw(world, window, level);
	}
	delete level;
	return 0;
}