#pragma  once

#include <iostream>
#include "spells/Earth_Spell.h"
#include "utils/utility.h"
#include "config.h"


Earth_Spell::Earth_Spell() : texture{Resource_Manager<sf::Texture>::load("resources/earth_spell.png")}, sprite{}
{
    sprite.setTexture(texture);
}

bool Earth_Spell::update(Player &player, Button_Manager & button, std::vector<Game_Object*> objs)
{
    auto size{texture.getSize()};
    sprite.setOrigin(size.x /2, size.y / 2);
    if(button.get_spell_active() && player.get_mana() >= 1 && button.get_current_button_id() == 1) {
        sf::Vector2f pos = player.getPlayerPos();
        sprite.setPosition(pos);
        sprite.rotate(-1);
    }
    return true;
}

void Earth_Spell::render(sf::RenderTarget & target, Player & player, Button_Manager & button)
{
    if(button.get_spell_active() && player.get_mana() >= 1 && button.get_current_button_id() == 1) {
        target.draw(sprite);
    }
}

double Earth_Spell::get_mana()
{
    return config::spell::earth_mana;
}

double Earth_Spell::get_damage()
{
    return 50;
}
