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

public:
    Bullet();
    //Bullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale);
    ~Bullet();

    float getMovementSpeed();
    bool isActive();

    void launch(sf::Vector2f position);
    void setMovementSpeed(float speed);
    void setActive(bool active);
    virtual void move(sf::Vector2f direction, float dt);
    virtual void draw(sf::RenderWindow* window);



};

#endif
