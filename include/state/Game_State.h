//
// Created by nadla777 on 12/9/22.
//

#pragma once

#include "Base_State.h"
#include "entity/player.h"
#include "utils/Button_Manager.h"

class Game_State : public Base_State
{
public:
    Game_State();

    virtual ~Game_State() = default;

    virtual void update() override;

    virtual void render(sf::RenderTarget & target) override;

    virtual int get_current_state() override;

    virtual int get_next_state() override;
private:
    unsigned int curr_state{1};

    sf::Texture texture;
    sf::Font font;
    sf::Sprite sprite;

    Spell_Manager spell_manager;
    Player player;
    Button_Manager buttons;

    sf::Clock clock;
    sf::Text fps;

};
