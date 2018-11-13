#ifndef KEYINPUT_H
#define KEYINPUT_H

#include "Include.h"
#include "Handler.h"

class KeyInput {
public:
    KeyInput(Handler* handler);

    ~KeyInput();

    void keyPressed(sf::Event& event);

    void keyReleased(sf::Event& event);
private:
    Handler* _handler;
    bool     _keys[128];
};

#endif // KEYINPUT_H
