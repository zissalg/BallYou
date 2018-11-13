#include "Window.h"
#include "Handler.h"
#include "Player.h"
#include "BasicEnemy.h"
#include "Detector.h"
#include "Statistics.h"
#include "Wave.h"

#define MAX_WAVE 3

Handler mainHandler;
Window mainWindow("Ball You", 800, 600);
KeyInput mainKeyInput(&mainHandler);
Detector mainDetector(&mainHandler);
Statistics mainStatistics(&mainHandler);
Wave mainWave(&mainHandler);

bool mainRunning = true;

void init();

void loop();

int main()
{
    init();
    loop();
    return 0;
}

void init()
{
    srand(time(nullptr));

    mainWindow.setKeyInput(&mainKeyInput);
    mainHandler.addObject(new Player(sf::Vector2f(800 / 2 - 32, 600 / 2 - 32)));

    mainWave.load("waves/wave" + std::to_string(mainStatistics.level()) + ".txt");
}

void loop()
{
    while (mainWindow.isOpen())
    {
        mainWindow.begin();

        if (mainRunning)
        {

            mainHandler.tick();

            mainStatistics.increase();

            if (mainDetector.check() || mainStatistics.nextWave())
            {

                if (mainStatistics.nextWave())
                {
                    mainWave.clean();

                    if (mainStatistics.level() < MAX_WAVE)
                    {
                        mainStatistics.levelUp();
                        mainWave.load("waves/wave" + std::to_string(mainStatistics.level()) + ".txt");
                    } else
                    {
                        mainRunning = false;
                        continue;
                    }
                }

                mainStatistics.reset();
                mainHandler.getPlayer()->setPosition(sf::Vector2f(800 / 2 - 32, 600 / 2 - 32));

            }

        }

        mainHandler.render(mainWindow.renderWindow());
        mainStatistics.render(mainWindow.renderWindow());

        mainWindow.end();

    }
}
