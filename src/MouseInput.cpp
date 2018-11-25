#include "MouseInput.h"

MouseInput::MouseInput(Handler* handler)
    : _handler(handler)
{

}

MouseInput::~MouseInput()
{

}

void MouseInput::mouseClicked(sf::Event &event)
{
    for (auto wdt : _handler->getAllWidgets())
        wdt->mouseClicked(event);
}

void MouseInput::mouseReleased(sf::Event &event)
{
    for (auto wdt : _handler->getAllWidgets())
        wdt->mouseReleased(event);
}

void MouseInput::mouseMoved(sf::Event &event)
{
    for (auto wdt : _handler->getAllWidgets())
        wdt->mouseMoved(event);
}
