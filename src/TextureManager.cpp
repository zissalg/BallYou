#include "TextureManager.h"

TextureManager::TextureManager()
{
    MyTexture texture;
    texture.fileName = "textures/unknown.png";
    texture.texture.loadFromFile(texture.fileName);
    _textures.push_back(texture);
}

TextureManager::~TextureManager()
{

}

TextureManager& TextureManager::instance()
{
    static TextureManager texMan;

    return texMan;
}

sf::Texture& TextureManager::find(std::string fileName)
{
    if (isFileExist(fileName) == false)
        return _textures.front().texture;

    for (auto it = _textures.begin(); it != _textures.end(); ++it)
        if ((*it).fileName == fileName)
            return (*it).texture;

    MyTexture texture;
    texture.fileName = fileName;
    texture.texture.loadFromFile(texture.fileName);

    _textures.push_back(texture);

    return _textures.back().texture;
}

bool TextureManager::isFileExist(const std::string &fileName)
{
    std::ifstream is(fileName);
    return is.good();
}
