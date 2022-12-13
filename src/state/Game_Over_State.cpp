#include "state/Base_State.h"

#include <iostream>

using namespace sf; 

Game_Over_State::Game_Over_State()
{
    std::cout << "Game over state on" << std::endl;
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
    
}

int Game_Over_State::get_next_state()
{
    return MENU_STATE;
}
