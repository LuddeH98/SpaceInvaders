#include <SFML/Graphics.hpp>
#include "../Headers/GameObject.h"
#include <iostream>

GameObject::GameObject()
{
    this->character = new sf::Sprite();
    this->character->setPosition(sf::Vector2f(0,0));
    //this->character->setOrigin(character->getLocalBounds().width / 2, character->getLocalBounds().height / 2);
}

GameObject::GameObject(sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale)
{
    this->character = new sf::Sprite();
    this->character->setPosition(position);
    this->character->setTexture(*texture, true);
    this->character->setScale(scale);
    this->character->setOrigin(character->getLocalBounds().width / 2, character->getLocalBounds().height / 2);
}

GameObject::GameObject(sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale, sf::IntRect frameSize, int maxFrames)
{
    this->character = new sf::Sprite();
    this->character->setPosition(position);
    this->character->setTexture(*texture, true);
    this->character->setScale(scale);
    this->character->setTextureRect(frameSize);
    this->character->setOrigin(character->getLocalBounds().width / 2, character->getLocalBounds().height / 2);
    this->anim = Animator(this->character, &frameSize, maxFrames);
}

GameObject::~GameObject()
{

}

GameObject::GameObject(const GameObject &other)
{
    this->character = other.character;
    this->anim = other.anim;
}

GameObject& GameObject::operator=(const GameObject &other)
{
    if (this != &other)
    {
        this->character = other.character;
        this->anim = other.anim;
    }
    return *this;

}

void GameObject::setSprite(sf::Sprite* sprite)
{
    delete this->character;
    this->character = sprite;
}

void GameObject::setPosition(sf::Vector2f position)
{
    this->character->setPosition(position);
}

void GameObject::setSpriteColor(sf::Color color)
{
    this->character->setColor(color);
}

sf::Vector2f GameObject::getPosition()
{
    return this->character->getPosition();
}

bool GameObject::checkCollision(const GameObject &other)
{
    return this->character->getGlobalBounds().intersects(other.character->getGlobalBounds());
}

Animator* GameObject::getAnimator()
{
    return &this->anim;
}

void GameObject::animate(float speed)
{
    this->anim.animate();
    this->anim.setAnamtionSpeed(speed);
}

void GameObject::draw(sf::RenderWindow* window)
{
    window->draw(*this->character);
}

void GameObject::move(sf::Vector2f direction)
{
    this->character->move(direction);
}


sf::FloatRect GameObject::getRect() const
{
    return this->character->getGlobalBounds();
}
