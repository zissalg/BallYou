#include "Text.h"

Text::Text(std::string msg, sf::Vector2f pos, uint size)
    : GameWidget(pos, sf::Vector2f(size, size))
    , _msg(msg)
{
    _text.setFont(FontManager::instance().find("fonts/orange kid.ttf"));
    update();
}

Text::~Text()
{

}

void Text::update()
{
    _text.setCharacterSize(_size.x);
    _text.setString(_msg);
    _text.setPosition(_position);
}

std::string Text::msg() const
{
    return _msg;
}

void Text::setMsg(const std::string& msg)
{
    _msg = msg;
    update();
}

sf::Vector2f Text::globSize()
{
    sf::Vector2f size;
    size.x = _text.getGlobalBounds().width;
    size.y = _text.getGlobalBounds().height;
    return size;
}

void Text::tick()
{

}

void Text::render(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(_text);
}
