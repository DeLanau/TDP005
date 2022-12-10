#pragma once

#include "spells/Spell_Manager.h"

#include <iostream>

Spell_Manager::Spell_Manager() :
spells{}
{

    //spells.insert(std::pair<int, std::unique_ptr<Base_Spell>({WATER_SPELL, std::make_unique<Water_Spell>()}));
    //spells.insert(std::pair<int, std::unique_ptr<Base_Spell>>({WATER_SPELL, std::make_unique<Fire_Spell>()}));
    spells.push_back(new Fire_Spell);

  //  std::cout << typeid(spells.at(0)).name() << std::endl;
}

void Spell_Manager::update(Player & player)
{
    for ( auto s : spells)
    {
        if(check_mana(player, 0) && check_buttons())
            s->update();
    }

}

void Spell_Manager::render(sf::RenderTarget & target, Player & player)
{
    for (auto s : spells)
    {
        if(check_mana(player, s->get_mana()) && check_buttons())
            s->render(target);
    }
}

bool Spell_Manager::check_mana(Player & player, int const & spell_mana)
{

    if(player.get_mana() >= spell_mana)
        player.set_mana(-spell_mana);
        return true;

    return false;
}

bool Spell_Manager::check_buttons()
{
    //E -> ritas och skickas till -> spell_manager -> wait space -> controll mana -> dra mana -> render update spell
    return false;
}