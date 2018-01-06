#ifndef SHIELD_H
#define SHIELD_H

#include <SFML/Graphics.hpp>
#include "../Headers/GameObject.h"
#include "../Headers/Bullet.h"

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

    bool checkCollision(int i, int j, Bullet &other);
    void setPosition(sf::Vector2f position);
    float getHeight();
    float getWidth();
    void reset();
    void draw(sf::RenderWindow* window);
};

#endif
