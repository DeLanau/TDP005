//
// Created by nadla777 on 12/9/22.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "resource_manager.h"
#include "utility.h"

class Button_Manager
{
public:
    Button_Manager();

    void update();

    void render(sf::RenderTarget & target);

private:
    sf::Font font;
    sf::Text QQ, WW, EE, RR;
    sf::Text current_button;
    sf::CircleShape circle;
};