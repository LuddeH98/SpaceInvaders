#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <SFML/Graphics.hpp>
#include "../Headers/GameObject.h"
#include "../Headers/InputManager.h"
#include "../Headers/Bullet.h"

class Player : public GameObject
{
private:
    int score;
    int lives;
    bool canShoot;
    bool alive;
    float movementSpeed;
    std::string name;
    InputManager input;
    sf::RenderWindow* window;
    Bullet b;

public:
    Player();
    Player(sf::RenderWindow* window, std::string name, sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale);
    virtual ~Player();

    int getScore();
    int getLives();
    std::string getName();
    Bullet& getBullet();

    void fire();
    void addScore(int score);
    void setPosition(sf::Vector2f position);
    bool kill();
    bool isAlive();
    void revive();
    sf::Sprite getDrawable();
    void drawBullet();
    void movement(float dt, int timeScale);
    virtual void move(sf::Vector2f direction, float dt);
    void setMovementSpeed(float speed);
    void reset();
    void setPlayerName(std::string name);

};

#endif
