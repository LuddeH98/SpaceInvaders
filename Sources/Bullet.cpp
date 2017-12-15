#include "../Headers/Bullet.h"
#include <iostream>

Bullet::Bullet(sf::RenderWindow* window) : GameObject()
{
    this->active = false;
    this->movementSpeed = 70.0f;

    // Dynamically allocated texture will be deleted by the sprite
    this->tex = new sf::Texture();
    this->tex->loadFromFile("/Users/ludwighansson/Desktop/SpaceInvaders/Resources/bullet.png");

    sf::Sprite* temp = new sf::Sprite();

    temp->setTexture(*tex, true);
    temp->setOrigin(temp->getLocalBounds().width / 2, temp->getLocalBounds().height / 2);
    temp->setScale(2.5f, 2.5f);
    temp->setColor(sf::Color::Green);

    setSprite(temp);

    this->window = window;

}

Bullet::~Bullet()
{

}

float Bullet::getMovementSpeed()
{
    return this->movementSpeed;
}

bool Bullet::isActive()
{
    return this->active;
}

void Bullet::launch(sf::Vector2f startPos)
{
    this->active = true;
    setPosition(startPos);
}

void Bullet::setMovementSpeed(float speed)
{
    this->movementSpeed = speed;
}

void Bullet::setActive(bool active)
{
    this->active = active;
}

void Bullet::move(sf::Vector2f direction, float dt)
{
    if (this->active)
    {
        if (getPosition().y < -50)
        {
            this->active = false;
        }
        GameObject::move(direction * dt * movementSpeed);
        //std::cout << window << std::endl;
    }
}
