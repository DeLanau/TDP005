#include "Base_State.h"

#include <iostream>

using namespace sf; 

Menu_State::Menu_State()
{
    std::cout << "Menu state on" << std::endl;
}

int Menu_State::get_current_state()
{
    return curr_state;
}

void Menu_State::update()
{
    
}

void Menu_State::render(RenderTarget & target)
{
    
}

int Menu_State::get_next_state()
{
    return MENU_STATE;
}
