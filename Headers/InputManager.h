#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Graphics.hpp>

class InputManager
{
private:
    bool isPressed;

public:
    InputManager();
    ~InputManager();

    bool getKey(sf::Keyboard::Key inputKey) const;
    bool getKeyDown(sf::Keyboard::Key inputKey) const;
    bool getKeyReleased(sf::Keyboard::Key inputKey, sf::Event* event) const;

};

#endif
