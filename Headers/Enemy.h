#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <string>
#include "../Headers/GameObject.h"

class Enemy : public GameObject
{
private:
    static bool goLeft;
    static int moveDown;
    float movementSpeed;
    float startPosY;
    int alienType;
    bool alive;

public:
    Enemy();
    Enemy(int alienType, sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale, sf::IntRect frameSize, int maxFrames);
    ~Enemy();

    Enemy(const Enemy &other);
    Enemy& operator=(const Enemy &other);

    sf::Sprite& getDrawable();
    virtual void move(sf::Vector2f direction, float dt);
    void kill();

};

#endif
