#include "../Headers/Game.h"
#include "../Headers/InputManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(sf::RenderWindow* window, sf::Event* event)
{
    this->window = window;
    this->winWidth = window->getSize().x;
    this->winHeight = window->getSize().y;
    this->timeScale = 1.5f;
    this->textLayer = GUI(window);
    this->event = event;
    this->gameState = 1;

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

    this->playerTexture->loadFromFile("Resources/player.png");
    this->alienType1Texture->loadFromFile("Resources/Alien1.png");
    this->alienType2Texture->loadFromFile("Resources/Alien2.png");
    this->alienType3Texture->loadFromFile("Resources/Alien3.png");

    // Initializing and spawning the player
    this->player = new Player(window, playerName, sf::Vector2f(winWidth / 2, winHeight - 200), playerTexture, sf::Vector2f(4.0f, 4.0f));
    this->textLayer.setPoints(player->getScore());
    this->textLayer.setLivesTexture(playerTexture);

    // Initializing an array with x alines wide, and y aliens high
    this->aliensX = 11;
    this->aliensY = 5;
    this->nrOfAliens = aliensX * aliensY;
    this->aliens = new Enemy*[aliensX];
    for (int i = 0; i < aliensX; i++)
    {
        this->aliens[i] = new Enemy[aliensY];
    }

    alienOffset = 105;
    alienScaleFactor = 3.0f;

    for (int i = 0; i < aliensX; i++)
    {
        for (int j = 0; j < aliensY; j++)
        {
            if (j == 0)
            {
                this->aliens[i][j] = Enemy(window ,3, sf::Vector2f(winWidth / 4 + (alienOffset * i) , 100 + (j * alienOffset)), alienType3Texture, sf::Vector2f(alienScaleFactor, alienScaleFactor), sf::IntRect(0,0, 16, 16), 2);
            }
            else if (j < 3)
            {
                this->aliens[i][j] = Enemy(window, 2, sf::Vector2f(winWidth / 4 + (alienOffset * i) , 100 + (j * alienOffset)), alienType2Texture, sf::Vector2f(alienScaleFactor, alienScaleFactor), sf::IntRect(0,0, 22, 16), 2);
            }
            else
            {
                this->aliens[i][j] = Enemy(window, 1, sf::Vector2f(winWidth / 4 + (alienOffset * i) , 100 + (j * alienOffset)), alienType1Texture, sf::Vector2f(alienScaleFactor, alienScaleFactor), sf::IntRect(0,0, 24, 16), 2);
            }

            if (j == aliensY - 1)
            {
                this->aliens[i][j].setCanShoot(true);
            }
            else
            {
                this->aliens[i][j].setCanShoot(false);
            }
        }
    }

    this->shieldMid.setPosition(sf::Vector2f(winWidth / 2, winHeight - (winHeight / 4)));
    this->shieldRight.setPosition(sf::Vector2f(winWidth - (winWidth / 4), winHeight - (winHeight / 4)));
    this->shieldLeft.setPosition(sf::Vector2f(winWidth / 4, winHeight - (winHeight / 4)));

}

void Game::update(float &deltaTime, float &gameTime)
{
    // In Main menu

    if (gameState == 1)
    {
        if (textLayer.textContainsMouse('s') && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            gameState = 2;

            restart();
        }

        if (textLayer.textContainsMouse('h') && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            gameState = 3;
        }

        if (textLayer.textContainsMouse('q') && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            window->close();
        }

    }

    if (gameState == 3)
    {
        if (textLayer.textContainsMouse('b') && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            gameState = 1;
        }
    }

    // In Game

    if (player->isAlive() && player->getLives() >= 0 && gameState == 2)
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
                        if (j - 1 >= 0)
                        {
                            aliens[i][j - 1].setCanShoot(true);
                            //std::cout << "alien[" << i << "][" << j - 1 << "] can now shoot" << std::endl;

                        }

                        //std::cout << "col with alien[" << i << "][" << j << "]" << std::endl;
                        aliens[i][j].setMovementSpeed(4.0f);

                        player->addScore(aliens[i][j].getAlienType() * 10);
                        textLayer.setPoints(player->getScore());
                    }

                    aliens[i][j].shoot();
                    aliens[i][j].move(sf::Vector2f(1.0f, 0.0f), deltaTime * timeScale);


                    // If player gets hit
                    if (aliens[i][j].getBulletBounds().checkCollision(*player) && aliens[i][j].getBulletBounds().isActive())
                    {
                        aliens[i][j].getBulletBounds().setActive(false);
                        player->kill();
                        textLayer.setLivesLeft(player->getLives());
                        resumeTime = gameTime + 10;

                        if (player->getLives() < 0)
                        {
                            gameState = 3;
                            textLayer.setPoints(player->getScore());
                        }
                    }

                    shieldColDetection(aliens[i][j].getBulletBounds());
                }

            }
        }
        shieldColDetection(player->getBullet());
    }

    // Resume the game when player being respawned
    else
    {
        if (gameTime > resumeTime)
        {
            player->revive();
        }
        else
        {
            // TODO: Player death animation
        }

    }



    render();
}

//
void Game::shieldColDetection(Bullet& bul)
{
    for (int i = 0; i < shieldMid.getWidth(); i++)
    {
        for (int j = 0; j < shieldMid.getHeight(); j++)
        {
            shieldMid.checkCollision(i, j, bul);
            shieldLeft.checkCollision(i, j, bul);
            shieldRight.checkCollision(i, j, bul);
        }
    }
}

void Game::render()
{

    window->clear();

    if (gameState == 2)
    {
        //Draw Aliens
        for (int i = 0; i < aliensX; i++)
        {
            for (int j = 0; j < aliensY; j++)
            {
                if (aliens[i][j].isAlive())
                {
                    aliens[i][j].draw(window);
                    aliens[i][j].drawBullet();
                }

            }
        }

        // Draw Player
        shieldMid.draw(window);
        shieldLeft.draw(window);
        shieldRight.draw(window);

        player->draw(window);
        player->drawBullet();
    }

    textLayer.draw(gameState);
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

void Game::setGameState(int state)
{
    this->gameState = state;
}

int Game::getGameState()
{
    return this->gameState;
}

void Game::restart()
{
    this->player->reset();
    this->player->revive();
    this->player->setPosition(sf::Vector2f(window->getSize().x / 2, player->getPosition().y));
    this->textLayer.setLivesLeft(3);
    this->textLayer.setPoints(player->getScore());

    for (int i = 0; i < aliensX; i++)
    {
        for (int j = 0; j < aliensY; j++)
        {
            this->aliens[i][j].revive();
            this->aliens[i][j].resetBullet();
            this->aliens[i][j].setPosition(sf::Vector2f(winWidth / 4 + (alienOffset * i) , 100 + (j * alienOffset)));

            if (j == aliensY -1)
            {
                this->aliens[i][j].setCanShoot(true);
            }
            else
            {
                this->aliens[i][j].setCanShoot(false);
            }
        }
    }

    shieldLeft.reset();
    shieldMid.reset();
    shieldRight.reset();
}

void Game::setPlayerName(std::string name)
{
    this->playerName = name;
    player->setPlayerName(name);
}
