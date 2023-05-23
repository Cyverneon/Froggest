#include "Frog.h"
#include <iostream>

Frog::Frog()
{
    texture.loadFromFile("Graphics/Frog/Frog.png");
    sprite.setTexture(texture);

    sprite.setOrigin(sf::Vector2f(TILE_SIZE/2, TILE_SIZE/2));
    collider.setOrigin(sf::Vector2f(TILE_SIZE / 2, TILE_SIZE / 2));

    SetColliderSize(TILE_SIZE, TILE_SIZE);

    Respawn();
}

void Frog::Respawn()
{
    // start one tile above the bottom of the screen, plus an extra half tile to account for the sprite origin offset
    SetPos(WINDOW_X / 2, WINDOW_Y - (TILE_SIZE * 1.5));
}

void Frog::setTrucksRef(std::vector<Truck*> trucksRef)
{
    trucks = trucksRef;
}

void Frog::setRiverPlatformsRef(std::vector<RiverPlatform*> riverPlatformsRef)
{
    riverPlatforms = riverPlatformsRef;
}

void Frog::MoveFrog(sf::Event event)
{
    if (sf::Keyboard::Key::A == event.key.code)
    {
        if (sprite.getPosition().x-TILE_SIZE >= 0)
        {
            Move(-TILE_SIZE, 0);
        }
        sprite.setRotation(270);
    }
    if (sf::Keyboard::Key::D == event.key.code)
    {
        if (sprite.getPosition().x + TILE_SIZE <= WINDOW_X)
        {
            Move(TILE_SIZE, 0);
        }
        sprite.setRotation(90);
    }
    if (sf::Keyboard::Key::W == event.key.code)
    {
        if (sprite.getPosition().y - TILE_SIZE >= 0)
        {
            Move(0, -TILE_SIZE);
        }
        sprite.setRotation(0);
    }
    if (sf::Keyboard::Key::S == event.key.code)
    {
        if (sprite.getPosition().y + TILE_SIZE <= WINDOW_Y)
        {
            Move(0, TILE_SIZE);
        }
        sprite.setRotation(180);
    }
}

bool Frog::CheckDeath()
{
    for (int i = 0; i < trucks.size(); i++)
    {
        if (GetCollider().getGlobalBounds().intersects(trucks[i]->GetCollider().getGlobalBounds()))
        {
            return true;
        }
    }

    if (GetPos().y > RIVER_TOP && GetPos().y < RIVER_BOTTOM)
    {
        for (int i = 0; i < riverPlatforms.size(); i++)
        {
            if (GetCollider().getGlobalBounds().intersects(riverPlatforms[i]->GetCollider().getGlobalBounds()))
            {
                return false;
            }
        }
        return true;
    }

    return false;
}

bool Frog::CheckWin()
{
    if (GetPos().y < 40)
    {
        return true;
    }
    return false;
}