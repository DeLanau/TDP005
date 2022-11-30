#include "Base_State.h"

#include <iostream>

using namespace sf; 

Game_State::Game_State()
{
    std::cout << "Game state on" << std::endl;
}

int Game_State::get_current_state()
{
    return curr_state;
}

void Game_State::update()
{
    
}

void Game_State::render(RenderTarget & target)
{
    
}

int Game_State::get_next_state()
{
    return GAME_OVER_STATE;
}
