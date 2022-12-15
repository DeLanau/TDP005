#include "state/Base_State.h"
#include "utils/utility.h"

#include <iostream>

using namespace sf; 

Game_Over_State::Game_Over_State() :
        font{Resource_Manager<sf::Font>::load("resources/font/toppo.ttf")}
{
    std::cout << "Game over state on" << std::endl;

    text = sf::Text("GAME OVER", font, 82);
    auto bounds{text.getGlobalBounds()};
    text.setPosition((1280 - bounds.width )/ 2, 300);
    text.setColor(sf::Color::Red);

    press = sf::Text("Press enter", font, 42);
    auto bounds2{press.getGlobalBounds()};
    press.setPosition((1280 - bounds2.width )/ 2, 400);

}

int Game_Over_State::get_current_state()
{
    return curr_state;
}

void Game_Over_State::update(sf::Time delta)
{
    
}

void Game_Over_State::render(RenderTarget & target)
{
    target.draw(text);
    target.draw(press);
}

int Game_Over_State::get_next_state()
{
    if(utility::debounce(sf::Keyboard::Enter))
        return MENU_STATE;

    return GAME_OVER_STATE;
}
