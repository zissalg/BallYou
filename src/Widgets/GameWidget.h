#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "../Include.h"
#include "../TextureManager.h"

class GameWidget {
public:
    GameWidget();

    GameWidget(sf::Vector2f pos, sf::Vector2f);

    virtual ~GameWidget() {}

    virtual void tick() = 0;

    virtual void render(sf::RenderWindow& renderWindow) = 0;

    virtual void update() = 0;

    virtual void mouseClicked(sf::Event& event) {}

    virtual void mouseReleased(sf::Event& event) {}

    virtual void mouseMoved(sf::Event& event) {}

    virtual void hide(bool hidden);

    sf::Vector2f position() const;

    void setPosition(const sf::Vector2f& position);

    sf::Vector2f size() const;

    void setSize(const sf::Vector2f& size);

protected:

    bool         _hidden;

    sf::Vector2f _position;

    sf::Vector2f _size;
};

#endif // GAMEWIDGET_H
