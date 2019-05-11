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
	tRBullet.loadFromFile("D:/Game/character/RBullet.png");
	tLBullet.loadFromFile("D:/Game/character/LBullet.png");
	tFon.loadFromFile("D:/Game/zagEl/background.png");
	sFon.setTexture(tFon);
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
	goru.push_back(Fon(sFGoru,0,212));
	stars.push_back(Fon(sFStars, 0, 0));
	polosky.push_back(Fon(sFpolosky, 0, 0));
}

void Camera::draw(b2World &world, RenderWindow &window, Level *level)
{
window.clear();
b2Vec2 pl = level->player->b2body()->GetPosition();
offsetX = pl.x*scale - 683;
moveFon(level);
//window.draw(sFon);

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
level->player->sprite()->setPosition(pos.x*scale - offsetX, pos.y*scale - offsetY + 1);
//std::cout << "p =" << int(pos.x*m - offsetX) << std::endl;
//	level->player->sPlayer.setRotation(angle * 57);
window.draw(*level->player->sprite());

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
		sPlatform.setPosition(pos.x*scale - level->ground[i].rect.width / 2.f - offsetX, pos.y*scale - level->ground[i].rect.height / 2.f - offsetY);
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
for (int i = 0; i < level->bullet.size(); i++)
{
	b2Vec2 position = level->bullet[i].b2Bullet->GetPosition();
	if (level->bullet[i].directionRignt())
	{

		sRBullet.setPosition(position.x*scale - offsetX, position.y*scale);
		window.draw(sRBullet);
	}
	if (level->bullet[i].directionLeft())
	{
		sLBullet.setPosition(position.x*scale - offsetX, position.y*scale);
		window.draw(sLBullet);
	}
}
for (int i = 0; i < level->monster.size(); i++)
{
	b2Vec2  pos = level->monster[i]->b2body()->GetPosition();
	//std::cout << "  x  " << pos.x*scale<<std::endl<<"y   "<< pos.y*scale<<std::endl;
	level->monster[i]->sprite()->setPosition(pos.x*scale - offsetX, pos.y*scale);
	window.draw(*level->monster[i]->sprite());
	//_sMonster.setPosition(pos.x*scale - offsetX, pos.y*scale);
	//window.draw(_sMonster);
}
window.display();
}

void Camera::moveFon(Level *level)
{
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

	for (int i = 0; i < level->ground.size(); i++)
	{
		if (level->ground[i].number == 4)
		{
			for (b2ContactEdge *contactList = level->ground[i].b2Body->GetContactList(); contactList != nullptr; contactList = contactList->next)
			{
				if (contactList->other == level->player->b2body())
				{
					b2Vec2 posP = level->player->b2body()->GetPosition();
					b2Vec2 posG = level->ground[i].b2Body->GetPosition();
					if ( posG.y*scale - posP.y*scale >  476)
					{
						offsetY = -634;
							polosky.push_back(Fon(sFpolosky, posG.x-202, offsetY*0.7f));
							polosky[polosky.size() - 1].sprite.setPosition(polosky[polosky.size() - 1].x - offsetX * 0.1f, polosky[polosky.size() - 1].y);

							goru.push_back(Fon(sFGoru, posG.x - 202, offsetY * 0.7f + 212));
							goru[goru.size() - 1].sprite.setPosition(goru[goru.size() - 1].x - offsetX * 0.2f, goru[goru.size() - 1].y);

							stars.push_back(Fon(sFStars, posG.x - 202, offsetY * 0.7f));
							stars[stars.size() - 1].sprite.setPosition(stars[stars.size() - 1].x - offsetX * 0.15f, stars[stars.size() - 1].y);

					}
				}
			}
		}
	}


	if (polosky[polosky.size() - 1].x - offsetX * 0.1f + 1363 < offsetX + 683)
	{
		polosky.push_back(Fon(sFpolosky, polosky[polosky.size() - 1].x + 1363, offsetY));
		polosky[polosky.size() - 1].sprite.setPosition(polosky[polosky.size() - 1].x - offsetX * 0.1f, polosky[polosky.size() - 1].y);
	}
	if (goru[goru.size() - 1].x - offsetX * 0.2f + 1490 < offsetX + 683)
	{
		goru.push_back(Fon(sFGoru, goru[goru.size() - 1].x  + 1700 , offsetY+212));
		goru[goru.size() - 1].sprite.setPosition(goru[goru.size() - 1].x - offsetX * 0.2f, goru[goru.size() - 1].y);
	}
	if (stars[stars.size() - 1].x - offsetX * 0.15f + 1608 < offsetX + 683)
	{
		stars.push_back(Fon(sFStars, stars[stars.size() - 1].x  + 1608, offsetY));
		stars[stars.size() - 1].sprite.setPosition(stars[stars.size() - 1].x - offsetX * 0.15f, stars[stars.size() - 1].y);
	}

	if (polosky[0].x - offsetX * 0.1f > offsetX - 683)
	{
		polosky.emplace(polosky.begin(),Fon(sFpolosky, polosky[0].x - 1363, offsetY));
		polosky[0].sprite.setPosition(polosky[0].x - offsetX * 0.1f, polosky[0].y);
	}
	if (goru[0].x - offsetX * 0.2f > offsetX - 683)
	{
		goru.emplace(goru.begin(),Fon(sFGoru, goru[0].x - 1700, offsetY+212));
		goru[0].sprite.setPosition(goru[0].x - offsetX * 0.2f, goru[0].y);
	}
	if (stars[0].x - offsetX * 0.15f > offsetX -683)
	{
		stars.emplace(stars.begin(),Fon(sFStars, stars[0].x - 1608, offsetY));
		stars[0].sprite.setPosition(stars[0].x - offsetX * 0.15f, stars[0].y);
	}
	sFPlanet.setPosition(offsetX*0.05f, offsetY);
}

Camera::~Camera()
{
}
