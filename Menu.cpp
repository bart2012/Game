#include "Menu.h"



Menu::Menu(sf::RenderWindow &window, std::string type):type(type)
{
	if (type == "main")
	{
		tFon.loadFromFile("D:/Game/menu/main/background.png");
		tBNewGame.loadFromFile("D:/Game/menu/main/нова гра.png");
		tBExit.loadFromFile("D:/Game/menu/main/вийти.png");
		tBLvl.loadFromFile("D:/Game/menu/main/обратирівень.png");
		tBSettings.loadFromFile("D:/Game/menu/main/налаштування.png");
		tBLoc1.loadFromFile("D:/Game/menu/level/1.png");
		tBLoc2.loadFromFile("D:/Game/menu/level/2.png");
		tBLoc3.loadFromFile("D:/Game/menu/level/3.png");
		tBLoc4.loadFromFile("D:/Game/menu/level/4.png");
		tBLoc5.loadFromFile("D:/Game/menu/level/5.png");
		tBLoc6.loadFromFile("D:/Game/menu/level/6.png");
		tBLoc7.loadFromFile("D:/Game/menu/level/7.png");

		sBLoc1.setTexture(tBLoc1);
		sBLoc2.setTexture(tBLoc2);
		sBLoc3.setTexture(tBLoc3);
		sBLoc4.setTexture(tBLoc4);
		sBLoc5.setTexture(tBLoc5);
		sBLoc6.setTexture(tBLoc6);
		sBLoc7.setTexture(tBLoc7);

		BLoc1.left = 148;
		BLoc1.top = 151;
		BLoc1.width = 180;
		BLoc1.height = 227;
		sBLoc1.setPosition(BLoc1.left, BLoc1.top);

		BLoc2.left = 374;
		BLoc2.top = 151;
		BLoc2.width = 180;
		BLoc2.height = 227;
		sBLoc2.setPosition(BLoc2.left, BLoc2.top);

		BLoc3.left = 593;
		BLoc3.top = 151;
		BLoc3.width = 180;
		BLoc3.height = 227;
		sBLoc3.setPosition(BLoc3.left, BLoc3.top);

		BLoc4.left = 805;
		BLoc4.top = 151;
		BLoc4.width = 180;
		BLoc4.height = 227;
		sBLoc4.setPosition(BLoc4.left, BLoc4.top);

		BLoc5.left = 1015;
		BLoc5.top = 151;
		BLoc5.width = 188;
		BLoc5.height = 227;
		sBLoc5.setPosition(BLoc5.left, BLoc5.top);

		BLoc6.left = 475;
		BLoc6.top = 418;
		BLoc6.width = 180;
		BLoc6.height = 227;
		sBLoc6.setPosition(BLoc6.left, BLoc6.top);

		BLoc7.left = 723;
		BLoc7.top = 418;
		BLoc7.width = 180;
		BLoc7.height = 227;
		sBLoc7.setPosition(BLoc7.left, BLoc7.top);

		sFon.setTexture(tFon);
		sBNewGame.setTexture(tBNewGame);
		sBExit.setTexture(tBExit);
		sBLvl.setTexture(tBLvl);
		sBSettings.setTexture(tBSettings);
		sBSoundOn.setTexture(tBSoundOn);
		sBSoundOff.setTexture(tBSoundOff);
		sBMusicOn.setTexture(tBMusicOn);
		sBMusicOff.setTexture(tBMusicOff);

		BNewGame.left = 1366 / 2.f - 392 / 2.f;
		BNewGame.top = 300;
		BNewGame.width = 393;
		BNewGame.height = 89;
		sBNewGame.setPosition(BNewGame.left, BNewGame.top);

		BLvl.left = 1366 / 2.f - 392 / 2.f;
		BLvl.top = 400;
		BLvl.width = 393;
		BLvl.height = 89;
		sBLvl.setPosition(BLvl.left, BLvl.top);

		BSettings.left = 1366 / 2.f - 392 / 2.f;
		BSettings.top = 500;
		BSettings.width = 393;
		BSettings.height = 89;
		sBSettings.setPosition(BSettings.left, BSettings.top);

		BExit.left = 1366 / 2.f - 392 / 2.f;
		BExit.top = 600;
		BExit.width = 393;
		BExit.height = 89;
		sBExit.setPosition(BExit.left, BExit.top);

		BSoundOn.left = 1366 / 2.f - 574 / 2.f;
		BSoundOn.top = 300;
		BSoundOn.width = 575;
		BSoundOn.height = 99;
		sBSoundOn.setPosition(BExit.left, BExit.top);

		BSoundOff.left = 1366 / 2.f - 574 / 2.f;
		BSoundOff.top = 300;
		BSoundOff.width = 575;
		BSoundOff.height = 99;
		sBSoundOff.setPosition(BExit.left, BExit.top);

		BMusicOn.left = 1366 / 2.f - 574 / 2.f;
		BMusicOn.top = 500;
		BMusicOn.width = 575;
		BMusicOn.height = 99;
		sBMusicOn.setPosition(BExit.left, BExit.top);

		BMusicOff.left = 1366 / 2.f - 574 / 2.f;
		BMusicOff.top = 500;
		BMusicOff.width = 575;
		BMusicOff.height = 99;
		sBMusicOff.setPosition(BExit.left, BExit.top);

		activeButton.push_back(Button(sBNewGame, "newGame", BNewGame));
		activeButton.push_back(Button(sBLvl, "lvl", BLvl));
		activeButton.push_back(Button(sBSettings, "settings", BSettings));
		activeButton.push_back(Button(sBExit, "exit", BExit));
	}
	if (type == "pause")
	{
		tZat.loadFromFile("D:/Game/menu/pause/zat.png");
		tBContinue.loadFromFile("D:/Game/menu/pause/continue.png");
		tBExittoMainMenu.loadFromFile("D:/Game/menu/pause/exittomaimmenu.png");
		sZat.setTexture(tZat);
		sBPNewGame.setTexture(tBPNewGame);
		sBContinue.setTexture(tBContinue);
		sBExittoMainMenu.setTexture(tBExittoMainMenu);

		BContinue.left = 520;
		BContinue.top = 400;
		BContinue.width = 316;
		BContinue.height = 71;
		sBContinue.setPosition(BContinue.left, BContinue.top);

		BExittoMainMenu.left = 520;
		BExittoMainMenu.top = 500;
		BExittoMainMenu.width = 315;
		BExittoMainMenu.height = 71;
		sBExittoMainMenu.setPosition(BExittoMainMenu.left, BExittoMainMenu.top);
		activeButton.push_back(Button(sBContinue, "Continue", BContinue));
		activeButton.push_back(Button(sBExittoMainMenu, "ExitToMainMenu", BExittoMainMenu));
	}
	if (type == "los")
	{
		tFon.loadFromFile("D:/Game/menu/los/fon.png");
		sFon.setTexture(tFon);
		tText.loadFromFile("D:/Game/menu/los/text.png");
		sText.setTexture(tText);
		sText.setPosition(320, 100);
		tRestart.loadFromFile("D:/Game/menu/los/restart.png");
		sRestart.setTexture(tRestart);
		Restart.left = 520;
		Restart.top = 400;
		Restart.width = 318;
		Restart.height = 73;
		sRestart.setPosition(Restart.left, Restart.top);
		activeButton.push_back(Button(sRestart, "restart", Restart));
	}

}

