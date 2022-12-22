#pragma once

#include <SFML/Graphics.hpp>

class Player;
class Button_Manager;

class Game_Object {

public:
    virtual ~Game_Object() = default;

    virtual void update(Player & player, Button_Manager & button) = 0;

    virtual void render(sf::RenderTarget &target, Player &player, Button_Manager & button) = 0;
};