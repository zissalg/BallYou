#include "FontManager.h"

FontManager::FontManager()
{

}

FontManager::~FontManager()
{

}

FontManager& FontManager::instance()
{
    static FontManager fontMan;
    return fontMan;
}

sf::Font& FontManager::find(std::string fileName)
{
    if (isFileExist(fileName) == false)
        return _fonts.front().font;

    for (auto it = _fonts.begin(); it != _fonts.end(); ++it)
        if ((*it).fileName == fileName)
            return (*it).font;

    MyFont font;
    font.fileName = fileName;
    font.font.loadFromFile(font.fileName);

    _fonts.push_back(font);

    return _fonts.back().font;
}

bool FontManager::isFileExist(const std::string &fileName)
{
    std::ifstream is(fileName);
    return is.good();
}

