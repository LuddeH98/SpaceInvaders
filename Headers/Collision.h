#ifndef COLLISION_H
#define COLLISION_H

#include "../Headers/GameObject.h"
#include <SFML/Graphics.hpp>

class Collision
{
private:
    GameObject* owner;
    GameObject** objs;
    int nrOfObjs;

public:
    Collision();
    Collision(GameObject* owner, GameObject** objs, int nrOfObjs);
    ~Collision();

    int checkCollision();

};

#endif
