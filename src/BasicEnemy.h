#ifndef BASICENEMY_H
#define BASICENEMY_H

#include "GameObject.h"
#include "Handler.h"

class BasicEnemy : public GameObject {
public:

    BasicEnemy(sf::Vector2f position);

    ~BasicEnemy();

    void tick();

    void render(sf::RenderWindow& renderWindow);

    sf::FloatRect size() const;

private:
    sf::Sprite _sprite;

    float      _alpha;
};

#endif // BASICENEMY_H
