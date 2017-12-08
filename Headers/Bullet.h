#ifndef BULLET_H
#define BULLET_H

#include "../Headers/GameObject.h"
#include "../Headers/Collision.h"

class Bullet : public GameObject
{
private:
    GameObject** objs;
    int nrOfObjs;
    float movementSpeed;
    bool active;
    Collision col;

public:
    Bullet(GameObject** objs, int nrOfObjs, sf::Vector2f position, sf::Texture* texture, sf::Vector2f scale);
    ~Bullet();

    float getMovementSpeed();
    bool isActive();

    void setMovementSpeed(float speed);
    void setActive(bool active);
    virtual void move(sf::Vector2f direction, float dt);



};

#endif
