#pragma once

#include <SFML/Graphics.hpp>
#include "utils/resource_manager.h"

/**
 * @brief base class for spells
 * 
 */

/**
 * int const spell id
 */
int const WATER_SPELL{0};
int const EARTH_SPELL{1};
int const FIRE_SPELL{2};
int const WIND_SPELL{3};

class Base_Spell
{
public:
    /**
     * @brief Destroy the Spell_Base object
     * 
     */
    virtual ~Base_Spell () = default;
    /**
     * @brief update spell logic
     * 
     */
    virtual void update() = 0;
    /**
     * @brief render spell
     * 
     * @param target 
     */
    virtual void render(sf::RenderTarget & target) = 0;
    /**
     * @brief Get the mana cost of spell
     * 
     * @return int 
     */
    virtual int get_mana() = 0;
    /**
     * @brief Get the spell damage
     * 
     * @return int 
     */
    virtual int get_damage() = 0;
};