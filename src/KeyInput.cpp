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

    if (event.key.code == sf::Keyboard::A)
        player->setVelX(-5);
    if (event.key.code == sf::Keyboard::D)
        player->setVelX(+5);
    if (event.key.code == sf::Keyboard::W)
        player->setVelY(-5);
    if (event.key.code == sf::Keyboard::S)
        player->setVelY(+5);


}

void KeyInput::keyReleased(sf::Event &event)
{
    GameObject* player = _handler->getPlayer();

    if (event.key.code == sf::Keyboard::A)
        player->setVelX(0);
    if (event.key.code == sf::Keyboard::D)
        player->setVelX(0);
    if (event.key.code == sf::Keyboard::W)
        player->setVelY(0);
    if (event.key.code == sf::Keyboard::S)
        player->setVelY(0);

}
