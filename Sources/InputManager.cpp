#include "../Headers/InputManager.h"
#include <SFML/Graphics.hpp>

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
