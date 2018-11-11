#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Include.h"

class TextureManager {
public:

    struct MyTexture {
        sf::Texture texture;
        std::string fileName;
    };

    static TextureManager& instance();

public:

    sf::Texture& find(std::string fileName);

    void free(std::string fileName);

private:
    TextureManager();

    ~TextureManager();

    bool isFileExist(const std::string& fileName);

    std::list<MyTexture> _textures;
};

#endif // TEXTUREMANAGER_H
