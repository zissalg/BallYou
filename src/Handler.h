#ifndef HANDLER_H
#define HANDLER_H

#include "GameObject.h"

class Handler {
public:
    Handler();

    ~Handler();

    void run(sf::RenderWindow& renderWindow);

    GameObject* addObject(GameObject* obj);

    void removeObject(GameObject* obj);

private:

    std::list<GameObject*> _objects;
};

#endif // HANDLER_H
