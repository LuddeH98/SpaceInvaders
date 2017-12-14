#include "../Headers/Game.h"
#include "../Headers/InputManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(sf::RenderWindow* window)
{
    this->window = window;
    this->winWidth = window->getSize().x;
    this->winHeight = window->getSize().y;
    this->timeScale = 1.5f;

    start();

}

Game::~Game()
{
    freeUpMemory();
}

void Game::start()
{
    // This memory allocation will be deleted by the GameObject
    this->playerTexture = new sf::Texture();
    this->alienType1Texture = new sf::Texture();
    this->alienType2Texture = new sf::Texture();
    this->alienType3Texture = new sf::Texture();

    this->playerTexture->loadFromFile("/Users/ludwighansson/Desktop/SpaceInvaders/Resources/player.png");
    this->alienType1Texture->loadFromFile("/Users/ludwighansson/Desktop/SpaceInvaders/Resources/Alien1.png");
    this->alienType2Texture->loadFromFile("/Users/ludwighansson/Desktop/SpaceInvaders/Resources/Alien2.png");
    this->alienType3Texture->loadFromFile("/Users/ludwighansson/Desktop/SpaceInvaders/Resources/Alien3.png");

    // Initializing and spawning the player
    this->player = new Player("Ron", sf::Vector2f(winWidth / 2, winHeight - 100), playerTexture, sf::Vector2f(5.0f, 5.0f));

    // Initializing an array with x alines wide, and y aliens high
    this->aliensX = 8;
    this->aliensY = 4;
    this->nrOfAliens = aliensX * aliensY;
    this->aliens = new Enemy*[aliensX];
    for (int i = 0; i < aliensX; i++)
    {
        this->aliens[i] = new Enemy[aliensY];
    }

    for (int i = 0; i < aliensX; i++)
    {
        for (int j = 0; j < aliensY; j++)
        {
            this->aliens[i][j] = Enemy(2, sf::Vector2f(winWidth / 4 + (110 * i) , 100 + (j * 100)), alienType2Texture, sf::Vector2f(3.5f, 3.5f), sf::IntRect(0,0, 25, 20), 2);
        }
    }
}

void Game::update(float &deltaTime, float &gameTime)
{
    player->movement(deltaTime, timeScale);

    for (int i = 0; i < aliensX; i++)
    {
        for (int j = 0; j < aliensY; j++)
        {
            if (aliens[i][j].isAlive())
            {
                if (aliens[i][j].checkCollision(player->getBullet()) && player->getBullet().isActive())
                {
                    aliens[i][j].kill();
                    player->getBullet().setActive(false);
                    nrOfAliens--;
                    std::cout << "col with alien[" << i << "][" << j << "]" << std::endl;
                    aliens[i][j].setMovementSpeed(8.0f);
                }

                //std::cout << "movementspeed: " << 60.0f / (nrOfAliens * 0.25f) << std::endl;
                aliens[i][j].move(sf::Vector2f(1.0f, 0.0f), deltaTime * timeScale);
            }

        }
    }

    ;

    render();
}

void Game::render()
{

    window->clear();

    //Draw Aliens
    for (int i = 0; i < aliensX; i++)
    {
        for (int j = 0; j < aliensY; j++)
        {
            aliens[i][j].draw(window);
        }
    }

    // Draw Player
    player->draw(window);
    window->display();
}


void Game::freeUpMemory()
{
    delete this->player;

    for (int i = 0; i < aliensX; i++)
    {
        delete[] aliens[i];
    }
    delete[] aliens;

    this->playerTexture = nullptr;
    this->alienType1Texture = nullptr;
    this->alienType2Texture = nullptr;
    this->alienType3Texture = nullptr;

}

float Game::getTimeScale()
{
    return this->timeScale;
}

void Game::setTimeScale(float timeScale)
{
    this->timeScale = timeScale;
}
