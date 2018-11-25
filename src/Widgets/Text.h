#ifndef TEXT_H
#define TEXT_H

#include "GameWidget.h"
#include "../FontManager.h"

class Text : public GameWidget {
public:
    Text(std::string msg, sf::Vector2f pos, uint size);

    ~Text();

    void tick();

    void render(sf::RenderWindow &renderWindow);

    void update();

    std::string msg() const;

    void setMsg(const std::string& msg);

    sf::Vector2f globSize();

private:

    sf::Text _text;

    std::string _msg;

};

#endif // TEXT_H
