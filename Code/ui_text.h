#pragma once

#ifndef UITEXT_H
#define UITEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class UIText
{
public:
	UIText(std::string newText, int newSize, sf::Vector2f newPos);

	void Update(std::string newText);

	void Draw(sf::RenderWindow& window);

private:
	sf::Font font;
	sf::Text text;
};

#endif