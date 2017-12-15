#ifndef SHIELD_H
#define SHIELD_H

#include <SFML/Graphics.hpp>
#include "../Headers/GameObject.h"

class Shield
{
private:
    sf::RectangleShape** cells;
    int cellsX;
    int cellsY;
    float cellWidth;
    float cellHeight;

    sf::Vector2f pivot;
    sf::Vector2f position;

public:
    Shield();
    ~Shield();

    bool checkCollision(const GameObject &other);
    void setPosition(sf::Vector2f position);
    void reset();
    void draw(sf::RenderWindow* window);
};

#endif
