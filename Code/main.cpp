#include "game.h"
#include "menu.h"

int main()
{
    sf::RenderWindow* window;
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_X, WINDOW_Y), WINDOW_TITLE);

    Menu menu(window, "Graphics/StartScreen.png");

    menu.Loop();

    Game game(window);
    while (window->isOpen())
    {
        game.StartGame();
        game.Loop();
        menu.Restart();
        menu.SetBG("Graphics/DeathScreen.png");
        menu.Loop();
    }

    return 0;
}