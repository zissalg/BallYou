#ifndef MOUSEINPUT_H
#define MOUSEINPUT_H

#include "Handler.h"

class MouseInput {
public:
    MouseInput(Handler* handler);

    ~MouseInput();

    void mouseClicked(sf::Event& event);

    void mouseReleased(sf::Event& event);

    void mouseMoved(sf::Event& event);

private:

    Handler* _handler;
};

#endif // MOUSEINPUT_H
