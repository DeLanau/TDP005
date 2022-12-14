#pragma  once

#include <iostream>
#include "spells/Wind_Spell.h"
#include "utils/utility.h"
#include "config.h"


Wind_Spell::Wind_Spell() : texture{Resource_Manager<sf::Texture>::load("resources/wind_spell.png")}, sprite{}
{
    sprite.setTexture(texture);
}

void Wind_Spell::update(Player &player)
{
    auto size{texture.getSize()};
    sprite.setOrigin(size.x /2, size.y / 2);

    sf::Vector2f pos = player.getPlayerPos();
    sprite.setPosition(pos);
    sprite.rotate(1);
}

void Wind_Spell::render(sf::RenderTarget & target)
{
    target.draw(sprite);
}

double Wind_Spell::get_mana()
{
    return config::spell::wind_mana;
}

double Wind_Spell::get_damage()
{
    return 50;
}

