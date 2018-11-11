#include "Window.h"
#include "Handler.h"

Window mainWindow("Ball You", 800, 600);
Handler mainHandler;

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

    for (int i = 0; i < 50; ++i)
        mainHandler.addObject(new GameObject(GameType::Player, sf::Vector2f(rand() % 800, rand() % 600), sf::Vector2f((rand() % 5) - 2, (rand() % 5) - 2)));
}

void loop()
{
    while (mainWindow.isOpen())
    {
        mainWindow.begin();

        mainHandler.run(mainWindow.renderWindow());

        mainWindow.end();
    }
}
