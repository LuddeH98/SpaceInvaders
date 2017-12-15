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

    void setSprite(sf::Sprite* sprite);
    void setPosition(sf::Vector2f position);

    bool checkCollision(const GameObject &other);

    sf::Vector2f getPosition();
    Animator* getAnimator();

    void move(sf::Vector2f direction);
    void draw(sf::RenderWindow* window);
    void animate(float speed);

};

#endif
