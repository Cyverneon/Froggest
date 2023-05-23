#pragma once

#ifndef TRUCK_H
#define TRUCK_H

#include <SFML/Graphics.hpp>
#include "game_object.h"


// starting_pos in tiles
// size in tiles
// speed in pixels per second

class Truck : public GameObject
{
public:
	Truck( sf::Vector2f starting_pos, sf::Vector2f size, float new_speed, std::string texture_path, float colliderScale);

	void MoveTruck(float deltaTime );

private:
	float speed = 0;
};

#endif