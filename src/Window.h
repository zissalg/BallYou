#ifndef WINDOW_H
#define WINDOW_H

#include "Include.h"
#include "KeyInput.h"

class Window {
public:
    Window(std::string title, int width, int height);

    ~Window();

    void setKeyInput(KeyInput* keyInput);

    void begin();

    void end();

    bool isOpen();

    sf::RenderWindow& renderWindow();

private:

    KeyInput*        _keyInput;

    sf::RenderWindow _renderWindow;
};

#endif // WINDOW_H
