#ifndef WINDOW_H
#define WINDOW_H

#include "Include.h"

class Window {
public:
    Window(std::string title, int width, int height);

    ~Window();

    void begin();

    void end();

    bool isOpen();

    sf::RenderWindow& renderWindow();

private:

    sf::RenderWindow _renderWindow;
};

#endif // WINDOW_H
