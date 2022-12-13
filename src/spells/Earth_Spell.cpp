//
// Created by nadla777 on 12/6/22.
//

#pragma  once

#include <iostream>
#include "spells/Earth_Spell.h"
#include "utils/utility.h"


Earth_Spell::Earth_Spell() : texture{Resource_Manager<sf::Texture>::load("resources/earth_spell.png")}, sprite{}
{
    sprite.setTexture(texture);
}

void Earth_Spell::update(Player &player)
{
    auto size{texture.getSize()};
    sprite.setOrigin(size.x /2, size.y / 2);

    sf::Vector2f pos = player.getPlayerPos();
    sprite.setPosition(pos);
    sprite.rotate(1);
}

void Earth_Spell::render(sf::RenderTarget & target)
{
    target.draw(sprite);
}

double Earth_Spell::get_mana()
{
    return 0.05;
}

double Earth_Spell::get_damage()
{
    return 50;
}
