#include "Button.h"

Button::Button(std::string msg, sf::Vector2f pos, sf::Vector2f size)
    : GameWidget(pos, size)
    , _text(msg, pos, 24)
    , _sprite(TextureManager::instance().find("textures/button.png"))
    , _callback(nullptr)
{
    update();
}

Button::~Button()
{

}

void Button::setMsg(std::string msg)
{
    _text.setMsg(msg);
    update();
}

void Button::render(sf::RenderWindow& renderWindow)
{
    if (_hidden)
        return;

    renderWindow.draw(_sprite);
    _text.render(renderWindow);
}

void Button::tick()
{

}

void Button::update()
{
    sf::Vector2f factor;
    factor.x = _size.x / _sprite.getGlobalBounds().width;
    factor.y = _size.y / _sprite.getGlobalBounds().height;

    _sprite.setPosition(_position);
    _sprite.setScale(factor);

    sf::Vector2f textPos;
    textPos.x = _position.x + _sprite.getGlobalBounds().width / 2 - _text.globSize().x / 2;
    textPos.y = _position.y + _sprite.getGlobalBounds().height / 2 - _text.globSize().y;

    _text.setPosition(textPos);
}

void Button::connect(void (*callback)())
{
    _callback = callback;
}

void Button::mouseClicked(sf::Event &event)
{
    if (_hidden)
        return;

    if (event.mouseButton.button != sf::Mouse::Left)
        return;

    if (isHovered(event.mouseButton.x, event.mouseButton.y))
    {
        if (_callback)
            _callback();
        _sprite.setColor(sf::Color(255, 200, 200, 255));
    }
}

void Button::mouseMoved(sf::Event &event)
{
}

void Button::mouseReleased(sf::Event &event)
{
    if (event.mouseButton.button != sf::Mouse::Left)
        return;

    _sprite.setColor(sf::Color(255, 255, 255, 255));
}

bool Button::isHovered(float mouseX, float mouseY)
{
    if (   mouseX > _position.x
        && mouseY > _position.y
        && mouseX < _position.x + _sprite.getGlobalBounds().width
        && mouseY < _position.y + _sprite.getGlobalBounds().height)
        return true;

    return false;
}

