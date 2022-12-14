//
// Created by nadla777 on 12/11/22.
//

#pragma once

#include "spells/Fire_Spell.h"
#include "entity/player.h"
#include "utils/Button_Manager.h"
#include "Water_Spell.h"
#include "Earth_Spell.h"
#include "Wind_Spell.h"

class Player;

class Spell_Manager
{

public:

    Spell_Manager();

    ~Spell_Manager();

    void update(Player & player);

    void render(sf::RenderTarget & target, Player & player);

    void run_spells(sf::RenderTarget & target, Player & player);

    sf::Sprite get_sprite(Player & player);

    int const get_current_spell(){
        return buttons.get_current_button_id();
    }

private:

    Button_Manager buttons;
    Fire_Spell fire;
    Water_Spell water;
    Earth_Spell earth;
    Wind_Spell wind;
};

