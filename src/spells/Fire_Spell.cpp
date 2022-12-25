//
// Created by nadla777 on 12/6/22.
//

#pragma  once

#include <iostream>
#include "spells/Fire_Spell.h"
#include "utils/utility.h"
#include "config.h"


Fire_Spell::Fire_Spell() : texture{Resource_Manager<sf::Texture>::load("resources/fire_spell.png")},
                           sprite{}
{
    sprite.setTexture(texture);
}

bool Fire_Spell::update(Player &player, Button_Manager & button, std::vector<Game_Object*> objs)
{
    auto size{texture.getSize()};
    sprite.setOrigin(size.x /2, size.y / 2);
    if(button.get_spell_active() && player.get_mana() >= 1 && button.get_current_button_id() == 2) {
        sf::Vector2f pos = player.getPlayerPos();
        sprite.setPosition(pos);
        sprite.rotate(-1);
        if(player.get_hp() >= 20){
            player.set_hp(-this->get_mana());
        }else {
            player.set_mana(-this->get_mana());
        }
    }
    return true;
}

void Fire_Spell::render(sf::RenderTarget & target, Player & player, Button_Manager & button)
{
    if(button.get_spell_active() && player.get_mana() >= 1 && button.get_current_button_id() == 2) {
        target.draw(sprite);
    }
}

double Fire_Spell::get_mana()
{
    return config::spell::fire_mana;
}

double Fire_Spell::get_damage()
{
    return 50;
}