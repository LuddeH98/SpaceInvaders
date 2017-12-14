#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <string>
#include "../Headers/GameObject.h"
#include "../Headers/Collision.h"

class Enemy : public GameObject
{
private:
    static bool goLeft;
    static int moveDown;
    static float movementSpeed;
    float startPosY;
    int alienType;
    bool alive;
    Collision col;

public:
    Enemy();
    Enemy(int alienType, sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale, sf::IntRect frameSize, int maxFrames);
    ~Enemy();

    Enemy(const Enemy &other);
    Enemy& operator=(const Enemy &other);

    bool checkCollision(const GameObject &other);
    bool isAlive();
    sf::Sprite& getDrawable();
    virtual void move(sf::Vector2f direction, float dt);
    virtual void draw(sf::RenderWindow* window);
    void kill();
    void setMovementSpeed(float speed);

};

#endif
