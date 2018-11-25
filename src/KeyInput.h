#ifndef KEYINPUT_H
#define KEYINPUT_H

#include "Handler.h"

class KeyInput {
public:
    KeyInput(Handler* handler);

    ~KeyInput();

    void keyPressed(sf::Event& event);

    void keyReleased(sf::Event& event);

    bool isKeyPressed(int key);
private:
    Handler* _handler;
    bool     _key[1024];
};

#endif // KEYINPUT_H