void Menu::finalLoad(Game *game)
{
	if (game->level->maxCoins * 80 <= game->score)
	{
		tFon.loadFromFile("D:/Game/menu/final/+.png");
		sFon.setTexture(tFon);
		tBExittoMainMenu.loadFromFile("D:/Game/menu/pause/exittomaimmenu.png");
		sBExittoMainMenu.setTexture(tBExittoMainMenu);
		BExittoMainMenu.left = 920;
		BExittoMainMenu.top = 500;
		BExittoMainMenu.width = 315;
		BExittoMainMenu.height = 71;
		sBExittoMainMenu.setPosition(BExittoMainMenu.left, BExittoMainMenu.top);
		activeButton.push_back(Button(sBExittoMainMenu, "ExitToMainMenu", BExittoMainMenu));
	}
	else
	{
		tFon.loadFromFile("D:/Game/menu/final/-.png");
		sFon.setTexture(tFon);
		tRestart.loadFromFile("D:/Game/menu/los/restart.png");
		sRestart.setTexture(tRestart);
		Restart.left = 194;
		Restart.top = 551;
		Restart.width = 318;
		Restart.height = 73;
		sRestart.setPosition(Restart.left, Restart.top);
		activeButton.push_back(Button(sRestart, "restart", Restart));
	}
}


