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
    this->aliensX = 5;
    this->aliensY = 3;
    this->aliens = new Enemy*[aliensX];
    for (int i = 0; i < aliensX; i++)
    {
        this->aliens[i] = new Enemy[aliensY];
    }

    for (int i = 0; i < aliensX; i++)
    {
        for (int j = 0; j < aliensY; j++)
        {
            this->aliens[i][j] = Enemy(2, sf::Vector2f(winWidth / 2 + (100 * i) , 100 + (j * 70)), alienType2Texture, sf::Vector2f(3.0f, 3.0f), sf::IntRect(0,0, 25, 20), 2);
        }
    }

    // Saving all gameobjects in a array to easily manage them while
    this->nrOfGameObjects = (this->aliensX * this->aliensY) + 1;
    this->gameObjs = new GameObject*[nrOfGameObjects];

    this->gameObjs[0] = player;
    //Player has been added manuallay
    for (int i = 1; i < nrOfGameObjects; i++)
    {
        for (int j = 0; j < nrOfGameObjects; j++)
        {
            gameObjs[i * j] = &aliens[i][j];
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
            aliens[i][j].move(sf::Vector2f(1.0f, 0.0f), deltaTime * timeScale);
        }
    }

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
            window->draw(aliens[i][j].getDrawable());

        }
    }

    // Draw Player
    window->draw(player->getDrawable());
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
