#include "Window.h"

Window::Window(std::string title, int width, int height)
    : _renderWindow(sf::VideoMode(width, height), title)
{
    _renderWindow.setFramerateLimit(60);
}

Window::~Window()
{

}

void Window::setKeyInput(KeyInput *keyInput)
{
    _keyInput = keyInput;
}

void Window::setMouseInput(MouseInput* mouseInput)
{
    _mouseInput = mouseInput;
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

        case sf::Event::KeyPressed: _keyInput->keyPressed(event);
            break;

        case sf::Event::KeyReleased: _keyInput->keyReleased(event);
            break;

        case sf::Event::MouseButtonPressed: _mouseInput->mouseClicked(event);
            break;

        case sf::Event::MouseButtonReleased: _mouseInput->mouseReleased(event);
            break;

        case sf::Event::MouseMoved: _mouseInput->mouseMoved(event);
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
