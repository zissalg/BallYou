#include "Wave.h"

Wave::Wave(Handler* handler)
    : _handler(handler)
{

}

Wave::~Wave()
{
    clean();
}

bool Wave::load(std::string fileName)
{
    std::ifstream is(fileName);
    std::string buffer;
    int type = 0;
    size_t pos = 0;
    if (is.is_open() == false)
        return false;

    while (std::getline(is, buffer))
    {
        if (buffer == "[Type=1]") {
            type = 1;
            continue;
        }

        pos = buffer.find("Enemy=");
        if (type != 0 && pos != std::string::npos)
        {
            int countEnemies = std::stoi(buffer.substr(pos + 6));

            for (int i = 0; i < countEnemies; ++i)
            {
                int rx = rand() % (800 - 16);
                int ry = rand() % (600 - 16);

                switch(type)
                {
                case 1: _objects.push_back(_handler->addObject(new BasicEnemy(sf::Vector2f(rx, ry))));
                    break;
                default: break;
                }
            }
        }
    }

    return true;
}

void Wave::clean()
{
    for (auto obj : _objects)
        _handler->removeObject(obj);
}
