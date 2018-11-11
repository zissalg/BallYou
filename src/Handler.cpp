#include "Handler.h"

Handler::Handler()
{

}

Handler::~Handler()
{
    for (auto obj : _objects)
        delete obj;
}

void Handler::run(sf::RenderWindow& renderWindow)
{
    for (auto obj : _objects)
    {
        obj->tick();
        obj->render(renderWindow);
    }
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