void Menu::draw(sf::RenderWindow &window)
{
	if (type == "main"||type=="los"||type=="final")
	{
		window.clear();
		window.draw(sFon);
	}
	if (type == "los")
	{
		window.draw(sText);
	}
	if (type == "pause")
	{
		window.draw(sZat);
	}
	for (int i = 0; i < activeButton.size(); i++)
	{
		window.draw(activeButton[i].sprite);
	}
	window.display();
}

bool Menu::kliked(sf::RenderWindow &window)
{
	if (!flag)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i posMouse = sf::Mouse::getPosition();
			sf::Vector2i posWindow = window.getPosition();
			posWindow.y += 29;
			posWindow.x += 8;
			for (int i = 0; i < activeButton.size(); i++)
			{
				if (posMouse.x - posWindow.x > activeButton[i].rect.left && posMouse.x - posWindow.x < activeButton[i].rect.left + activeButton[i].rect.width && posMouse.y - posWindow.y> activeButton[i].rect.top && posMouse.y - posWindow.y < activeButton[i].rect.top + activeButton[i].rect.height)
				{
					if (type == "main")
					{
						if (activeButton[i].name == "newGame")
						{
							return true;
						}
						if (activeButton[i].name == "lvl")
						{
							activeButton.clear();
							activeButton.push_back(Button(sBLoc1, "lvl1", BLoc1));
							activeButton.push_back(Button(sBLoc2, "lvl2", BLoc2));
							activeButton.push_back(Button(sBLoc3, "lvl3", BLoc3));
							activeButton.push_back(Button(sBLoc4, "lvl4", BLoc4));
							activeButton.push_back(Button(sBLoc5, "lvl5", BLoc5));
							activeButton.push_back(Button(sBLoc6, "lvl6", BLoc6));
							activeButton.push_back(Button(sBLoc7, "lvl7", BLoc7));
							flag = true;
							break;
						}
						if (activeButton[i].name == "settings")
						{

						}
						if (activeButton[i].name == "exit")
						{
							window.close();
						}
						if (activeButton[i].name == "lvl1")
						{
							startLevel = 1;
							return true;
						}
						if (activeButton[i].name == "lvl2")
						{
							startLevel = 2;
							return true;
						}
						if (activeButton[i].name == "lvl3")
						{
							startLevel = 3;
							return true;
						}
						if (activeButton[i].name == "lvl4")
						{
							startLevel = 4;
							return true;
						}
						if (activeButton[i].name == "lvl5")
						{
							startLevel = 5;
							return true;
						}
						if (activeButton[i].name == "lvl6")
						{
							startLevel = 6;
							return true;
						}
						if (activeButton[i].name == "lvl7")
						{
							startLevel = 7;
							return true;
						}
					}
					if (type == "pause"||type=="final")
					{
						if (activeButton[i].name == "Continue")
						{
							return true;
						}
						if (activeButton[i].name == "ExitToMainMenu")
						{
							ExitToMenu = true;
							return true;
						}
					}
					if (type == "los" || type == "final")
					{
						if (activeButton[i].name == "restart")
						{
							return true;
						}
					}
					break;
					flag = true;
				}
			}
		}
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && flag)
	{
		flag = false;
	}
	return false;
}

Menu::~Menu()
{
}
