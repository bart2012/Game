#pragma warning( disable : 4996)
#include "Camera.h"
#include <sstream>
#include "doublenumberssupport.h"
#include <cmath>
Camera::Camera(int locatoin) :_location(locatoin)
{
	tFStars.loadFromFile("D:/Game/loc0/stars.png");
	tFpolosky.loadFromFile("D:/Game/loc0/полоски.png");
	if (locatoin == 1)
	{
		tFGoru.loadFromFile("D:/Game/loc0/mountain.png");
		tFPlanet.loadFromFile("D:/Game/loc0/sun.png");
		tPlatform.loadFromFile("D:/Game/loc0/platform.png");
		tGround.loadFromFile("D:/Game/loc0/down.png");
		tStina.loadFromFile("D:/Game/loc0/блок.png");
	}
	if (locatoin == 2)
	{
		tFGoru.loadFromFile("D:/Game/loc1/mountain.png");
		tFPlanet.loadFromFile("D:/Game/loc1/mercury.png");
		tPlatform.loadFromFile("D:/Game/loc1/platform.png");
		tGround.loadFromFile("D:/Game/loc1/down.png");
		tStina.loadFromFile("D:/Game/loc1/блок.png");
	}
	if (locatoin == 3)
	{
		tFGoru.loadFromFile("D:/Game/loc2/mountain.png");
		tFPlanet.loadFromFile("D:/Game/loc2/earth.png");
		tPlatform.loadFromFile("D:/Game/loc2/platform.png");
		tGround.loadFromFile("D:/Game/loc2/down.png");
		tStina.loadFromFile("D:/Game/loc2/блок.png");
	}
	if (locatoin == 4)
	{
		tFGoru.loadFromFile("D:/Game/loc3/mountain.png");
		tFPlanet.loadFromFile("D:/Game/loc3/mars.png");
		tPlatform.loadFromFile("D:/Game/loc3/platform.png");
		tGround.loadFromFile("D:/Game/loc3/down.png");
		tStina.loadFromFile("D:/Game/loc3/блок.png");
	}
	if (locatoin == 5)
	{
		tFGoru.loadFromFile("D:/Game/loc4/mountain.png");
		tFPlanet.loadFromFile("D:/Game/loc4/planet.png");
		tPlatform.loadFromFile("D:/Game/loc4/platform.png");
		tGround.loadFromFile("D:/Game/loc4/down.png");
		tStina.loadFromFile("D:/Game/loc4/блок.png");
	}
	if (locatoin == 6)
	{
		tFGoru.loadFromFile("D:/Game/loc5/mountain.png");
		tFPlanet.loadFromFile("D:/Game/loc5/planet.png");
		tPlatform.loadFromFile("D:/Game/loc5/platform.png");
		tGround.loadFromFile("D:/Game/loc5/down.png");
		tStina.loadFromFile("D:/Game/loc5/блок.png");
	}
	if (locatoin == 7)
	{
		tFGoru.loadFromFile("D:/Game/loc6/mountain.png");
		tFPlanet.loadFromFile("D:/Game/loc6/planet.png");
		tPlatform.loadFromFile("D:/Game/loc6/platform.png");
		tGround.loadFromFile("D:/Game/loc6/down.png");
		tStina.loadFromFile("D:/Game/loc6/блок.png");
		tFog.loadFromFile("D:/Game/loc6/fog.png");
		sFog.setTexture(tFog);
		fog.push_back(Fon(sFog, 0, 0));
	}


	tCoins.loadFromFile("D:/Game/zagEl/moon.png");
	tRBullet.loadFromFile("D:/Game/character/RBullet.png");
	tLBullet.loadFromFile("D:/Game/character/LBullet.png");
	//tFon.loadFromFile("D:/Game/zagEl/background.png");
	//sFon.setTexture(tFon);
	//_tMonster.loadFromFile("D:/Game/character/alien.png");
	//_sMonster.setTexture(_tMonster);
	//_sMonster.setTextureRect(IntRect(1, 1, 100, 100));
	//tRBullet.loadFromFile("D:/Game/zagEl/p.png");
	//tLBullet.loadFromFile("D:/Game/zagEl/p.png");
	sLBullet.setTexture(tLBullet);
	sRBullet.setTexture(tRBullet);
	//sLBullet.setTextureRect(IntRect(0, 0, 14, 6));
	//sRBullet.setTextureRect(IntRect(0, 0, 14, 6));
	//sLBullet.setTextureRect(IntRect(0, 0, 14, 6));
	//sRBullet.setTextureRect(IntRect(0, 0, 14, 6));
	sLBullet.setTextureRect(IntRect(0, 11, 24, 6));
	//sLBullet.setTextureRect(IntRect(0, 0, -14, 6));
	sRBullet.setTextureRect(IntRect(6, 11, 24, 6));
	//sRBullet.setTextureRect(IntRect(0, 0, -14, 6));
	sLBullet.setOrigin(7, 3);
	sRBullet.setOrigin(22, 3);
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
	sFGoru.setPosition(0, 217);
	goru.push_back(Fon(sFGoru, 0, 212));
	stars.push_back(Fon(sFStars, 0, 0));
	polosky.push_back(Fon(sFpolosky, 0, 0));

	font.loadFromFile("D:/Game/9114.otf");
	text.setFont(font);
	text.setCharacterSize(40);
	text.setColor(Color::Color(168, 168, 168));

}

