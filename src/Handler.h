#ifndef HANDLER_H
#define HANDLER_H

#include "GameObject.h"

class Handler {
public:
    Handler();

    ~Handler();

    void render(sf::RenderWindow& renderWindow);

    void tick();

    GameObject* addObject(GameObject* obj);

    void removeObject(GameObject* obj);

    GameObject* getPlayer();

    std::list<GameObject*> getAllObjects();

private:

    std::list<GameObject*> _objects;
};

#endif // HANDLER_H
