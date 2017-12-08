#include <SFML/Graphics.hpp>
#include "../Headers/GameObject.h"
#include <iostream>

GameObject::GameObject()
{
    this->character = nullptr;
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

sf::Vector2f GameObject::getPosition()
{
    return this->character->getPosition();
}

sf::Sprite* GameObject::getCharacter()
{
    return this->character;
}

GameObject* GameObject::getGameObject()
{
    return this;
}

void GameObject::animate()
{
    this->anim.animate();
}
