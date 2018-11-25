#include "Menu.h"

Menu::Menu(sf::Vector2f pos, uint rows)
    : GameWidget(pos, sf::Vector2f(0, 0))
{
    for (uint i = 0; i < rows; ++i)
    {
        sf::Vector2f btnPos = pos;
        btnPos.y += (40 * i + i * 20);

        _buttons.push_back(new Button("HELLO WORLD", btnPos, sf::Vector2f(200, 40)));
    }
}

Menu::~Menu()
{
    for (auto btn : _buttons)
        delete btn;
}

void Menu::setMsg(std::string msg, uint row)
{
    if (row >= _buttons.size())
        return;

    _buttons[row]->setMsg(msg);
}

void Menu::connect(void (*callback)(), uint row)
{
    if (row >= _buttons.size())
        return;

    _buttons[row]->connect(callback);
}

void Menu::hide(bool hidden)
{
    GameWidget::hide(hidden);

    for (auto btn : _buttons)
        btn->hide(hidden);
}

void Menu::render(sf::RenderWindow& renderWindow)
{
    for (auto btn : _buttons)
        btn->render(renderWindow);
}

void Menu::tick()
{

    for (auto btn : _buttons)
        btn->tick();
}

void Menu::update()
{
    for (auto btn : _buttons)
        btn->update();
}

void Menu::mouseClicked(sf::Event &event)
{
    for (auto btn : _buttons)
        btn->mouseClicked(event);
}

void Menu::mouseReleased(sf::Event &event)
{
    for (auto btn : _buttons)
        btn->mouseReleased(event);
}

void Menu::mouseMoved(sf::Event &event)
{
    for (auto btn : _buttons)
        btn->mouseMoved(event);
}
