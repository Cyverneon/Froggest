#include "river_platform.h"
#include "DEFINITIONS.h"

RiverPlatform::RiverPlatform(sf::Vector2f starting_pos, sf::Vector2f size, float new_speed, std::string texture_path, float colliderScale, Frog* frog_ref)
{
	texture.loadFromFile(texture_path);
	sprite.setTexture(texture);

	objectSize = sf::Vector2f(size.x * TILE_SIZE, size.y * TILE_SIZE);
	SetColliderSize((size.x * TILE_SIZE)*colliderScale, (size.y * TILE_SIZE)*colliderScale);

	sprite.setOrigin(sf::Vector2f(objectSize.x / 2, objectSize.y / 2));
	collider.setOrigin(sf::Vector2f((objectSize.x / 2) * colliderScale, (objectSize.y / 2) * colliderScale));

	SetPos((starting_pos.x * TILE_SIZE) - (TILE_SIZE / 2), (starting_pos.y * TILE_SIZE) - (TILE_SIZE / 2));

	speed = new_speed;

	frog = frog_ref;
}

void RiverPlatform::MoveRiverPlatform(float deltaTime)
{
	Move(speed * deltaTime, 0);
	if (GetPos().x < 0 - (GetSize().x / 2))
	{
		SetPos(WINDOW_X + (GetSize().x / 2), GetPos().y);
	}
	if (GetPos().x > WINDOW_X + (GetSize().x / 2))
	{
		SetPos(0 - (GetSize().x / 2), GetPos().y);
	}

	if (GetCollider().getGlobalBounds().intersects(frog->GetCollider().getGlobalBounds()))
	{
		if (frog->GetPos().x + (speed * deltaTime) > 0 && frog->GetPos().x + (speed * deltaTime) < WINDOW_X)
		{
			frog->Move(speed * deltaTime, 0);
		}	
	}
}