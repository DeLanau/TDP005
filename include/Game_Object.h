#pragma once

#include <SFML/Graphics.hpp>

class Player;
class Button_Manager;

class Game_Object {

public:
    virtual ~Game_Object() = default;

    virtual bool update(Player & player, Button_Manager & button, std::vector<Game_Object*> objs) = 0;

    virtual void render(sf::RenderTarget &target, Player &player, Button_Manager & button) = 0;

    virtual sf::FloatRect getGlobalBounds() = 0;

    virtual const std::string name() = 0;
};