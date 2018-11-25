#include "Window.h"
#include "Handler.h"
#include "Player.h"
#include "BasicEnemy.h"
#include "Detector.h"
#include "Widgets/Button.h"
#include "Widgets/Menu.h"

#define MAX_WAVE 3

Handler mainHandler;
Window mainWindow("Ball You", 800, 600);
Detector mainDetector(&mainHandler);
KeyInput mainKeyInput(&mainHandler);
MouseInput mainMouseInput(&mainHandler);
Menu* mainMenu;
sf::Sprite mainRect(TextureManager::instance().find("textures/rect.png"));

bool mainRunning = false;

void init();

void loop();

void run();

void initMenu();

void startCallback();

void pauseCallback();

void settingsCallback();

void exitCallback();

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
    mainWindow.setMouseInput(&mainMouseInput);
    mainRect.setPosition(sf::Vector2f(800 - 64, 600 - 64));

    initMenu();
}

void run()
{

    mainHandler.tick();

    GameObject* player = mainHandler.getPlayer();
    if (player != nullptr)
    {
        if (player->position().x > (800 - 64) && player->position().y > (600 - 64))
        {
            mainHandler.addWidget(new Text("YOU WIN", sf::Vector2f(300, 200), 30));
            mainRunning = false;
        }
    }

    if (mainDetector.check())
    {
        mainHandler.addWidget(new Text("YOU LOSE", sf::Vector2f(300, 200), 30));
        mainRunning = false;
    }

}

void loop()
{
    while (mainWindow.isOpen())
    {
        mainWindow.begin();
        mainWindow.renderWindow().draw(mainRect);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            mainMenu->hide(false);

        if (mainRunning)
            run();

        mainHandler.render(mainWindow.renderWindow());

        mainWindow.end();

    }
}

void startCallback()
{
    mainRunning = true;
    mainMenu->hide(true);

    mainHandler.removeAllObjects();
    mainHandler.addObject(new Player(sf::Vector2f(16, 16)));
    for (uint j = 0; j < 10; ++j)
        mainHandler.addObject(new BasicEnemy(sf::Vector2f((rand() % 700) + 50, (rand() % 500) + 50)));
}

void pauseCallback()
{
    mainRunning = !mainRunning;
}

void settingsCallback()
{

}

void exitCallback()
{
    mainWindow.renderWindow().close();
}

void initMenu()
{
    mainMenu = (Menu*)mainHandler.addWidget(new Menu(sf::Vector2f(250.f, 200.f), 4));
    mainMenu->setMsg("START", 0);
    mainMenu->setMsg("PAUSE", 1);
    mainMenu->setMsg("SETTINGS", 2);
    mainMenu->setMsg("EXIT", 3);
    mainMenu->connect(startCallback, 0);
    mainMenu->connect(pauseCallback, 1);
    mainMenu->connect(settingsCallback, 2);
    mainMenu->connect(exitCallback, 3);
}
