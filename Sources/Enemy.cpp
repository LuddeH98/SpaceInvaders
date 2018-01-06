#include "../Headers/Enemy.h"
#include "../Headers/GameObject.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

bool Enemy::goLeft = true;
int Enemy::moveDown = 0;
float Enemy::movementSpeed = 10.0f;

Enemy::Enemy()
{

}

Enemy::Enemy(sf::RenderWindow* window, int alienType, sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale, sf::IntRect frameSize, int maxFrames)
            : GameObject (position, texture, scale, frameSize, maxFrames)
{
    this->alienType = alienType;
    this->alive = true;
    this->startPosY = position.y;
    this->canShoot = false;
    this->freeFireLine = false;
    this->window = window;
    this->bul = Bullet(window);
    this->bul.setColor(sf::Color::Red);
    this->bul.setMovementSpeed(20.0f);

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
    this->window = other.window;
    this->bul = other.bul;
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
        this->window = other.window;
        this->bul = other.bul;
    }

    return *this;
}

void Enemy::move(sf::Vector2f direction, float dt)
{
    if (this->alive)
    {
        if (this->goLeft)
        {
            if (getPosition().x < 50)
            {
                this->goLeft = false;
                this->moveDown += 30;
            }
            else
            {
                GameObject::move((direction * -1.0f) * dt * movementSpeed);
            }

        }
        else
        {
            if (GameObject::getPosition().x > 1550)
            {
                this->goLeft = true;
                this->moveDown += 30;
            }
            else
            {
                GameObject::move((direction) * dt * movementSpeed);
            }
        }


        if (this->bul.isActive())
        {
            this->bul.move(sf::Vector2f(0, 20), dt);
        }

        GameObject::animate(this->movementSpeed);

        GameObject::setPosition(sf::Vector2f(GameObject::getPosition().x, startPosY + moveDown));

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

void Enemy::revive()
{
    this->alive = true;
}

void Enemy::setMovementSpeed(float speed)
{
    this->movementSpeed += speed;
}

void Enemy::setCanShoot(bool state)
{
    this->freeFireLine = state;
}

void Enemy::drawBullet()
{
    if (this->bul.isActive())
    {
        this->bul.draw(window);
    }

}

void Enemy::shoot()
{
    if (freeFireLine)
    {
        if (canShoot)
        {
            if (5 > rand() % 10000)
            {
                this->bul.launch(this->getPosition());
                this->bul.setActive(true);
                canShoot = false;
            }

        }
        else if (!this->bul.isActive() && !canShoot)
        {
            canShoot = true;
        }
        //std::cout << "yo" << std::endl;
    }

}

Bullet& Enemy::getBulletBounds()
{
    return this->bul;
}

void Enemy::resetBullet()
{
    this->bul.setPosition(this->getPosition());
    this->bul.setActive(false);
}

void Enemy::setPosition(sf::Vector2f pos)
{
    GameObject::setPosition(pos);
}

int Enemy::getAlienType()
{
    return alienType;
}
