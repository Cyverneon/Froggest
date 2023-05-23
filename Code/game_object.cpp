#include "game_object.h"

GameObject::GameObject()
{

}

void GameObject::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	// draw colliders for debugging
	//window.draw(collider);
}

sf::RectangleShape GameObject::GetCollider()
{
	return collider;
}

sf::Sprite GameObject::GetSprite()
{
	return sprite;
}

void GameObject::SetColliderSize(float sizeX, float sizeY)
{
	//sprite.setSize(sf::Vector2f(sizeX, sizeY));
	collider.setSize(sf::Vector2f(sizeX, sizeY));
}

sf::Vector2f GameObject::GetSize()
{
	return objectSize;
}

void GameObject::SetPos(float newX, float newY)
{
	sprite.setPosition(sf::Vector2f(newX, newY));
	collider.setPosition(sf::Vector2f(newX, newY));
}

sf::Vector2f GameObject::GetPos()
{
	return sprite.getPosition();
}

void GameObject::Move(float moveX, float moveY)
{
	sprite.move(moveX, moveY);
	collider.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y));
}