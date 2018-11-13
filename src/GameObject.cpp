#include "GameObject.h"

sf::Texture unknownTexture = TextureManager::instance().find("textures/unknown.png");
sf::Sprite unknownSprite = sf::Sprite(unknownTexture);

GameObject::GameObject()
{

}

GameObject::GameObject(GameType type, sf::Vector2f position, sf::Vector2f velacity)
    : _type(type)
    , _position(position)
    , _vel(velacity)
{

}

GameObject::~GameObject()
{

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

void GameObject::setVelX(float velX)
{
    _vel.x = velX;
}

void GameObject::setVelY(float velY)
{
    _vel.y = velY;
}

void GameObject::setVel(const sf::Vector2f& vel)
{
    _vel = vel;
}

GameType GameObject::type() const
{
    return _type;
}

sf::FloatRect GameObject::size() const
{
    return sf::FloatRect(0.f, 0.f, 0.f, 0.f);
}

void GameObject::setType(const GameType& type)
{
    _type = type;
}

bool GameObject::isConflict(const GameObject &obj)
{
    int d1x = _position.x - (obj._position.x + obj.size().width);
    int d1y = _position.y - (obj._position.y + obj.size().height);
    int d2x = obj._position.x - (_position.x + size().width);
    int d2y = obj._position.y - (_position.y + size().height);

    if (d1x >= 0 || d1y >= 0)
        return false;

    if (d2x >= 0 || d2y >= 0)
        return false;

    return true;
}
