#include "Level.h"

// ������� ������ - �����  = 125

Level::Level(b2World &world,int location)
{
	player = new Player(world, FloatRect(0, 0, 112, 199), 100, 402);
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
	//	ground.push_back(Ground(world, FloatRect(-405, 120, 405, 755), 4));
	//	ground.push_back(Ground(world, FloatRect(0, 625, 1366, 111), 1));
	//	coins.push_back(Coins(world, 400, 500));
	//	ground.push_back(Ground(world, FloatRect(800, 425, 121, 39), 2));
	//	ground.push_back(Ground(world, FloatRect(1000, 325, 121, 39), 2));
	//	coins.push_back(Coins(world, 1050, 200));
	////	ground.push_back(Ground(world, FloatRect(1200, 325, 121, 39), 2));
	//	ground.push_back(Ground(world, FloatRect(1400, 325, 121, 39), 2));
	//	ground.push_back(Ground(world, FloatRect(1366, 800, 300, 10), 7));
	//	ground.push_back(Ground(world, FloatRect(1666, 625, 1366, 111), 1));
	//	ground.push_back(Ground(world, FloatRect(1700, 425, 121, 39), 2));
	//	coins.push_back(Coins(world, 1700, 300));

	}

}


Level::~Level()
{
}
