#include "state/Base_State.h"
#include "spells/Fire_Spell.h"

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

Fire_Spell spell;

void Game_State::update()
{
    spell.update();
}

void Game_State::render(RenderTarget & target)
{
    spell.render(target);
}

int Game_State::get_next_state()
{
    return GAME_STATE;
}
