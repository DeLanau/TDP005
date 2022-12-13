#pragma once

#include "spells/Spell_Manager.h"

#include <iostream>

Spell_Manager::Spell_Manager() :
fire{}
{

}

Spell_Manager::~Spell_Manager() {
}

void Spell_Manager::update(Player & player)
{
    buttons.update();
}

void Spell_Manager::render(sf::RenderTarget & target, Player & player)
{
    buttons.render(target);
    run_spells(target, player);
}

void Spell_Manager::run_spells(sf::RenderTarget &target, Player &player) {
    if(buttons.get_spell_active() && player.get_mana() >= 1) {
        switch (buttons.get_current_button_id()) {
            case 2:
                fire.update(player);
                fire.render(target);
                player.set_mana(-fire.get_mana());
        }
    }
}