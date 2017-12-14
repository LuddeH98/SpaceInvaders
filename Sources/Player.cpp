#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Headers/GameObject.h"
#include "../Headers/Player.h"

Player::Player()
{
    this->score = 0;
    this->lives = 3;
    this->canShoot = true;
    this->name = "?";
    this->movementSpeed = 10.0f;
    this->input = InputManager();
    this->b = Bullet();

}

Player::Player(std::string name, sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale) : GameObject (position, texture, scale)
{
    this->score = 0;
    this->lives = 3;
    this->canShoot = true;
    this->name = name;
    this->movementSpeed = 20.0f;
    this->input = InputManager();
    this->b = Bullet();
}

Player::~Player()
{

}

int Player::getScore()
{
    return this->score;
}

int Player::getLives()
{
    return this->lives;
}

std::string Player::getName()
{
    return this->name;
}

Bullet& Player::getBullet()
{
    return this->b;
}

void Player::movement(float dt, int timeScale)
{
    if (input.getKey(sf::Keyboard::A) && getPosition().x > 70)
    {
        move(sf::Vector2f(-15.0f, 0.0f), dt * timeScale);
    }

    if (input.getKey(sf::Keyboard::D) && getPosition().x < 1600 - 70)
    {
        move(sf::Vector2f(15.0f, 0.0f), dt * timeScale);
    }

    if (input.getKey(sf::Keyboard::Space))
    {

        fire();

    }

    if (b.isActive())
    {
        b.move(sf::Vector2f(0, -20), dt);
    }
}

void Player::fire()
{
    if (!b.isActive())
    {
        b.launch(sf::Vector2f(GameObject::getCharacter()->getPosition()));
        b.setActive(true);
    }


}

void Player::addScore(int score)
{
    this->score += score;
}

void Player::setPosition(sf::Vector2f position)
{
    GameObject::getCharacter()->setPosition(position);
}

sf::Sprite Player::getDrawable()
{
    return *GameObject::getCharacter();
}

void Player::move(sf::Vector2f direction, float dt)
{
    GameObject::getCharacter()->move(direction * dt * movementSpeed);
}

void Player::draw(sf::RenderWindow* window)
{
    window->draw(*GameObject::getCharacter());
    b.draw(window);
}
