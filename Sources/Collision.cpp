#include "../Headers/Collision.h"

Collision::Collision(GameObject* owner, GameObject** objs, int nrOfObjs)
{
    this->objs = objs;
    this->nrOfObjs = nrOfObjs;
    this->owner = owner;
}

Collision::~Collision()
{

}

int Collision::checkCollision()
{
    int index = -1;
    for (int i = 0; i < this->nrOfObjs && index == -1; i++)
    {
        if (owner->getCharacter()->getGlobalBounds().intersects(objs[i]->getCharacter()->getGlobalBounds()))
        {
            index = i;
        }
    }
    return index;
}
