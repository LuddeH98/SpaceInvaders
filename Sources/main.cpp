#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "../Headers/Game.h"

using namespace std;

int main()
{
    int screenScale = 2;
    int screenWidth = 800 * screenScale;
    int screenHeight = 800 * screenScale;

    clock_t t = clock();
    float deltaTime = 0.0f;
    //float lastFrame = 0.0f;
    float totalTime = 0.0f;

    sf::Clock clck;

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), "Space Invaders", sf::Style::Close);
    sf::Event* event = new sf::Event();

    sf::Sprite r;

    Game game = Game(window, event);

    std::cout << "Player Name: ";
    std::string playerName = "Ron";
    //getline(cin, playerName);
    game.setPlayerName(playerName);

    while (window->isOpen())
    {

        deltaTime = (float)clck.restart().asSeconds();

        while (window->pollEvent(*event))
        {
            switch (event->type)
            {
                case sf::Event::Closed:
                {
                    window->close();
                    break;
                }

                default:
                {
                    break;
                }
            }


        }

        totalTime += ((float)t / CLOCKS_PER_SEC);

        // Draw here...
        game.update(deltaTime, totalTime);

    }

    delete window;
    delete event;

    return 0;
}
