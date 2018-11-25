#include "Handler.h"

Handler::Handler()
{

}

Handler::~Handler()
{
    for (auto obj : _objects)
        delete obj;

    for (auto wdt : _widgets)
        delete wdt;
}

void Handler::tick()
{
    for (auto obj : _objects)
        if (obj != nullptr)
            obj->tick();

    for (auto wdt : _widgets)
        if (wdt != nullptr)
            wdt->tick();
}

void Handler::render(sf::RenderWindow& renderWindow)
{
    for (auto obj : _objects)
        obj->render(renderWindow);

    for (auto wdt : _widgets)
        wdt->render(renderWindow);
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

void Handler::removeAllObjects()
{
    std::list<GameObject*> copied = _objects;
    for (auto obj : copied)
        removeObject(obj);

    _objects.clear();
}

GameWidget*Handler::addWidget(GameWidget* widget)
{
    _widgets.push_back(widget);
    return widget;
}

void Handler::removeWidget(GameWidget *widget)
{
    _widgets.remove(widget);
}

void Handler::removeAllWidgets()
{
    std::list<GameWidget*> copied = _widgets;
    for (auto wdt : copied)
        removeWidget(wdt);

    _widgets.clear();
}

GameObject* Handler::getPlayer()
{
    for (auto obj : _objects)
        if (obj->type() == GameType::You)
            return obj;

    return nullptr;
}

std::list<GameObject*> Handler::getAllObjects()
{
    return _objects;
}

std::list<GameWidget*> Handler::getAllWidgets()
{
    return _widgets;
}
