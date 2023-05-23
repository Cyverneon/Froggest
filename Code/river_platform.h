#pragma once

#ifndef RIVER_PLATFORM_H
#define RIVER_PLATFORM_H

#include <SFML/Graphics.hpp>
#include "game_object.h"
#include "frog.h"

class Frog;

class RiverPlatform : public GameObject
{
public:
	RiverPlatform(sf::Vector2f starting_pos, sf::Vector2f size, float new_speed, std::string texture_path, float colliderScale, Frog* frog_ref);

	void MoveRiverPlatform(float deltaTime);

private:
	float speed = 0;

	Frog* frog;
};

#endif