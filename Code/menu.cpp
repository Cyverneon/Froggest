#include "menu.h"


Menu::Menu(sf::RenderWindow* newWindow, std::string bgPath)
{
    window = newWindow;

    bgTexture.loadFromFile(bgPath);
    bg.setTexture(bgTexture);

    menuConfirmed = false;
}

void Menu::SetBG(std::string bgPath)
{
    bgTexture.loadFromFile(bgPath);
    bg.setTexture(bgTexture);
}

void Menu::Restart()
{
    menuConfirmed = false;
}

void Menu::Loop()
{
    while (window->isOpen() && !menuConfirmed)
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyReleased:
                if (sf::Keyboard::Key::Space == event.key.code)
                {
                    menuConfirmed = true;
                }
                break;
            }
        }

        window->clear();

        window->draw(bg);

        window->display();
    }
}