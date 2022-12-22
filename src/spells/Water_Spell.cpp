#pragma  once

#include <iostream>
#include "spells/Water_Spell.h"
#include "utils/utility.h"
#include "config.h"


Water_Spell::Water_Spell() : texture{Resource_Manager<sf::Texture>::load("resources/water_spell.png")}, sprite{}
{
    sprite.setTexture(texture);
}

void Water_Spell::update(Player &player, Button_Manager & button)
{
    auto size{texture.getSize()};
    sprite.setOrigin(size.x /2, size.y / 2);
    if(button.get_spell_active() && player.get_mana() >= 1 && button.get_current_button_id() == 0) {
        sf::Vector2f pos = player.getPlayerPos();
        sprite.setPosition(pos);
        player.set_mana(-this->get_mana());

        sf::Time time = clock.getElapsedTime();
        if (time > render_time && player.get_hp() < config::player::hp) {
            player.set_hp(config::spell::water_heal);
            clock.restart();
        }
    }
}

void Water_Spell::render(sf::RenderTarget & target, Player & player, Button_Manager & button)
{
    if(button.get_spell_active() && player.get_mana() >= 1 && button.get_current_button_id() == 0) {
        target.draw(sprite);
    }
}

double Water_Spell::get_mana()
{
    return config::spell::water_mana;
}

double Water_Spell::get_damage()
{
    return 50;
}

