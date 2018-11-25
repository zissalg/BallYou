#ifndef MENU_H
#define MENU_H

#include "GameWidget.h"
#include "Button.h"

class Menu : public GameWidget{
public:
    Menu(sf::Vector2f pos, uint rows);

    ~Menu();

    void render(sf::RenderWindow& renderWindow);

    void tick();

    void update();

    void setMsg(std::string msg, uint row);

    void connect(void (*callback)(), uint row);

    void mouseClicked(sf::Event& event);

    void mouseReleased(sf::Event& event);

    void mouseMoved(sf::Event& event);

    void hide(bool hidden);

private:

    std::vector<Button*> _buttons;
};

#endif // MENU_H
