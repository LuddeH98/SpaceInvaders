#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

class Animator
{
private:
    sf::Sprite* animObj;
    int currentFrame;
    int maxFrames;
    float updateTime;
    float animationSpeed;
    sf::IntRect frameSize;
    clock_t t;

public:
    Animator();
    Animator(sf::Sprite* sprite, sf::IntRect* frameSize, int maxFrames, float animationSpeed = 10);
    ~Animator();

    float getAnimationSpeed();

    void setAnamtionSpeed(float speed);

    Animator(const Animator& other);
    Animator& operator= (const Animator &other);

    void animate();
};

#endif
