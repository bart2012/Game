#include "Level.h"
#include <fstream>
// відстань монета - земля  = 125

// number
// 1 - Ground(1366*111)
// 2 - платформа
// 3 - літаюча платформа
// 4 - стіна
// 5 - підйом
// 6 - спуск
// 7 - яма
Level::Level(b2World &world,int location)
{
	struct element
	{
		int number;
		int x;
		int y;
		int dx;
		int dy;
		int t1;
		int t2;
		char vec = ' ';
	};
	std::vector <element> elements;
	//if (location == 2)
	//{
	////	player = new Player(world, FloatRect(0, 0, 112, 199), 100, 402, 103);
	////	coins.push_back(Coins(world, 400, 500));
	////	coins.push_back(Coins(world, 600, 500));
	////	coins.push_back(Coins(world, 800, 500));
	////	coins.push_back(Coins(world, 1000, 500));
	////	ground.push_back(Ground(world, FloatRect(0, 625, 1366, 111), 1));
	////	ground.push_back(Ground(world, FloatRect(-1366, 625, 1366, 111), 1));
	////	ground.push_back(Ground(world, FloatRect(0, 325, 121, 39), 2));
	////	ground.push_back(Ground(world, FloatRect(1366, 625, 1366, 111), 1));
	////	ground.push_back(Ground(world, FloatRect(1366, 425, 121, 39), 2));
	////	ground.push_back(Ground(world, FloatRect(1566, 325, 121, 39), 2));
	////	ground.push_back(Ground(world, FloatRect(1966, 325, 121, 39), 3, 1766, 2166, 'b'));
	////	ground.push_back(Ground(world, FloatRect(1166, 325, 121, 39), 3, 125, 425, 'v'));
	////	ground.push_back(Ground(world, FloatRect(-405-1366, 13, 405, 755), 4));
	////	ground.push_back(Ground(world, FloatRect(-1200, 325, 121, 39), 2));
	////	ground.push_back(Ground(world, FloatRect(1366*2.f, 625, 1366, 111), 1));
	////	ground.push_back(Ground(world, FloatRect(1366 * 3.f, 625, 1366, 111), 1));
	////	ground.push_back(Ground(world, FloatRect(1366 * 4.f, 625, 1366, 111), 1));
	////	ground.push_back(Ground(world, FloatRect(1366 * 5.f, 625, 1366, 111), 1));
	////	ground.push_back(Ground(world, FloatRect(1366 * 6.f, 625, 1366, 111), 1));
	//////	ground.push_back(Ground(world, FloatRect(4010, 120, 1298, 1158), 6));
	////	ground.push_back(Ground(world, FloatRect(-705, 120, 300, 10), 7));
	////	monster.push_back(new Monster(world, -300, 500, -405, 0));
	////	//m = new Monster(world, 500, 100, -405, 0);
	////	ground.push_back(Ground(world, FloatRect(-405, 120, 405, 755), 4));
	////	ground.push_back(Ground(world, FloatRect(0, 625, 1366, 111), 1));
	////	coins.push_back(Coins(world, 400, 500));
	////	ground.push_back(Ground(world, FloatRect(800, 425, 121, 39), 2));
	////	ground.push_back(Ground(world, FloatRect(1000, 325, 121, 39), 2));
	////	coins.push_back(Coins(world, 1050, 200));
	////  ground.push_back(Ground(world, FloatRect(1200, 325, 121, 39), 2));
	////	ground.push_back(Ground(world, FloatRect(1400, 325, 121, 39), 2));
	////	ground.push_back(Ground(world, FloatRect(1366, 800, 300, 10), 7));
	////	ground.push_back(Ground(world, FloatRect(1666, 625, 1366, 111), 1));
	////	ground.push_back(Ground(world, FloatRect(1700, 425, 121, 39), 2));
	////	coins.push_back(Coins(world, 1700, 300));

	//}

	std::ifstream file;
	if (location == 1)
	{
		player = new Player(world, FloatRect(0, 228, 112, 199), 0, 0, 86);
		file.open("d:\\Game\\map\\dat\\lvl1", std::ios::binary);
		player->havePistol = false;
		b2BodyDef b2Def;
		b2Def.position.Set(19800 / scale, 300 / scale);
		b2theEnd = world.CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(40 / 2.f / scale, 5 / scale);
		b2FixtureDef b2Fix;
		b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
	}
	if (location == 2)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 0, 0, 103);
		file.open("d:\\Game\\map\\dat\\lvl2", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.position.Set(19800 / scale, 300 / scale);
		b2theEnd = world.CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(40 / 2.f / scale, 5 / scale);
		b2FixtureDef b2Fix;
		b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
	}
	if (location == 3)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 19000, 0, 103);
		file.open("d:\\Game\\map\\dat\\lvl3", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.position.Set(19800 / scale, 300 / scale);
		b2theEnd = world.CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(40 / 2.f / scale, 5 / scale);
		b2FixtureDef b2Fix;
		b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
		maxCoins = 0;
	}
	if (location == 4)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 0, 0, 103);
		file.open("d:\\Game\\map\\dat\\lvl4", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.position.Set(19800 / scale, 300 / scale);
		b2theEnd = world.CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(40 / 2.f / scale, 5 / scale);
		b2FixtureDef b2Fix;
		b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
	}
	if (location == 5)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 0, 0, 103);
		file.open("d:\\Game\\map\\dat\\lvl5", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.position.Set(19800 / scale, 300 / scale);
		b2theEnd = world.CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(40 / 2.f / scale, 5 / scale);
		b2FixtureDef b2Fix;
		b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
	}
	if (location == 6)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 0, 0, 103);
		file.open("d:\\Game\\map\\dat\\lvl6", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.position.Set(19800 / scale, 300 / scale);
		b2theEnd = world.CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(40 / 2.f / scale, 5 / scale);
		b2FixtureDef b2Fix;
		b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
	}
	if (location == 7)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 0, 0, 103);
		file.open("d:\\Game\\map\\dat\\lvl7", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.position.Set(19800 / scale, 300 / scale);
		b2theEnd = world.CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(40 / 2.f / scale, 5 / scale);
		b2FixtureDef b2Fix;
		b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
	}
	for (int i = 0; !file.eof(); i++)
	{
		elements.resize(i + 1);
		file.read(reinterpret_cast<char*>(&elements[i]), sizeof(element));
	}
	if (file.is_open())
	{
		for (int i = 0; i < elements.size(); i++)
		{
			if (elements[i].number == 1)
			{
				ground.push_back(Ground(world, FloatRect(elements[i].x, elements[i].y, 1366, 514), 1));
			}
			if (elements[i].number == 2)
			{
				ground.push_back(Ground(world, FloatRect(elements[i].x, elements[i].y, 121, 39), 2));
			}
			if (elements[i].number == 3)
			{
				ground.push_back(Ground(world, FloatRect(elements[i].x, elements[i].y, 121, 39), 3, elements[i].t1, elements[i].t2, elements[i].vec));
			}
			if (elements[i].number == 4)
			{
				ground.push_back(Ground(world, FloatRect(elements[i].x, elements[i].y, 405, 755), 4));
			}
			if (elements[i].number == 7)
			{
				ground.push_back(Ground(world, FloatRect(elements[i].x, elements[i].y, elements[i].dx, elements[i].dy), 7));
			}
			if (elements[i].number == 8)
			{
				coins.push_back(Coins(world, elements[i].x, elements[i].y));
			}
			if (elements[i].number == 9)
			{
				monster.push_back(new Monster(world, elements[i].x, elements[i].y, elements[i].t1, elements[i].t2));
				std::cout << elements[i].t1 << std::endl << elements[i].t2 << std::endl << std::endl;
			}
				//b2BodyDef b2Def;
				//b2Def.position.Set(19800 / scale, 300 / scale);
				//b2theEnd = world.CreateBody(&b2Def);
				//b2PolygonShape b2Shape;
				//b2Shape.SetAsBox(40 / 2.f / scale, 5 / scale);
				//b2FixtureDef b2Fix;
				//b2Fix.isSensor = true;
				//b2Fix.shape = &b2Shape;
				//b2Fix.density = 1.0;
				//b2theEnd->CreateFixture(&b2Shape,1);
		}
	}
}


Level::~Level()
{
}
