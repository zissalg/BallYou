#ifndef BUTTON_H
#define BUTTON_H

#include "GameWidget.h"
#include "Text.h"

class Button : public GameWidget {
public:
    Button();

    Button(std::string msg, sf::Vector2f pos, sf::Vector2f size);

    ~Button();

    void render(sf::RenderWindow& renderWindow);

    void tick();

    void update();

    void connect(void (*callback)());

    void setMsg(std::string msg);

    void mouseClicked(sf::Event &event);

    void mouseReleased(sf::Event &event);

    void mouseMoved(sf::Event &event);

private:

    bool isHovered(float mouseX, float mouseY);

    Text       _text;
    sf::Sprite _sprite;
    void       (*_callback)();

};

#endif // BUTTON_H
