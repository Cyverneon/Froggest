#pragma once

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>


class GameObject
{
public:
	GameObject();

	void Draw(sf::RenderWindow& window);

	sf::RectangleShape GetCollider();
	sf::Sprite GetSprite();

	void SetColliderSize(float sizeX, float sizeY);
	sf::Vector2f GetSize();

	void SetPos(float newX, float newY);
	sf::Vector2f GetPos();

	void Move(float moveX, float moveY);

protected:
	sf::RectangleShape collider;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f objectSize;
};

#endif