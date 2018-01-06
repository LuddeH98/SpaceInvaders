#include "../Headers/Shield.h"
#include <iostream>

Shield::Shield()
{
    cellsX = 8;
    cellsY = 6;
    cellWidth = 20;
    cellHeight = 20;

    pivot = sf::Vector2f((cellsX * cellWidth) / 2, (cellsY * cellHeight) / 2);
    position = sf::Vector2f();

    cells = new sf::RectangleShape*[cellsX];

    for (int i = 0; i < cellsX; i++)
    {
        cells[i] = new sf::RectangleShape[cellsY];
    }

    for (int i = 0; i < cellsX; i++)
    {
        for (int j = 0; j < cellsY; j++)
        {
            cells[i][j] = sf::RectangleShape(sf::Vector2f(cellWidth, cellHeight));
            cells[i][j].setOrigin(cellWidth / 2, cellHeight / 2);
            cells[i][j].setPosition((i * cellWidth), (j * cellHeight));
            cells[i][j].setFillColor(sf::Color::Green);

            if (i == 0 || i == cellsX - 1)
            {
                if (j == 0)
                {
                    cells[i][j].setFillColor(sf::Color::Black);
                }

            }

            if (i >= 2 && i <= cellsX - 3)
            {
                if (j == cellsY - 1)
                {
                    cells[i][j].setFillColor(sf::Color::Black);
                }
            }
        }
    }
}

Shield::~Shield()
{
    for (int i = 0; i < cellsX; i++)
    {
        delete[] cells[i];
    }
    delete[] cells;
}

bool Shield::checkCollision(int i, int j, Bullet &other)
{
    bool collide = false;

    if (cells[i][j].getFillColor() != sf::Color::Black)
    {
        collide = cells[i][j].getGlobalBounds().intersects(other.getRect());
        if (collide)
        {
            cells[i][j].setFillColor(sf::Color::Black);
            //cells[i][j].setPosition(cellWidth * -1, cellHeight * -1);
            other.setActive(false);
        }
    }

    return collide;
}

void Shield::setPosition(sf::Vector2f position)
{
    for (int i = 0; i < cellsX; i++)
    {
        for (int j = 0; j < cellsY; j++)
        {
            cells[i][j].setPosition(position.x + (i * cellWidth) -  pivot.x, position.y + (j * cellHeight));
        }
    }
}

void Shield::reset()
{
    for (int i = 0; i < cellsX; i++)
    {
        for (int j = 0; j < cellsY; j++)
        {
            cells[i][j].setFillColor(sf::Color::Green);

            if (i == 0 || i == cellsX - 1)
            {
                if (j == 0)
                {
                    cells[i][j].setFillColor(sf::Color::Black);
                }
            }

            if (i >= 2 && i <= cellsX - 3)
            {
                if (j == cellsY - 1)
                {
                    cells[i][j].setFillColor(sf::Color::Black);
                }
            }
        }
    }
}

float Shield::getHeight()
{
    return this->cellsY;
}
float Shield::getWidth()
{
    return this->cellsX;
}

void Shield::draw(sf::RenderWindow *window)
{
    for (int i = 0; i < cellsX; i++)
    {
        for (int j = 0; j < cellsY; j++)
        {
            window->draw(cells[i][j]);
        }
    }
}
