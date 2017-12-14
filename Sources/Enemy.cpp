#include "../Headers/Enemy.h"
#include "../Headers/GameObject.h"
#include <string>
#include <iostream>

bool Enemy::goLeft = true;
int Enemy::moveDown = 0;
float Enemy::movementSpeed = 10.0f;

Enemy::Enemy()
{
    this->col = Collision(this);
}

Enemy::Enemy(int alienType, sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale, sf::IntRect frameSize, int maxFrames)
            : GameObject (position, texture, scale, frameSize, maxFrames)
{
    this->alienType = alienType;
    this->alive = true;
    this->startPosY = position.y;
    this->col = Collision(this);
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

bool Enemy::checkCollision(const GameObject &other)
{
    return col.checkCollision(other);
}

void Enemy::move(sf::Vector2f direction, float dt)
{
    if (this->alive)
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

        GameObject::animate(this->movementSpeed);

        GameObject::getCharacter()->setPosition(GameObject::getCharacter()->getPosition().x, startPosY + moveDown);

    }

}

sf::Sprite& Enemy::getDrawable()
{
    return *GameObject::getCharacter();
}

void Enemy::draw(sf::RenderWindow* window)
{
    if (this->alive)
    {
        window->draw(*GameObject::getCharacter());
    }

}
bool Enemy::isAlive()
{
    return this->alive;
}

void Enemy::kill()
{
    this->alive = false;
}

void Enemy::setMovementSpeed(float speed)
{
    this->movementSpeed += speed;
}
