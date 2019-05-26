#ifndef GAME_H
#define GAME_H
#include "Level.h"
class Game
{
public:
	void logic(b2World &world);
	Game(b2World &world,int location);
	Level *level;
	bool game = false;
	int score = 0;
	int location;
	~Game();
private:
	void theEnd();
	void logicCoin(b2World &world);
	void logicMoveLPlatrotm ();
	void logicChasm();
	void keyPressed(b2World &world);
	void logicBullet(b2World &world);
	//void collisionBullet(b2World &world);
	//void destroyBullet();
	float scale = 30;
	bool canShoot = true;
};

#endif

