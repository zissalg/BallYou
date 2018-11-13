#include "Player.h"

Player::Player(sf::Vector2f pos, sf::Vector2f vel)
    : GameObject(GameType::Ally, pos, vel)
    , _sprite(TextureManager::instance().find("textures/player.png"))
{

}

Player::~Player()
{

}

void Player::tick()
{
    sf::Vector2f tempPos = _position + _vel;

    if (tempPos.x >= 800 - 16)
        return;
    if (tempPos.x <= 0)
        return;
    if (tempPos.y >= 600 - 16)
        return;
    if (tempPos.y <= 0)
        return;

    _position = tempPos;
    _sprite.setPosition(_position);
}

void Player::render(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(_sprite);
}

sf::FloatRect Player::size() const
{
    return _sprite.getGlobalBounds();
}
