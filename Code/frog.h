#pragma once

#ifndef FROG_H
#define FROG_H

#include <SFML/Graphics.hpp>
#include "game_object.h"
#include "DEFINITIONS.h"
#include "river_platform.h"
#include "truck.h"

class RiverPlatform;
class Truck;

class Frog : public GameObject
{
public:
	Frog();

	void MoveFrog(sf::Event event);

	void setTrucksRef(std::vector<Truck*> trucksRef);
	void setRiverPlatformsRef(std::vector<RiverPlatform*> riverPlatformsRef);

	bool CheckDeath();
	bool CheckWin();

	void Respawn();

private:
	std::vector<Truck*> trucks;
	std::vector<RiverPlatform*> riverPlatforms;
};

#endif