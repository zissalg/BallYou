#ifndef WINDOW_H
#define WINDOW_H

#include "Include.h"
#include "KeyInput.h"
#include "MouseInput.h"

class Window {
public:
    Window(std::string title, int width, int height);

    ~Window();

    void setKeyInput(KeyInput* keyInput);

    void setMouseInput(MouseInput* mouseInput);

    void begin();

    void end();

    bool isOpen();

    sf::RenderWindow& renderWindow();

private:

    KeyInput*        _keyInput;

    MouseInput*      _mouseInput;

    sf::RenderWindow _renderWindow;
};

#endif // WINDOW_H
