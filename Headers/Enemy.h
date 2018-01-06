#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <string>
#include "../Headers/GameObject.h"
#include "../Headers/Bullet.h"

class Enemy : public GameObject
{
private:
    static bool goLeft;
    static int moveDown;
    static float movementSpeed;
    float startPosY;
    int alienType;
    bool alive;
    bool canShoot;
    bool freeFireLine;

    Bullet bul;
    sf::RenderWindow* window;


public:
    Enemy();
    Enemy(sf::RenderWindow* window, int alienType, sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale, sf::IntRect frameSize, int maxFrames);
    ~Enemy();

    Enemy(const Enemy &other);
    Enemy& operator=(const Enemy &other);

    Bullet& getBulletBounds();

    bool isAlive();
    virtual void move(sf::Vector2f direction, float dt);
    
    void kill();
    void revive();
    void setMovementSpeed(float speed);
    void setCanShoot(bool state);
    void drawBullet();
    void shoot();
    void resetBullet();
    void setPosition(sf::Vector2f pos);
    void resetMoveDown();
    void resetMovementSpeed();
    int getAlienType();

};

#endif
