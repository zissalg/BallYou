#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject{
public:
    Player(sf::Vector2f position, sf::Vector2f velacity = sf::Vector2f(0.0f, 0.0f));

    ~Player();

    void tick();

    void render(sf::RenderWindow& renderWindow);

    sf::FloatRect size() const;

private:

    sf::Sprite _sprite;

};

#endif // PLAYER_H
