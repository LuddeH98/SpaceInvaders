#include "../Headers/Collision.h"

Collision::Collision(GameObject* owner)
{
    this->owner = owner;
}

Collision::Collision()
{

}

Collision::~Collision()
{

}

int Collision::checkCollision(const GameObject &other) const
{
    return (owner->getCharacter()->getGlobalBounds().intersects(other.getCharacter()->getGlobalBounds()));
}
