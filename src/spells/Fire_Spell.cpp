//
// Created by nadla777 on 12/6/22.
//

#pragma  once

#include <iostream>
#include "spells/Fire_Spell.h"
#include "utils/utility.h"


Fire_Spell::Fire_Spell() : texture{Resource_Manager<sf::Texture>::load("resources/fire_spell.png")},
                           sprite{}
{
    sprite.setTexture(texture);
}

void Fire_Spell::update(Player &player)
{
    auto size{texture.getSize()};
    sprite.setOrigin(size.x /2, size.y / 2);

    sf::Vector2f pos = player.getPlayerPos();
    sprite.setPosition(pos);
    sprite.rotate(1);
}

void Fire_Spell::render(sf::RenderTarget & target)
{
    target.draw(sprite);
}

double Fire_Spell::get_mana()
{
    return 0.05;
}

double Fire_Spell::get_damage()
{
    return 50;
}