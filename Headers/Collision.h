#ifndef COLLISION_H
#define COLLISION_H

#include "../Headers/GameObject.h"
#include <SFML/Graphics.hpp>

class Collision
{
private:
    GameObject* owner;

public:
    Collision();
    Collision(GameObject* owner);
    ~Collision();

    int checkCollision(const GameObject &other) const;

};

#endif