void Camera::draw(b2World &world, RenderWindow &window, Level *level, int score)
{
	window.clear();
	b2Vec2 pl = level->player->b2body()->GetPosition();
	offsetX = pl.x*scale - 683;
	moveFon(level);

	for (int i = 0; i < polosky.size(); i++)
	{

		window.draw(polosky[i].sprite);
	}
	for (int i = 0; i < stars.size(); i++)
	{
		window.draw(stars[i].sprite);
	}
	for (int i = 0; i < goru.size(); i++)
	{
		window.draw(goru[i].sprite);
	}
	if (_location == 7)
	{
		for (int i = 0; i < fog.size(); i++)
		{
			window.draw(fog[i].sprite);
		}
	}

	window.draw(sFPlanet);
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
	b2Vec2  pos = level->player->b2body()->GetPosition();
	//player.b2Player->SetTransform(pos, 0);
	//float angle = level->player->b2Player->GetAngle();
	level->player->sprite()->setPosition(pos.x*scale - offsetX, pos.y*scale - offsetYg + 1);
	//std::cout << "p =" << int(pos.x*m - offsetX) << std::endl;
	//	level->player->sPlayer.setRotation(angle * 57);
	window.draw(*level->player->sprite());

	for (int i = 0; i < level->coins.size(); i++)
	{
		sCoins.setPosition(level->coins[i].x - offsetX, level->coins[i].y - offsetYg);
		window.draw(sCoins);
	}
	for (int i = 0; i < level->ground.size(); i++)
	{
		if (level->ground[i].number == 1)
		{
			sGround.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetYg);
			window.draw(sGround);
		}
		if (level->ground[i].number == 2)
		{
			sPlatform.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetYg);
			window.draw(sPlatform);
		}
		if (level->ground[i].number == 3)
		{
			b2Vec2 posPl = level->ground[i].b2Body->GetPosition();
			sPlatform.setPosition(posPl.x*scale - level->ground[i].rect.width / 2.f - offsetX, posPl.y*scale - level->ground[i].rect.height / 2.f - offsetYg);
			window.draw(sPlatform);
		}
		if (level->ground[i].number == 4)
		{
			sStina.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetYg);
			window.draw(sStina);
		}
		if (level->ground[i].number == 5)
		{
			sPid.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetYg);
			window.draw(sPid);
		}
		if (level->ground[i].number == 6)
		{

			sSpusk.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetYg);
			window.draw(sSpusk);
		}
	}
	for (int i = 0; i < level->bullet.size(); i++)
	{
		b2Vec2 position = level->bullet[i].b2Bullet->GetPosition();
		if (level->bullet[i].directionRignt())
		{

			sRBullet.setPosition(position.x*scale - offsetX, position.y*scale - offsetYg);
			window.draw(sRBullet);
		}
		if (level->bullet[i].directionLeft())
		{
			sLBullet.setPosition(position.x*scale - offsetX, position.y*scale - offsetYg);
			window.draw(sLBullet);
		}
	}
	for (int i = 0; i < level->monster.size(); i++)
	{
		b2Vec2  pos = level->monster[i]->b2body()->GetPosition();
		//std::cout << "  x  " << pos.x*scale<<std::endl<<"y   "<< pos.y*scale<<std::endl;
		level->monster[i]->sprite()->setPosition(pos.x*scale - offsetX, pos.y*scale - offsetYg);
		window.draw(*level->monster[i]->sprite());
		//_sMonster.setPosition(pos.x*scale - offsetX, pos.y*scale);
		//window.draw(_sMonster);
	}
	std::ostringstream _score;
	_score << score;
	text.setPosition(pos.x*scale - offsetX + 420, 30);
	text.setString("Score " + _score.str());
	window.draw(text);
	sCoins.setPosition(pos.x*scale - offsetX + 510 + _score.str().size() * 15, 33);
	window.draw(sCoins);
	if (display)
	{
		window.display();
	}
}

