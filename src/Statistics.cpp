#include "Statistics.h"

Statistics::Statistics(Handler* handler)
    : _handler(handler)
    , _score(0)
    , _level(1)
    , _maxScore(25)
    , _scoreText("", sf::Vector2f(30.f, 550.f), 24)
    , _levelText("", sf::Vector2f(30.f, 50.f), 24)
    , _infoText("", sf::Vector2f(30.f, 80.f), 24)
{

}

Statistics::~Statistics()
{

}

void Statistics::reset()
{
    _score = 0;
}

void Statistics::increase()
{
    ++_score;
}

void Statistics::decrease()
{
    --_score;
}

void Statistics::render(sf::RenderWindow& renderWindow)
{
    _scoreText.setText("Score: " + std::to_string(_score));
    _scoreText.render(renderWindow);

    _levelText.setText("Current Wave: " + std::to_string(_level));
    _levelText.render(renderWindow);

    _infoText.setText("Requiremenst: gain " + std::to_string(_maxScore) + " score");
    _infoText.render(renderWindow);
}

bool Statistics::nextWave()
{
    return _score >= _maxScore;
}

int Statistics::level()
{
    return _level;
}

void Statistics::levelUp()
{
    ++_level;
}
