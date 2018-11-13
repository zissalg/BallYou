#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include "Include.h"

class FontManager
{
public:

    struct MyFont {
        sf::Font font;
        std::string fileName;
    };

    static FontManager& instance();

public:

    sf::Font& find(std::string fileName);

    void free(std::string fileName);

private:
    FontManager();

    ~FontManager();

    bool isFileExist(const std::string& fileName);

    std::list<MyFont> _fonts;
};

#endif // FONTMANAGER_H
