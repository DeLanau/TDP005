#pragma  once

#include <iostream>
#include "spells/Wind_Spell.h"
#include "utils/utility.h"
#include "config.h"


Wind_Spell::Wind_Spell() : texture{Resource_Manager<sf::Texture>::load("resources/wind_spell.png")}, sprite{}
{
    sprite.setTexture(texture);
}

void Wind_Spell::update(Player &player, Button_Manager & button)
{
    auto size{texture.getSize()};
    sprite.setOrigin(size.x /2, size.y / 2);
    if(button.get_spell_active() && player.get_mana() >= 1 && button.get_current_button_id() == 3) {
        sf::Vector2f pos = player.getPlayerPos();
        sprite.setPosition(pos);
        sprite.rotate(-1);
        player.set_mana(-this->get_mana());
    }
}

void Wind_Spell::render(sf::RenderTarget & target, Player & player, Button_Manager & button)
{
    if(button.get_spell_active() && player.get_mana() >= 1 && button.get_current_button_id() == 3) {
        target.draw(sprite);
    }
}

double Wind_Spell::get_mana()
{
    return config::spell::wind_mana;
}

double Wind_Spell::get_damage()
{
    return 50;
}

