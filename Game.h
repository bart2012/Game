#ifndef GAME_H
#define GAME_H
#include "Level.h"
//#include "doublenumberssupport.h"
class Game
{
public:
	void logic(b2World &world,Level *level);
	Game();
	~Game();
private:
	void logicCoin(b2World &world,Level *level);
	void logicMoveLPlatrotm (b2World &world,Level *level);
	void logicYama(b2World &world,Level *level);
	void keyPressed(Level *level);
	double m = 30;
	int score{ 0 };

};

#endif
