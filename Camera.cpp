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

void Camera::draw(b2World &world, RenderWindow &window, Level *level)
{
	window.clear(Color::Yellow);
	b2Vec2 pl = level->player->b2Player->GetPosition();
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
	b2Vec2  pos = level->player->b2Player->GetPosition();
	//player.b2Player->SetTransform(pos, 0);
			double angle = level->player->b2Player->GetAngle();
			level->player->sPlayer.setPosition(pos.x*m - offsetX, pos.y*m - offsetY+1);
			//std::cout << "p =" << int(pos.x*m - offsetX) << std::endl;
			level->player->sPlayer.setRotation(angle * 57);
			window.draw(level->player->sPlayer);
	for (int i = 0; i < level->coins.size(); i++)
	{
		sCoins.setPosition(level->coins[i].x - offsetX, level->coins[i].y - offsetY);
		window.draw(sCoins);
	}
	for (int i = 0; i < level->ground.size(); i++)
	{
		if (level->ground[i].number == 1)
		{
			sGround.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetY);
			window.draw(sGround);
		}
		if (level->ground[i].number == 2)
		{
			sPlatform.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetY);
			window.draw(sPlatform);
		}
		if (level->ground[i].number == 3)
		{
			pos = level->ground[i].b2Body->GetPosition();
			sPlatform.setPosition(pos.x*m- level->ground[i].rect.width/2.f - offsetX, pos.y*m - level->ground[i].rect.height / 2.f - offsetY);
			window.draw(sPlatform);
		}
		if (level->ground[i].number == 4)
		{
			sStina.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetY);
			window.draw(sStina);
		}
		if (level->ground[i].number == 5)
		{
			sPid.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetY);
			window.draw(sPid);
		}
		if (level->ground[i].number == 6)
		{
			sSpusk.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetY);
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
