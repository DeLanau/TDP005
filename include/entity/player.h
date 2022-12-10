#pragma once

#include "SFML/Graphics.hpp"

class Player
{
public:
    /**
     * @brief Initialises player object variablesS
     *
    */
    Player();

    ~Player();
    /**
     * @brief Adds the choosen parameter "amount" to the member variable "mana"
     *
    */
    void set_hp(const int amount);
    /**
     * @brief gets the value of the hitpoint member variable
     *
     * @return int
    */
    int get_hp() const;
    /**
     * @brief gets the value of the mana member variable
     *
     * @return double
    */
    double get_mana() const;
    /**
     * @brief Adds the choosen parameter "amount" to the member variable "mana".
     *
    */
    void set_mana(double amount);
    /**
     * @brief updates player
     */
    void update();
    /**
     * @brief Renders the player Graphical User InterFace.
     *
    */
    void renderPlayerGUI(sf::RenderTarget & target);

private:

    void regenerate_mana();
    void RestartClock();
    void updatePlayerGUI();

    //Hp
    int hitpointMax{}, hitpoint{};

    double HpPercent{};
    int get_hpMax() const;
    //Mana
    double manaMax{}, mana{};

    double ManaPercent{};
    double get_manaMax() const;
    //Time
    sf::Clock m_clock;
    sf::Time m_elapsed;
    //GUI
    sf::RectangleShape playerHpBar, playerHpBarBack, playerManaBar, playerManaBarBack;
};
