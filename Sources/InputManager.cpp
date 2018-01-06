#include "../Headers/InputManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

InputManager::InputManager()
{
    this->isPressed = false;
}

InputManager::~InputManager()
{

}

bool InputManager::getKey(sf::Keyboard::Key inputKey) const
{
    bool isPressed = false;

    if (sf::Keyboard::isKeyPressed(inputKey))
    {
        isPressed = true;
    }

    return isPressed;
}

bool InputManager::getKeyDown(sf::Keyboard::Key inputKey) const
{
    return false;//event->type == sf::Event::KeyPressed && event->key.code == inputKey;
}

bool InputManager::getKeyReleased(sf::Keyboard::Key inputKey, sf::Event* event) const
{
    return event->type == sf::Event::KeyReleased && event->key.code == inputKey;
}
