#include "KeyInput.h"

KeyInput::KeyInput(Handler* handler)
    : _handler(handler)
{

}

KeyInput::~KeyInput()
{

}

void KeyInput::keyPressed(sf::Event &event)
{
    GameObject* player = _handler->getPlayer();

    if (player == nullptr)
        return;

    if (event.key.code == sf::Keyboard::A)
        player->setVelX(-5);
    else if (event.key.code == sf::Keyboard::D)
        player->setVelX(+5);
    else if (event.key.code == sf::Keyboard::W)
        player->setVelY(-5);
    else if (event.key.code == sf::Keyboard::S)
        player->setVelY(+5);



}

void KeyInput::keyReleased(sf::Event &event)
{
    GameObject* player = _handler->getPlayer();

    if (player == nullptr)
        return;

    sf::Vector2f vel = player->vel();

    if (event.key.code == sf::Keyboard::A && vel.x == -5)
        vel.x = 0;
    if (event.key.code == sf::Keyboard::D && vel.x == +5)
        vel.x = 0;
    if (event.key.code == sf::Keyboard::W && vel.y == -5)
        vel.y = 0;
    if (event.key.code == sf::Keyboard::S && vel.y == +5)
        vel.y = 0;

    player->setVel(vel);

}
