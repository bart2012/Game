#include "Location.h"



Location::Location(int location)
{
	if (location == 1)
	{
		tMountain.loadFromFile("D:/Game/loc1/mountain.png");
		tMCoins.loadFromFile("D:/Game/loc1/coin.png");
		tPlatform.loadFromFile("D:/Game/loc1/platform.png");
		tGround.loadFromFile("D:/Game/loc1/down.png");
		tLocation.loadFromFile("D:/Game/loc1/loc1.png");
	}

}


Location::~Location()
{
}
