#ifndef HANDLER_H
#define HANDLER_H

#include "GameObject.h"
#include "Widgets/GameWidget.h"

class Handler {
public:
    Handler();

    ~Handler();

    void        render(sf::RenderWindow& renderWindow);

    void        tick();

    GameObject* addObject(GameObject* obj);

    void        removeObject(GameObject* obj);

    void        removeAllObjects();

    GameWidget* addWidget(GameWidget* widget);

    void        removeWidget(GameWidget* widget);

    void        removeAllWidgets();

    GameObject* getPlayer();

    std::list<GameObject*> getAllObjects();

    std::list<GameWidget*> getAllWidgets();

private:

    std::list<GameObject*> _objects;
    std::list<GameWidget*> _widgets;
};

#endif // HANDLER_H
