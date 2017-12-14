#include "../Headers/Bullet.h"

Bullet::Bullet() : GameObject()
{
    this->active = false;
    this->movementSpeed = 50.0f;

    // Dynamically allocated texture will be deleted by the sprite
    this->tex = new sf::Texture();
    this->tex->loadFromFile("/Users/ludwighansson/Desktop/SpaceInvaders/Resources/bullet.png");
    this->GameObject::getCharacter()->setTexture(*tex, true);
    this->GameObject::getCharacter()->setOrigin(GameObject::getCharacter()->getLocalBounds().width / 2, GameObject::getCharacter()->getLocalBounds().height / 2);
    this->GameObject::getCharacter()->setScale(2, 2);
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
    GameObject::getCharacter()->setPosition(startPos);
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
        if (GameObject::getCharacter()->getPosition().y < -50)
        {
            this->active = false;
        }
        GameObject::getCharacter()->move(direction * dt * movementSpeed);
    }
}

void Bullet::draw(sf::RenderWindow* window)
{
    if (this->active)
    {
        window->draw(*GameObject::getCharacter());
    }

}
