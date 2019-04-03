#include "Camera.h"



Camera::Camera()
{
	tCoins.loadFromFile("D:/Game/zagEl/moon.png");

	tFGoru.loadFromFile("D:/Game/loc0/mountain.png");
	
	tPlatform.loadFromFile("D:/Game/loc0/platform.png");
	tGround.loadFromFile("D:/Game/loc0/down.png");
	tFStars.loadFromFile("D:/Game/loc0/stars.png");
	tFPlanet.loadFromFile("D:/Game/loc0/sun.png");
	tStina.loadFromFile("D:/Game/loc0/блок.png");
	tFGoruPid.loadFromFile("D:/Game/loc0/горипідйом.png");
	tFGoruSpusk.loadFromFile("D:/Game/loc0/гориспуск.png");
	tPid.loadFromFile("D:/Game/loc1/підйом.png");
	tSpusk.loadFromFile("D:/Game/loc1/спуск.png");
	tFpolosky.loadFromFile("D:/Game/loc0/полоски.png");
	sCoins.setTexture(tCoins);
	sGround.setTexture(tGround);
	sPlatform.setTexture(tPlatform);
	sFGoru.setTexture(tFGoru);
	sFGoruPid.setTexture(tFGoruPid);
	sFGoruSpusk.setTexture(tFGoruSpusk);
	sFStars.setTexture(tFStars);
	sFPlanet.setTexture(tFPlanet);
	sStina.setTexture(tStina);
	sPid.setTexture(tPid);
	sSpusk.setTexture(tSpusk);
	sFpolosky.setTexture(tFpolosky);

}

void Camera::draw(b2World &world, RenderWindow &window, Player &player, std::vector<Coins> coins, std::vector<Ground> ground)
{
	window.clear(Color::Yellow);
	b2Vec2 pl = player.b2Player->GetPosition();
	offsetX = pl.x*m - 683;
	//offsetY = pl.y*m - 525;
	//for (b2Body *it = world.GetBodyList(); it != 0; it = it->GetNext())
	//{
	//	if (it->GetUserData() == &player.pl)
	//	{
	//		b2Vec2  pos = it->GetPosition();
	//		it->SetTransform(pos, 0);
	//		double angle = it->GetAngle();
	//		player.sPlayer.setPosition(pos.x*m - offsetX, pos.y*m - offsetY+1);
	//		//std::cout << "p =" << int(pos.x*m - offsetX) << std::endl;
	//		player.sPlayer.setRotation(angle * 57);
	//		window.draw(player.sPlayer);
	//		break;
	//	}

	//}
	b2Vec2  pos = player.b2Player->GetPosition();
	player.b2Player->SetTransform(pos, 0);
			double angle = player.b2Player->GetAngle();
			player.sPlayer.setPosition(pos.x*m - offsetX, pos.y*m - offsetY+1);
			//std::cout << "p =" << int(pos.x*m - offsetX) << std::endl;
			player.sPlayer.setRotation(angle * 57);
			window.draw(player.sPlayer);
	for (int i = 0; i < coins.size(); i++)
	{
		sCoins.setPosition(coins[i].x - offsetX, coins[i].y - offsetY);
		window.draw(sCoins);
	}
	for (int i = 0; i < ground.size(); i++)
	{
		if (ground[i].number == 1)
		{
			sGround.setPosition(ground[i].rect.left - offsetX, ground[i].rect.top - offsetY);
			window.draw(sGround);
		}
		if (ground[i].number == 2)
		{
			sPlatform.setPosition(ground[i].rect.left - offsetX, ground[i].rect.top - offsetY);
			window.draw(sPlatform);
		}
		if (ground[i].number == 3)
		{
			pos = ground[i].b2Element->GetPosition();
			sPlatform.setPosition(pos.x*m-ground[i].rect.width/2.f - offsetX, pos.y*m - ground[i].rect.height / 2.f - offsetY);
			window.draw(sPlatform);
		}
		if (ground[i].number == 4)
		{
			sStina.setPosition(ground[i].rect.left - offsetX, ground[i].rect.top - offsetY);
			window.draw(sStina);
		}
		if (ground[i].number == 5)
		{
			sPid.setPosition(ground[i].rect.left - offsetX, ground[i].rect.top - offsetY);
			window.draw(sPid);
		}
		if (ground[i].number == 6)
		{
			sSpusk.setPosition(ground[i].rect.left - offsetX, ground[i].rect.top - offsetY);
			window.draw(sSpusk);
		}
	}
	//window.draw(sMountain);
	//window.draw(sMCoins);
	//
	//window.draw(sRocket);
	//window.draw(sStar);
	//window.draw(sPlatform);
	//window.draw(sKos);
	//window.draw(sLoc);
	window.display();
	//getchar();
	
}

Camera::~Camera()
{
}
