#include <SFML/Graphics.hpp>
#include "../Headers/Animator.h"
#include <iostream>

Animator::Animator()
{
    this->animObj = nullptr;
    this->currentFrame = 0;
    this->maxFrames = 0;
    this->frameSize = sf::IntRect();
    this->updateTime = 0.0f;
    this->t = clock();
    this->animationSpeed = 10;
}

Animator::Animator(sf::Sprite* sprite, sf::IntRect* frameSize, int maxFrames, float animationSpeed)
{
    this->animObj = sprite;
    this->currentFrame = 0;
    this->maxFrames = maxFrames - 1;
    this->frameSize = *frameSize;
    this->t = clock();
    this->updateTime = 0.0f;
    this->animationSpeed = animationSpeed;
}

Animator::~Animator()
{
    animObj = nullptr;
}

Animator::Animator(const Animator& other)
{
    this->animObj = other.animObj;
    this->currentFrame = other.currentFrame;
    this->maxFrames = other.maxFrames;
    this->frameSize = other.frameSize;
    this->updateTime = other.updateTime;
    this->animationSpeed = other.animationSpeed;
}

Animator& Animator::operator= (const Animator &other)
{
    delete this->animObj;

    if (this != &other)
    {
        this->animObj = other.animObj;
        this->currentFrame = other.currentFrame;
        this->maxFrames = other.maxFrames;
        this->frameSize = other.frameSize;
        this->updateTime = other.updateTime;
        this->animationSpeed = other.animationSpeed;
    }
    //std::cout << "Yo" << std::endl;
    return *this;
}

void Animator::animate()
{
    updateTime += (float)t / CLOCKS_PER_SEC;

    if (updateTime * (animationSpeed * 0.75) > 1000)
    {
        if (currentFrame < maxFrames)
        {
            this->currentFrame++;
            this->frameSize.left += this->frameSize.width;
        }
        else
        {
            this->frameSize.left = 0;
            this->currentFrame = 0;
        }
        //std::cout << frameSize.left << std::endl;
        animObj->setTextureRect(this->frameSize);
        updateTime = 0.0f;
    }


}

float Animator::getAnimationSpeed()
{
    return this->animationSpeed;
}

void Animator::setAnamtionSpeed(float speed)
{
    this->animationSpeed = speed;
}
