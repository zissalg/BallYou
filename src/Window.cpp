#include "Window.h"

Window::Window(std::string title, int width, int height)
    : _renderWindow(sf::VideoMode(width, height), title)
{
    _renderWindow.setFramerateLimit(60);
}

Window::~Window()
{

}

void Window::begin()
{
    sf::Event event;
    while (_renderWindow.pollEvent(event))
    {
        switch(event.type)
        {

        case sf::Event::Closed: _renderWindow.close();
            break;

        default:
            break;

        }
    }

    _renderWindow.clear();
}

void Window::end()
{
    _renderWindow.display();
}

bool Window::isOpen()
{
    return _renderWindow.isOpen();
}

sf::RenderWindow& Window::renderWindow()
{
    return _renderWindow;
}
