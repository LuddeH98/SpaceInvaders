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
    this->textLayer = GUI(window);

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
    this->player = new Player(window, "Ron", sf::Vector2f(winWidth / 2, winHeight - 200), playerTexture, sf::Vector2f(4.0f, 4.0f));

    // Initializing an array with x alines wide, and y aliens high
    this->aliensX = 11;
    this->aliensY = 5;
    this->nrOfAliens = aliensX * aliensY;
    this->aliens = new Enemy*[aliensX];
    for (int i = 0; i < aliensX; i++)
    {
        this->aliens[i] = new Enemy[aliensY];
    }

    int alienOffset = 105;
    float alienScaleFactor = 3.0f;

    for (int i = 0; i < aliensX; i++)
    {
        for (int j = 0; j < aliensY; j++)
        {
            if (j == 0)
            {
                this->aliens[i][j] = Enemy(3, sf::Vector2f(winWidth / 4 + (alienOffset * i) , 100 + (j * alienOffset)), alienType3Texture, sf::Vector2f(alienScaleFactor, alienScaleFactor), sf::IntRect(0,0, 16, 16), 2);
            }
            else if (j < 2)
            {
                this->aliens[i][j] = Enemy(2, sf::Vector2f(winWidth / 4 + (alienOffset * i) , 100 + (j * alienOffset)), alienType2Texture, sf::Vector2f(alienScaleFactor, alienScaleFactor), sf::IntRect(0,0, 22, 16), 2);
            }
            else
            {
                this->aliens[i][j] = Enemy(1, sf::Vector2f(winWidth / 4 + (alienOffset * i) , 100 + (j * alienOffset)), alienType1Texture, sf::Vector2f(alienScaleFactor, alienScaleFactor), sf::IntRect(0,0, 24, 16), 2);
            }


        }
    }

    this->test.setPosition(sf::Vector2f(winWidth / 2, winHeight - (winHeight / 4)));
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
                    aliens[i][j].setMovementSpeed(4.0f);
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
            if (aliens[i][j].isAlive())
            {
                aliens[i][j].draw(window);
            }

        }
    }

    // Draw Player
    test.draw(window);
    textLayer.draw(2);
    player->draw(window);
    player->drawBullet();
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
