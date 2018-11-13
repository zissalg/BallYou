#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Include.h"
#include "GameType.h"
#include "TextureManager.h"

class GameObject {
public:
    GameObject();

    virtual ~GameObject();

    virtual void tick() = 0;

    virtual void render(sf::RenderWindow& renderWindow) = 0;

    virtual sf::FloatRect size() const;

    sf::Vector2f position() const;

    void setPosition(const sf::Vector2f& position);

    sf::Vector2f vel() const;

    void setVelX(float velX);

    void setVelY(float velY);

    void setVel(const sf::Vector2f& vel);

    GameType type() const;

    void setType(const GameType& type);

    bool isConflict(const GameObject& obj);

protected:

    GameObject(GameType type, sf::Vector2f position, sf::Vector2f velacity = sf::Vector2f(0.0f, 0.0f));

    GameType     _type;
    sf::Vector2f _position;
    sf::Vector2f _vel;
};

#endif // GAMEOBJECT_H
