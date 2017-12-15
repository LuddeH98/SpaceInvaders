#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "../Headers/InputManager.h"
#include "../Headers/GameObject.h"
#include "../Headers/Player.h"
#include "../Headers/Shield.h"
#include "../Headers/Enemy.h"
#include "../Headers/GUI.h"


#include <string>

class Game
{
private:
    // Window and rendering
    sf::RenderWindow* window;
    int winWidth;
    int winHeight;
    float timeScale;

    // GameObjects
    Player* player;

    int aliensX;
    int aliensY;
    Enemy** aliens;
    int nrOfAliens;

    GameObject** gameObjs;
    int nrOfGameObjects;


    Shield test;

    //Game textures
    sf::Texture* playerTexture;
    sf::Texture* alienType1Texture;
    sf::Texture* alienType2Texture;
    sf::Texture* alienType3Texture;

    InputManager input;
    GUI textLayer;

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
