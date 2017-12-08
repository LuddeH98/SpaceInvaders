#include "../Headers/Bullet.h"

Bullet::Bullet(GameObject** objs, int nrOfObjs, sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale) : GameObject(position, texture, scale)
{
    this->objs = objs;
    this->active = false;
    this->movementSpeed = 1.0f;
    this->nrOfObjs = nrOfObjs;
    this->col = Collision(GameObject::getGameObject(), objs, nrOfObjs);
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
    if ()
    {

    }
}