void Camera::moveFon(Level *level)
{
	setY(level);

	b2Vec2 posP = level->player->b2body()->GetPosition();
	if (650 + offsetYg < posP.y*scale - 99.5&&DoubleCompare::fuzzyIsNull(offsetYl))
	{
		offsetYg += 500;
		polosky.clear();
		goru.clear();
		stars.clear();
		fog.clear();
		polosky.push_back(Fon(sFpolosky, posP.x*scale - 683 - offsetX, offsetYg - 130));
		goru.push_back(Fon(sFGoru, posP.x*scale - 683 - offsetX, offsetYg - 130 + 212));
		stars.push_back(Fon(sFStars, posP.x*scale - 683 - offsetX, offsetYg - 130));
		if (_location == 7)
		{
			fog.push_back(Fon(sFog, posP.x*scale - 683 - offsetX, offsetYg - 130));
		}
	}

	if (500+offsetYg <posP.y*scale + 99.5,5&&!DoubleCompare::fuzzyIsNull(offsetYl))
	{
		offsetYl = 0;
		offsetYg += 300;
		polosky.clear();
		goru.clear();
		stars.clear();
		fog.clear();
		polosky.push_back(Fon(sFpolosky, posP.x*scale - 683 - offsetX, offsetYg - 130));
		goru.push_back(Fon(sFGoru, posP.x*scale - 683 - offsetX, offsetYg - 130 + 212));
		stars.push_back(Fon(sFStars, posP.x*scale - 683 - offsetX, offsetYg - 130));
		if (_location == 7)
		{
			fog.push_back(Fon(sFog, posP.x*scale - 683 - offsetX, offsetYg - 130));
		}
	}

	//if (offsetYg - 200 > posP.y*scale - 99.5)
	//{
	//	offsetYl = -300;
	//	offsetYg -= 300;
	//	polosky.clear();
	//	goru.clear();
	//	stars.clear();
	//	fog.clear();
	//	polosky.push_back(Fon(sFpolosky, posP.x*scale - 683 - offsetX, offsetYg));
	//	goru.push_back(Fon(sFGoru, posP.x*scale - 683 - offsetX, offsetYg + 212));
	//	stars.push_back(Fon(sFStars, posP.x*scale - 683 - offsetX, offsetYg));
	//	if (_location == 7)
	//	{
	//		fog.push_back(Fon(sFog, posP.x*scale - 683 - offsetX, offsetYg));
	//	}
	//}


	if (polosky[polosky.size() - 1].x - offsetX * 0.1f + 1363 < offsetX + 683)
	{
		polosky.push_back(Fon(sFpolosky, polosky[polosky.size() - 1].x + 1363, polosky[polosky.size() - 1].y));
	}
	if (goru[goru.size() - 1].x - offsetX * 0.2f + 1490 < offsetX + 683)
	{
		goru.push_back(Fon(sFGoru, goru[goru.size() - 1].x + 1700, goru[goru.size() - 1].y));
	}
	if (stars[stars.size() - 1].x - offsetX * 0.15f + 1608 < offsetX + 683)
	{
		stars.push_back(Fon(sFStars, stars[stars.size() - 1].x + 1608, stars[stars.size() - 1].y));
	}
	if (_location == 7)
	{
		if (fog[fog.size() - 1].x - offsetX * 0.25f + 1374 < offsetX + 683)
		{
			fog.push_back(Fon(sFog, fog[fog.size() - 1].x + 1374, fog[fog.size() - 1].y));
		}
	}
	if (polosky[0].x - offsetX * 0.1f > offsetX - 683)
	{
		polosky.emplace(polosky.begin(), Fon(sFpolosky, polosky[0].x - 1363, polosky[polosky.size() - 1].y));
	}
	if (goru[0].x - offsetX * 0.2f > offsetX - 683)
	{
		goru.emplace(goru.begin(), Fon(sFGoru, goru[0].x - 1700, goru[goru.size() - 1].y));
	}
	if (stars[0].x - offsetX * 0.15f > offsetX - 683)
	{
		stars.emplace(stars.begin(), Fon(sFStars, stars[0].x - 1608, stars[stars.size() - 1].y));
	}
	if (_location == 7)
	{
		if (fog[fog.size() - 1].x - offsetX * 0.25f + 1374 < offsetX + 683)
		{
			fog.emplace(fog.begin(), Fon(sFog, fog[0].x - 1374, fog[fog.size() - 1].y));
		}
	}
	sFPlanet.setPosition(offsetX*0.01f, 0);
	for (int i = 0; i < polosky.size(); i++)
	{
		polosky[i].sprite.setPosition(polosky[i].x - (offsetX * 0.1f), polosky[i].y);
	}
	for (int i = 0; i < stars.size(); i++)
	{
		stars[i].sprite.setPosition(stars[i].x - (offsetX * 0.15f), stars[i].y);
	}
	for (int i = 0; i < goru.size(); i++)
	{
		goru[i].sprite.setPosition(goru[i].x - (offsetX * 0.2f), goru[i].y);
	}
	if (_location == 7)
	{
		for (int i = 0; i < fog.size(); i++)
		{
			fog[i].sprite.setPosition(fog[i].x - (offsetX * 0.25f), fog[i].y);
		}
	}

}

