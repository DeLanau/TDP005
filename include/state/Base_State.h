#pragma once

#include <SFML/Graphics.hpp>
#include "utils/resource_manager.h"
#include "spells/Spell_Manager.h"

int const MENU_STATE{0};
int const GAME_STATE{1};
int const GAME_OVER_STATE{3};
int const QUIT_STATE{404};

class Base_State
{

public:
    /**
     * @brief Destroy the Base_State object
     * 
     */
    virtual ~Base_State() = default;
    /**
     * @brief update state logic
     * 
     * @return * void 
     */
    virtual void update() = 0;
    /**
     * @brief render/draw obj
     * 
     * @param target 
     */
    virtual void render(sf::RenderTarget & target) = 0;
    /**
     * @brief Get the current state object
     * 
     * @return int 
     */
    virtual int get_current_state() = 0;
    /**
     * @brief Get the next state object
     * 
     * @return int 
     */
    virtual int get_next_state() = 0; 
};

class Game_Over_State : public Base_State
{
public:
    Game_Over_State();

    virtual ~Game_Over_State() = default;

    virtual void update() override;

    virtual void render(sf::RenderTarget & target) override;
        
    virtual int get_current_state() override;

    virtual int get_next_state() override;

private:
    unsigned int curr_state{2};
};
