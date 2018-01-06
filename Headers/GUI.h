#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

class GUI
{
private:
    sf::RenderWindow* window;
    sf::Texture* logoTexture;
    sf::Texture* livesTexture;
    sf::Sprite* logoSprite;
    sf::Font* font;
    int points;

    //Texts
    sf::Text startText;
    sf::Text highScoreText;
    sf::Text quitText;
    sf::Text markers;

    // In Game GUI
    sf::Sprite lives[3];
    sf::RectangleShape bottomRect;
    sf::Text score;
    bool initialized;
    int livesLeft;

    // End Screen text
    sf::Text gameOver;
    sf::Text highscore;
    sf::Text playerScore;
    sf::Text goToMainMenu;

    // Menu states
    void mainMenu();
    void inGame();
    void endScrren();

public:
    GUI();
    GUI(sf::RenderWindow* window);

    ~GUI();

    void draw(int state);
    bool textContainsMouse(char button);
    void setPoints(int points);
    void setLivesTexture(sf::Texture* texture);
    void setLivesLeft(int lives);

};

#endif
