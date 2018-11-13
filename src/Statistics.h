#ifndef STATISTICS_H
#define STATISTICS_H

#include "Include.h"
#include "Text.h"
#include "GameObject.h"
#include "Handler.h"

class Statistics {
public:
    Statistics(Handler* handler);

    ~Statistics();

    void reset();

    void increase();

    void decrease();

    void render(sf::RenderWindow& renderWindow);

    bool nextWave();

    int  level();

    void levelUp();


private:
    Handler* _handler;
    uint     _score;
    uint     _level;
    uint     _maxScore;
    Text     _scoreText;
    Text     _levelText;
    Text     _infoText;

};

#endif // STATISTICS_H