void Camera::setY(Level *level)
{
	for (int i = 0; i < level->ground.size(); i++)
	{
		if (level->ground[i].number == 4 || level->ground[i].number == 1)
		{
			for (b2ContactEdge *contactList = level->ground[i].b2Body->GetContactList(); contactList != nullptr; contactList = contactList->next)
			{
				if (contactList->other == level->player->b2body())
				{
					b2Vec2 posP = level->player->b2body()->GetPosition();
					b2Vec2 posG = level->ground[i].b2Body->GetPosition();
					if ((DoubleCompare::doubleEquals(posG.y*scale - posP.y*scale, 477, 1)&& !DoubleCompare::doubleEquals(offsetYg, posP.y*scale - 500, 1) && level->ground[i].number == 4) || (DoubleCompare::doubleEquals(posG.y*scale - posP.y*scale,356.5,1) && !DoubleCompare::doubleEquals(offsetYg, posP.y*scale - 500,1) && level->ground[i].number == 1))
					{
						polosky.clear();
						goru.clear();
						stars.clear();
						offsetYg = posP.y*scale-500;
						polosky.push_back(Fon(sFpolosky, posP.x*scale - 683 - offsetX, offsetYg));
						goru.push_back(Fon(sFGoru, posP.x*scale - 683 - offsetX , offsetYg-130 + 212));
						stars.push_back(Fon(sFStars, posP.x*scale - 683 - offsetX , offsetYg-130));
						if (_location == 7)
						{
							fog.push_back(Fon(sFog, posP.x*scale - 683 - offsetX, offsetYg));
						}
						return;
					}
				}
			}
		}
	}
}

Camera::~Camera()
{
}
