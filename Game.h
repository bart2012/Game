#ifndef GAME_H
#define GAME_H
#include "Level.h"

class Game
{
public:
	void logic(b2World &world);
	Game(b2World &world);
	Level *level;
	~Game();
private:
	void logicCoin(b2World &world);
	void logicMoveLPlatrotm ();
	void logicChasm();
	void keyPressed();
	float scale = 30;
	int score { 0 };

};

#endif
