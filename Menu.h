#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Button.h"
#include "Game.h"

class Menu
{
public:
	Menu(sf::RenderWindow &window,std::string type);
	sf::Texture tRestart,tText,tZat,tBPNewGame,tBContinue,tBExittoMainMenu,tFon, tBNewGame, tBLvl, tBSettings, tBExit, tBMusicOff, tBMusicOn, tBSoundOff, tBSoundOn, tBLoc1, tBLoc2, tBLoc3, tBLoc4, tBLoc5, tBLoc6, tBLoc7;
	sf::Sprite sRestart,sText,sZat, sBPNewGame, sBContinue, sBExittoMainMenu, sFon, sBNewGame, sBLvl, sBSettings, sBExit, sBMusicOff, sBMusicOn, sBSoundOff, sBSoundOn, sBLoc1, sBLoc2, sBLoc3, sBLoc4, sBLoc5, sBLoc6, sBLoc7;
	void draw(sf::RenderWindow &window);
	bool kliked(sf::RenderWindow &window);
	std::vector<Button> activeButton;
	sf::IntRect Restart,Zat, BPNewGame, BContinue, BExittoMainMenu, BNewGame, BLvl, BSettings, BExit, BMusicOff, BMusicOn, BSoundOff, BSoundOn, BLoc1, BLoc2, BLoc3, BLoc4, BLoc5, BLoc6, BLoc7;
	bool flag = false;
	std::string type;
	int startLevel = 1;
	bool ExitToMenu = false;
	void finalLoad(Game *game);
	~Menu();
};

#endif

