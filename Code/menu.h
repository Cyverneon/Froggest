#pragma once

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu(sf::RenderWindow* newWindow, std::string bgPath);

	void Loop();

	void SetBG(std::string bgPath);

	void Restart();

private:
	sf::RenderWindow* window;

	sf::Texture bgTexture;
	sf::Sprite bg;

	bool menuConfirmed = false;
};

#endif