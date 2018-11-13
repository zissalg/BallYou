#include "Handler.h"

Handler::Handler()
{

}

Handler::~Handler()
{
    for (auto obj : _objects)
        delete obj;
}

void Handler::tick()
{
    for (auto obj : _objects)
        if (obj != nullptr)
            obj->tick();
}

void Handler::render(sf::RenderWindow& renderWindow)
{
    for (auto obj : _objects)
        obj->render(renderWindow);
}

GameObject* Handler::addObject(GameObject *obj)
{
    _objects.push_back(obj);
    return obj;
}

void Handler::removeObject(GameObject *obj)
{
    _objects.remove(obj);
}

GameObject* Handler::getPlayer()
{
    for (auto obj : _objects)
        if (obj->type() == GameType::Ally)
            return obj;

    return nullptr;
}

std::list<GameObject*> Handler::getAllObjects()
{
    return _objects;
}
