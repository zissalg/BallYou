#ifndef WAVE_H
#define WAVE_H

#include "Include.h"
#include "Handler.h"
#include "BasicEnemy.h"

class Wave {
public:
    Wave(Handler* handler);

    ~Wave();

    bool load(std::string fileName);

    void clean();

private:
    Handler* _handler;

    std::list<GameObject*> _objects;
};

#endif // WAVE_H
