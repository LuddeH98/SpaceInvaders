#include "../Headers/Enemy.h"
#include "../Headers/GameObject.h"
#include <string>
#include <iostream>

bool Enemy::goLeft = true;
int Enemy::moveDown = 0;

Enemy::Enemy()
{

}

Enemy::Enemy(int alienType, sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale, sf::IntRect frameSize, int maxFrames)
            : GameObject (position, texture, scale, frameSize, maxFrames)
{
    this->alienType = alienType;
    this->alive = true;
    this->movementSpeed = 100.0f;
    this->startPosY = position.y;
}

Enemy::~Enemy()
{

}

Enemy::Enemy(const Enemy &other) : GameObject(other)
{
    this->alienType = other.alienType;
    this->alive = other.alive;
    this->movementSpeed = other.movementSpeed;
    this->startPosY = other.startPosY;
}

Enemy& Enemy::operator=(const Enemy &other)
{
    if (this != &other)
    {
        GameObject::operator=(other);
        this->alienType = other.alienType;
        this->alive = other.alive;
        this->movementSpeed = other.movementSpeed;
        this->startPosY = other.startPosY;
    }

    return *this;
}

void Enemy::move(sf::Vector2f direction, float dt)
{
    if (this->goLeft)
    {
        if (GameObject::getCharacter()->getPosition().x < 50)
        {
            this->goLeft = false;
            this->moveDown += 30;
        }
        else
        {
            GameObject::getCharacter()->move((direction * -1.0f) * dt * movementSpeed);
        }
        //std::cout << "Left: " << goLeft << std::endl;

    }
    else
    {
        if (GameObject::getCharacter()->getPosition().x > 1550)
        {
            this->goLeft = true;
            this->moveDown += 30;
        }
        else
        {
            GameObject::getCharacter()->move((direction) * dt * movementSpeed);
        }
        //std::cout << "right: " << goLeft << std::endl;
    }

    GameObject::animate();

    GameObject::getCharacter()->setPosition(GameObject::getCharacter()->getPosition().x, startPosY + moveDown);

}

sf::Sprite& Enemy::getDrawable()
{
    return *GameObject::getCharacter();
}
