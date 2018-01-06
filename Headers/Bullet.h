#ifndef BULLET_H
#define BULLET_H

#include "../Headers/GameObject.h"
#include <SFML/Graphics.hpp>

class Bullet : public GameObject
{
private:
    float movementSpeed;
    bool active;
    sf::Texture* tex;
    sf::RenderWindow* window;

public:
    Bullet(sf::RenderWindow* window = nullptr);
    ~Bullet();

    float getMovementSpeed();
    bool isActive();

    void launch(sf::Vector2f position);
    void setMovementSpeed(float speed);
    void setActive(bool active);
    void setColor(sf::Color color);
    void move(sf::Vector2f direction, float dt);



};

#endif
