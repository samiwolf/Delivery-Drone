#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("k.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(300, 100);
    menu[0].setCharacterSize(60);

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("How to Play");
	menu[1].setPosition(300, 180);
	 menu[1].setCharacterSize(40);


	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Credits");
   menu[2].setPosition(300, 260);
    menu[2].setCharacterSize(40);


	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("Exit");
   menu[3].setPosition(300, 340);
    menu[3].setCharacterSize(40);

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		menu[selectedItemIndex].setCharacterSize(40);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
		menu[selectedItemIndex].setCharacterSize(60);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		menu[selectedItemIndex].setCharacterSize(40);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
		menu[selectedItemIndex].setCharacterSize(60);
	}
}
