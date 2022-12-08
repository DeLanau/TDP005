//
// Created by nadla777 on 12/6/22.
//

#pragma  once

#include "spells/Fire_Spell.h"


Fire_Spell::Fire_Spell() : texture{Resource_Manager<sf::Texture>::load("resources/fire_spell.png")},
    sprite{}
{
    sprite.setTexture(texture);
    sprite.setOrigin(0, 0);
}

void Fire_Spell::update()
{
    sprite.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}

void Fire_Spell::render(sf::RenderTarget & target)
{
    target.draw(sprite);
}

int Fire_Spell::get_mana()
{
    return 20;
}

int Fire_Spell::get_damage()
{
    return 50;
}