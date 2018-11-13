#include "Text.h"

Text::Text(std::string text, sf::Vector2f pos, uint size)
{
    _text.setFont(FontManager::instance().find("fonts/orange kid.ttf"));
    _text.setCharacterSize(size);
    _text.setString(text);
    _text.setPosition(pos);
}

Text::~Text()
{

}

void Text::tick()
{
}

void Text::render(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(_text);
}

void Text::setText(std::string text)
{
    _text.setString(text);
}
