#pragma once

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "frog.h"
#include "truck.h"
#include "river_platform.h"
#include "ui_text.h"

class Game
{
public:
	Game(sf::RenderWindow* newWindow);

	void SpawnTruckRow(int column, std::vector<int> positions, sf::Vector2f size, float speed, std::string texturePath);
	void SpawnRiverRow(int column, std::vector<int> positions, sf::Vector2f size, float speed, std::string texturePath, Frog* frogRef);

	void StartGame();

	void Loop();

private:
	sf::RenderWindow* window;

	sf::Clock deltaClock;
	float deltaTime = 0;

	Frog* frog;
	std::vector<Truck*> trucks;
	std::vector<RiverPlatform*> riverPlatforms;

	int lives = 3;	
	int frogsSaved = 0;

	bool dead = false;

	UIText* frogsSavedUI;
	UIText* livesUI;

	sf::Texture bgTexture;
	sf::Sprite bg;
};

#endif