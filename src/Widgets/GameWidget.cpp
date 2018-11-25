#include "GameWidget.h"

GameWidget::GameWidget()
{

}

GameWidget::GameWidget(sf::Vector2f pos, sf::Vector2f size)
    : _position(pos)
    , _size(size)
    , _hidden(false)
{

}

void GameWidget::hide(bool hidden)
{
    _hidden = hidden;
}

sf::Vector2f GameWidget::position() const
{
    return _position;
}

void GameWidget::setPosition(const sf::Vector2f& position)
{
    _position = position;
    update();
}

sf::Vector2f GameWidget::size() const
{
    return _size;
}

void GameWidget::setSize(const sf::Vector2f& size)
{
    _size = size;
    update();
}
