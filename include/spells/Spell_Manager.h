//
// Created by nadla777 on 12/11/22.
//

#pragma once

#include "spells/Fire_Spell.h"
#include "entity/player.h"
#include "utils/Button_Manager.h"

class Player;

class Spell_Manager
{

public:

    Spell_Manager();

    ~Spell_Manager();

    void update(Player & player);

    void render(sf::RenderTarget & target, Player & player);

    void run_spells(sf::RenderTarget & target, Player & player);

private:

    Button_Manager buttons;
    Fire_Spell fire;
};

