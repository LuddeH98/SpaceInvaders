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

};

#endif
