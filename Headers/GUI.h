#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

class GUI
{
private:
    sf::RenderWindow* window;

    // Menu states
    void mainMenu();
    void inGame();
    void endScrren();

public:
    GUI();
    GUI(sf::RenderWindow* window);

    void draw(int state);

};

#endif
