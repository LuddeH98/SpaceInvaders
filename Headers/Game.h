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
    sf::Event* event;
    int winWidth;
    int winHeight;
    int gameState;
    float timeScale;
    float resumeTime;

    // GameObjects
    Player* player;
    std::string playerName;


    int aliensX;
    int aliensY;
    Enemy** aliens;
    int nrOfAliens;
    int alienOffset;
    float alienScaleFactor;

    GameObject** gameObjs;
    int nrOfGameObjects;


    Shield shieldMid;
    Shield shieldRight;
    Shield shieldLeft;

    //Game textures
    sf::Texture* playerTexture;
    sf::Texture* alienType1Texture;
    sf::Texture* alienType2Texture;
    sf::Texture* alienType3Texture;

    InputManager input;
    GUI textLayer;

    bool loadTexture(std::string path, sf::Sprite object);
    void shieldColDetection(Bullet& bul);
    void freeUpMemory();
    void render();
    void start();

public:
    Game(sf::RenderWindow* window, sf::Event* event);
    ~Game();

    int getGameState();
    void setGameState(int state);
    float getTimeScale();
    void update(float &deltaTime, float &gameTime);
    void setTimeScale(float timeScale);
    void restart();
    void setPlayerName(std::string name);


};

#endif
