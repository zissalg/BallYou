#include "GameObject.h"

sf::Texture unknownTexture = TextureManager::instance().find("textures/unknown.png");
sf::Sprite unknownSprite = sf::Sprite(unknownTexture);

GameObject::GameObject()
{

}

GameObject::GameObject(GameType type, sf::Vector2f pos, sf::Vector2f vel)
    : _type(type)
    , _position(pos)
    , _vel(vel)
{
}

GameObject::~GameObject()
{

}

void GameObject::render(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(unknownSprite);
}

void GameObject::tick()
{
    _position += _vel;

    unknownSprite.setPosition(_position);
}

sf::Vector2f GameObject::position() const
{
    return _position;
}

void GameObject::setPosition(const sf::Vector2f& position)
{
    _position = position;
}

sf::Vector2f GameObject::vel() const
{
    return _vel;
}

void GameObject::setVel(const sf::Vector2f& vel)
{
    _vel = vel;
}
