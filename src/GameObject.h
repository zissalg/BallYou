#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Include.h"
#include "GameType.h"
#include "TextureManager.h"

class GameObject {
public:
    GameObject();

    GameObject(GameType type, sf::Vector2f position, sf::Vector2f velacity = sf::Vector2f(0.0f, 0.0f));

    virtual ~GameObject();

    virtual void tick();

    virtual void render(sf::RenderWindow& renderWindow);

    sf::Vector2f position() const;

    void setPosition(const sf::Vector2f& position);

    sf::Vector2f vel() const;

    void setVel(const sf::Vector2f& vel);

private:

    GameType     _type;
    sf::Vector2f _position;
    sf::Vector2f _vel;
};

#endif // GAMEOBJECT_H
