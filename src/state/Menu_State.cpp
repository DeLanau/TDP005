#include "Base_State.h"

#include <iostream>

using namespace sf; 

Menu_State::Menu_State() : texture{Resource_Manager<sf::Texture>::load("resources/menubg.jpg")}, sprite{}
{
    std::cout << "Menu state on" << std::endl;


     sprite.setTexture(texture);
    
     sprite.setOrigin(0,0);
  
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
    target.draw(sprite);
}

int Menu_State::get_next_state()
{
    return MENU_STATE;
}
