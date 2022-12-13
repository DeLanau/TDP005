//
// Created by nadla777 on 12/9/22.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "resource_manager.h"
#include "utility.h"
#include "entity/player.h"


class Button_Manager
{
public:
    Button_Manager();

    void update();

    void render(sf::RenderTarget & target);

    bool &get_spell_active()
    {
        return spell_activate;
    };
  bool set_spell_active(bool state)
    {
      spell_activate = state;
    };

    sf::Text &get_current_button()
    {
        return current_button;
    };

    unsigned int get_current_button_id(){
        return button_id;
    }

    bool check_spell(char const & c){
        if(spell_activate && current_button.getString() == c)
            return true;
        return false;
    }

private:
    sf::Font font;
    sf::Text QQ, WW, EE, RR;
    sf::Text current_button;
    sf::CircleShape circle;

    bool spell_activate{};

    unsigned int button_id{0};

};
