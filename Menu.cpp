#include "Menu.h"



Menu::Menu(sf::RenderWindow &window, std::string type)
{
	tFon.loadFromFile("D:/Game/menu/головне/background.png");
	tBNewGame.loadFromFile("D:/Game/menu/головне/нова гра.png");
	tBExit.loadFromFile("D:/Game/menu/головне/вийти.png");
	tBLvl.loadFromFile("D:/Game/menu/головне/обратирівень.png");
	tBSettings.loadFromFile("D:/Game/menu/головне/налаштування.png");

	tBSoundOn.loadFromFile("D:/Game/menu/головне/налаштування/звукивкл.png");
	tBSoundOff.loadFromFile("D:/Game/menu/головне/налаштування/звукивикл.png");
	tBMusicOn.loadFromFile("D:/Game/menu/головне/налаштування/музикавкл.png");
	tBMusicOff.loadFromFile("D:/Game/menu/головне/налаштування/музикавикл.png");



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
	active_menu = 1;
	//activeButton.
}

void Menu::draw(sf::RenderWindow &window)
{
	window.clear();
	if (active_menu == 1)
	{
		window.draw(sFon);
		window.draw(sBNewGame);
		window.draw(sBLvl);
		window.draw(sBSettings);
		window.draw(sBExit);
	}
	if (active_menu == 2)
		for (int i =0;i<2;i++)

	window.display();
}

bool Menu::kliled(sf::RenderWindow &window)
{
	if (!flag)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i vec = sf::Mouse::getPosition();
			//std::cout <<"x"<< vec.x;
			//std::cout << "y" << vec.y;
			if (vec.x > BNewGame.left && vec.x < BNewGame.left + BNewGame.width && vec.y> BNewGame.top && vec.y < BNewGame.top + BNewGame.height)
			{
				std::cout << "1";
				flag = true;
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
