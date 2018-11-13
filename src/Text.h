#ifndef TEXT_H
#define TEXT_H

#include "GameObject.h"
#include "FontManager.h"

class Text {
public:
    Text(std::string text, sf::Vector2f pos, uint size);

    ~Text();

    void tick();

    void render(sf::RenderWindow &renderWindow);

    void setText(std::string text);

private:

    sf::Text _text;

};

#endif // TEXT_H
