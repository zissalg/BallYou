#ifndef DETECTOR_H
#define DETECTOR_H

#include "Handler.h"
#include "GameObject.h"

class Detector
{
public:
    Detector(Handler* handler);

    ~Detector();

    bool check();

private:

    Handler* _handler;
};

#endif // DETECTOR_H
