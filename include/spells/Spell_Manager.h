//
// Created by nadla777 on 12/6/22.
//

#pragma once
#include "Base_Spell.h"
#include "Fire_Spell.h"
#include "entity/player.h"

class Spell_Manager
{

public:

    Spell_Manager();

    void update(Player & player);

    void render(sf::RenderTarget & target, Player & player);

private:
    //std::map<int, std::unique_ptr<Base_Spell>> spells;

    bool check_mana(Player & player, int const & spell_mana);

    bool check_buttons();

    std::vector<Base_Spell*> spells;
};
