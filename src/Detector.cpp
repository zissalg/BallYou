#include "Detector.h"

Detector::Detector(Handler* handler)
    : _handler(handler)
{

}

Detector::~Detector()
{

}

bool Detector::check()
{
    GameObject* player = _handler->getPlayer();
    for (auto obj : _handler->getAllObjects())
        if (obj != player && player->isConflict(*obj))
            return true;

    return false;
}
