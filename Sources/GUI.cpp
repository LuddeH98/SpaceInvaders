#include "../Headers/GUI.h"

GUI::GUI()
{
    this->logoTexture = nullptr;
    this->logoSprite = nullptr;
    this->font = nullptr;
}

GUI::GUI(sf::RenderWindow* window)
{
    this->window = window;
    this->points = 0;
    this->font = new sf::Font();
    this->font->loadFromFile("Resources/ca.ttf");
    this->initialized = false;
    this->livesLeft = 3;

    mainMenu();
    endScrren();


}

GUI::~GUI()
{
    //delete this->font;
    //delete this->logoSprite;
}

void GUI::draw(int state)
{
    if (state == 1)
    {
        window->draw(*logoSprite);
        window->draw(startText);
        window->draw(highScoreText);
        window->draw(quitText);
        window->draw(markers);
    }

    else if (state == 2)
    {
        if (!initialized)
        {
            inGame();
            initialized = true;
        }

        score.setString("SCORE <" + std::to_string(points) + ">");
        window->draw(bottomRect);
        window->draw(score);

        for (int i = 0; i < livesLeft; i++)
        {
            window->draw(lives[i]);
        }
    }

    else if (state == 3)
    {
        this->playerScore.setString("Your score <" + std::to_string(points) + ">");
        window->draw(gameOver);
        window->draw(goToMainMenu);
        window->draw(playerScore);
    }

    else
    {
        markers.setPosition(-100, -100);
    }
}

void GUI::mainMenu()
{

    // Logo
    this->logoTexture = new sf::Texture();
    this->logoTexture->loadFromFile("Resources/Logo.png");
    this->logoSprite = new sf::Sprite(*logoTexture);
    this->logoSprite->setScale(3.0f, 3.0f);
    this->logoSprite->setOrigin(this->logoSprite->getLocalBounds().width / 2,
                                this->logoSprite->getLocalBounds().height / 2);
    this->logoSprite->setPosition(window->getSize().x / 2, window->getSize().y / 4);
    this->logoSprite->setColor(sf::Color::Green);

    // Start Game text setup
    this->startText = sf::Text("Start Game", *font, 30);
    this->startText.setScale(2.0f, 2.0f);
    this->startText.setPosition(window->getSize().x / 2, window->getSize().y / 2 + 50);
    this->startText.setOrigin(this->startText.getLocalBounds().width / 2,
                                this->startText.getLocalBounds().height / 2);

    // Highscore Text setup
    this->highScoreText = sf::Text("Highscore", *font, 30);
    this->highScoreText.setScale(2.0f, 2.0f);
    this->highScoreText.setPosition(window->getSize().x / 2, window->getSize().y / 2 + 150);
    this->highScoreText.setOrigin(this->highScoreText.getLocalBounds().width / 2,
                                this->highScoreText.getLocalBounds().height / 2);
    // Quit Game text setup
    this->quitText = sf::Text("Quit Game", *font, 30);
    this->quitText.setScale(2.0f, 2.0f);
    this->quitText.setPosition(window->getSize().x / 2, window->getSize().y / 2 + 250);
    this->quitText.setOrigin(this->quitText.getLocalBounds().width / 2,
                                this->quitText.getLocalBounds().height / 2);


    this->markers = sf::Text(">>            <<", *font, 30);
    this->markers.setScale(2.0f, 2.0f);
    this->markers.setPosition(-window->getSize().x / 2, - window->getSize().y / 2 + 250);
    this->markers.setFillColor(sf::Color::Green);
    this->markers.setOrigin(this->markers.getLocalBounds().width / 2,
                                this->markers.getLocalBounds().height / 2);


}

void GUI::inGame()
{
    bottomRect = sf::RectangleShape(sf::Vector2f(window->getSize().x, window->getSize().y / 250));
    bottomRect.setFillColor(sf::Color(sf::Color::Green));
    bottomRect.setOrigin(bottomRect.getLocalBounds().width / 2, bottomRect.getLocalBounds().height / 2);
    bottomRect.setPosition(window->getSize().x / 2, window->getSize().y - 140);

    score = sf::Text("SCORE <" + std::to_string(points) + ">", *font, 50);
    score.setFillColor(sf::Color(sf::Color::Green));
    score.setScale(0.8f, 0.8f);
    score.setPosition(20, 10);

    for (int i = 0; i < 3; i++)
    {
        lives[i] = sf::Sprite(*livesTexture);
        lives[i].setScale(2.5f, 2.5f);
        lives[i].setPosition((i * 80) + 20, window->getSize().y - 80);
    }
}

void GUI::endScrren()
{
    this->gameOver = sf::Text("<< Game Over >>", *font, 30);
    this->gameOver.setScale(3.0f, 3.0f);
    this->gameOver.setPosition(window->getSize().x / 2, window->getSize().y / 6);
    this->gameOver.setFillColor(sf::Color(sf::Color::Red));
    this->gameOver.setOrigin(this->gameOver.getLocalBounds().width / 2,
                                this->gameOver.getLocalBounds().height / 2);

    // Last round score
    this->playerScore = sf::Text("Your score <" + std::to_string(points) + ">", *font, 30);
    this->playerScore.setScale(2.0f, 2.0f);
    this->playerScore.setPosition(window->getSize().x / 2, window->getSize().y / 3);
    this->playerScore.setOrigin(this->playerScore.getLocalBounds().width / 2,
                                this->playerScore.getLocalBounds().height / 2);

    // Go to main menu
    this->goToMainMenu = sf::Text("Go to Main menu", *font, 30);
    this->goToMainMenu.setScale(2.0f, 2.0f);
    this->goToMainMenu.setPosition(window->getSize().x / 2, window->getSize().y / 2 + 300);
    this->goToMainMenu.setOrigin(this->goToMainMenu.getLocalBounds().width / 2,
                                this->goToMainMenu.getLocalBounds().height / 2);
}

bool GUI::textContainsMouse(char button)
{
    bool contains = false;
    sf::Text check;

    switch (button)
    {
        case 's':
        {
            check = startText;
            break;
        }
        case 'h':
        {
            check = highScoreText;
            break;
        }

        case 'q':
        {
            check = quitText;
            break;
        }

        case 'b':
        {
            check = goToMainMenu;
            break;
        }

        default:
        {

        }
    }

    if (check.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
    {
        contains = true;

        if (check.getPosition() != sf::Vector2f(0,0) && check.getPosition() != goToMainMenu.getPosition())
        {
            markers.setPosition(check.getPosition());
        }

        else
        {
            markers.setPosition(sf::Vector2f(-100, -100));
        }

    }

    return contains;
}

void GUI::setPoints(int points)
{
    this->points = points;
}

void GUI::setLivesTexture(sf::Texture *texture)
{
    this->livesTexture = texture;
}

void GUI::setLivesLeft(int lives)
{
    this->livesLeft = lives;
}
