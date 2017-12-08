#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <string>

class Game
{
private:
    sf::RenderWindow* window;
    int winWidth;
    int winHeight;
    float timeScale;

    Player* player;

    int aliensX;
    int aliensY;
    Enemy** aliens;

    GameObject** gameObjs;
    int nrOfGameObjects;

    sf::Texture* playerTexture;
    sf::Texture* alienType1Texture;
    sf::Texture* alienType2Texture;
    sf::Texture* alienType3Texture;

    InputManager input;

    bool loadTexture(std::string path, sf::Sprite object);
    void freeUpMemory();
    void render();
    void start();

public:
    Game(sf::RenderWindow* window);
    ~Game();

    float getTimeScale();
    void update(float &deltaTime, float &gameTime);
    void setTimeScale(float timeScale);


};

#endif
