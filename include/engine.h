#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "state/Base_State.h"
#include "state/Menu_State.h"
#include "state/Game_State.h"
/**
 * @brief Engine to run game using different states
 * 
 */
class Engine
{
public:
    /**
    * @brief Construct a new Engine object
    * 
    */
    Engine();
    /**
     * @brief run game 
     * 
     * @return int 
     */
    int run();

private:
    int current_state;
    sf::RenderWindow window;
    std::map<int, std::unique_ptr<Base_State>> states;
};