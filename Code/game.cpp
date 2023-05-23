#include "game.h"

Game::Game(sf::RenderWindow* newWindow)
{
    window = newWindow;

    bgTexture.loadFromFile("Graphics/Background.png");
    bg.setTexture(bgTexture);

    frog = new Frog();

    livesUI = new UIText("Lives: " + std::to_string(lives), 16, sf::Vector2f(TILE_SIZE, WINDOW_Y - TILE_SIZE));
    frogsSavedUI = new UIText("Frogs Saved: " + std::to_string(frogsSaved), 16, sf::Vector2f(TILE_SIZE * 4, WINDOW_Y - TILE_SIZE));
}

void Game::StartGame()
{
    frog->Respawn();

    lives = 3;
    frogsSaved = 0;
    dead = false;

    livesUI->Update("Lives: " + std::to_string(lives));
    frogsSavedUI->Update("Frogs Saved: " + std::to_string(frogsSaved));

    trucks.clear();
    riverPlatforms.clear();

    SpawnTruckRow(3, std::vector<int> {5, 10, 15}, sf::Vector2f(1, 1), 160, "Graphics/Cars/CarPinkRight.png");
    SpawnTruckRow(4, std::vector<int> {7, 11}, sf::Vector2f(2, 1), -400, "Graphics/Cars/TruckLeft.png");
    SpawnTruckRow(5, std::vector<int> {4, 8, 10, 14}, sf::Vector2f(1, 1), 80, "Graphics/Cars/CarYellowRight.png");
    SpawnTruckRow(6, std::vector<int> {2, 9}, sf::Vector2f(1, 1), -20, "Graphics/Cars/CarGreyLeft.png");

    SpawnRiverRow(8, std::vector<int> {5}, sf::Vector2f(6, 1), -300, "Graphics/River/Log6.png", frog);
    SpawnRiverRow(9, std::vector<int> {5, 9, 14}, sf::Vector2f(2, 1), 80, "Graphics/River/Turtle2Right.png", frog);
    SpawnRiverRow(10, std::vector<int> {7, 14}, sf::Vector2f(3, 1), -40, "Graphics/River/Log3.png", frog);
    SpawnRiverRow(11, std::vector<int> {1, 5, 10, 15}, sf::Vector2f(3, 1), 100, "Graphics/River/Turtle3Right.png", frog);
    SpawnRiverRow(12, std::vector<int> {3, 9, 14}, sf::Vector2f(3, 1), -20, "Graphics/River/Log3.png", frog);

    SpawnTruckRow(14, std::vector<int> {4, 8, 10, 14}, sf::Vector2f(1, 1), 100, "Graphics/Cars/CarGreyRight.png");
    SpawnTruckRow(15, std::vector<int> {1, 8}, sf::Vector2f{ 2, 1 }, -50, "Graphics/Cars/TruckLeft.png");
    SpawnTruckRow(16, std::vector<int> {3, 8, 13}, sf::Vector2f{ 1, 1 }, 20, "Graphics/Cars/CarYellowRight.png");
    SpawnTruckRow(17, std::vector<int> {7}, sf::Vector2f{ 1, 1 }, 200, "Graphics/Cars/CarPinkRight.png");
    SpawnTruckRow(18, std::vector<int> {4, 9, 14}, sf::Vector2f{ 1, 1 }, -80, "Graphics/Cars/CarGreyLeft.png");

    frog->setRiverPlatformsRef(riverPlatforms);
    frog->setTrucksRef(trucks);

    deltaTime = deltaClock.restart().asSeconds();
}

void Game::SpawnTruckRow(int column, std::vector<int> positions, sf::Vector2f size, float speed, std::string texturePath)
{
    for (int i = 0; i < positions.size(); i++)
    {
        trucks.push_back(new Truck(sf::Vector2f(positions[i], column), size, speed, texturePath, 0.8));
    }
}

void Game::SpawnRiverRow(int column, std::vector<int> positions, sf::Vector2f size, float speed, std::string texturePath, Frog* frogRef)
{
    for (int i = 0; i < positions.size(); i++)
    {
        riverPlatforms.push_back(new RiverPlatform(sf::Vector2f(positions[i], column), size, speed, texturePath, 0.8, frogRef));
    }
}

void Game::Loop()
{
    while (window->isOpen() && !dead)
    {
        deltaTime = deltaClock.restart().asSeconds();

        sf::Event event; 
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyReleased:
                frog->MoveFrog(event);
                break;
            }
        }

        if (frog->CheckDeath())
        {
            lives--;
            livesUI->Update("Lives: " + std::to_string(lives));
            frog->Respawn();
            if (lives < 0)
            {
                dead = true;
            }
        }

        if (frog->CheckWin())
        {
            frogsSaved++;
            frogsSavedUI->Update("Frogs Saved: " + std::to_string(frogsSaved));
            frog->Respawn();
        }

        for (int i = 0; i < trucks.size(); i++)
        {
            trucks[i]->MoveTruck(deltaTime);
        }
        for (int i = 0; i < riverPlatforms.size(); i++)
        {
            riverPlatforms[i]->MoveRiverPlatform(deltaTime);
        }

        window->clear();

        window->draw(bg);

        for (int i = 0; i < riverPlatforms.size(); i++)
        {
            riverPlatforms[i]->Draw(*window);
        }

        frog->Draw( *window);

        for (int i = 0; i < trucks.size(); i++)
        {
            trucks[i]->Draw( *window);
        }

        livesUI->Draw(*window);
        frogsSavedUI->Draw(*window);

        window->display();
    }
}