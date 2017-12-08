#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "../Headers/Animator.h"

class GameObject
{
private:
    sf::Sprite* character;
    Animator anim;

public:

    GameObject();
    GameObject(sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale);
    GameObject(sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale,
                sf::IntRect frameSize, int maxFrames);
    ~GameObject();

    GameObject(const GameObject &other);
    GameObject& operator=(const GameObject &other);

    sf::Vector2f getPosition();
    sf::Sprite* getCharacter();
    GameObject* getGameObject();

    void setCharacter(sf::Sprite Character);
    virtual void move(sf::Vector2f direction, float dt) = 0;
    void animate();

};

#endif
