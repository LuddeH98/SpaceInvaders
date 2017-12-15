#include "../Headers/GUI.h"

GUI::GUI()
{

}

GUI::GUI(sf::RenderWindow* window)
{
    this->window = window;
}

void GUI::draw(int state)
{
    if (state == 1)
    {

    }

    else if (state == 2)
    {
        inGame();
    }

    else
    {

    }
}

void GUI::mainMenu()
{

}

void GUI::inGame()
{
    sf::RectangleShape bottomRect(sf::Vector2f(window->getSize().x, window->getSize().y / 250));
    bottomRect.setFillColor(sf::Color(sf::Color::Green));
    bottomRect.setOrigin(bottomRect.getLocalBounds().width / 2, bottomRect.getLocalBounds().height / 2);
    bottomRect.setPosition(window->getSize().x / 2, window->getSize().y - 140);
    

    window->draw(bottomRect);
}

void GUI::endScrren()
{

}
