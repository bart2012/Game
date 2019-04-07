#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
class Menu
{
public:
	Menu(sf::RenderWindow &window,std::string type);
	sf::Texture tFon, tBNewGame, tBLvl, tBSettings, tBExit, tBMusicOff, tBMusicOn, tBSoundOff, tBSoundOn, tBLoc1, tBLoc2, tBLoc3, tBLoc4, tBLoc5, tBLoc6, tBLoc7;
	sf::Sprite sFon, sBNewGame, sBLvl, sBSettings, sBExit, sBMusicOff, sBMusicOn, sBSoundOff, sBSoundOn, sBLoc1, sBLoc2, sBLoc3, sBLoc4, sBLoc5, sBLoc6, sBLoc7;
	void draw(sf::RenderWindow &window);
	bool kliled(sf::RenderWindow &window);
	std::vector<sf::Sprite> activeButton;
	sf::IntRect BNewGame, BLvl, BSettings, BExit, BMusicOff, BMusicOn, BSoundOff, BSoundOn, BLoc1, BLoc2, BLoc3, BLoc4, BLoc5, BLoc6, BLoc7;
	int active_menu;
	bool flag = false;
	~Menu();
};

#endif

