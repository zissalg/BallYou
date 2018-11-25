#include "BasicEnemy.h"

BasicEnemy::BasicEnemy(sf::Vector2f pos)
    : GameObject(GameType::Enemy, pos, sf::Vector2f(5.f, 5.f))
    , _sprite(TextureManager::instance().find("textures/basic_enemy.png"))
{
    if (rand() % 2)
        _vel.x = -5.f;

    if (rand() % 2)
        _vel.y = -5.f;

}

BasicEnemy::~BasicEnemy()
{

}

void BasicEnemy::render(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(_sprite);
}

void BasicEnemy::tick()
{
    _position += _vel;

    if (_position.x >= 800 - size().width || _position.x <= 0) _vel.x *= -1;
    if (_position.y >= 600 - size().height || _position.y <= 0) _vel.y *= -1;

    //_handler->addObject(new Trail(_position, "textures/basic_enemy.png", _handler));

    _sprite.setPosition(_position);
}

sf::FloatRect BasicEnemy::size() const
{
    return _sprite.getLocalBounds();
}
