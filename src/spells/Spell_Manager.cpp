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
                if(player.get_hp() >= 20){
                    player.set_hp(-fire.get_mana());
                }else {
                    player.set_mana(-fire.get_mana());
                }
        }
    }
}

sf::Sprite Spell_Manager::get_sprite(Player & player) {
    if(buttons.get_spell_active() && player.get_mana() >= 1) {
        switch (buttons.get_current_button_id()) {
            case 2:
                return fire.get_sprite();
        }
    }
}