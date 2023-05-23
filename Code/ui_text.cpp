#include "ui_text.h"

UIText::UIText(std::string newText, int newSize, sf::Vector2f newPos)
{
	font.loadFromFile("Graphics/FiraSans-Regular.otf");
	text.setFont(font);
	text.setString(newText);

	text.setCharacterSize(newSize);

	text.setPosition(newPos);
}

void UIText::Update(std::string newText)
{
	text.setString(newText);
}

void UIText::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}