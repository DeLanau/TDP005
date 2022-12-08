#include <SFML/Graphics.hpp>


#ifndef PLAYER_H
#define PLAYER_H

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
     * @brief gets the max amount of hitpoints the player object have.
     * 
     * @return int
    */
   // int get_hpMax() const;

    /**
     * @brief gets the value of the mana member variable
     * 
     * @return double
    */
    double get_mana() const;

    /**
     * @brief Gets the max amount of mana the player object have.
     * 
     * @return double
    */
    //double get_manaMax() const;

    /**
     * @brief Adds the choosen parameter "amount" to the member variable "mana".
     * 
    */
    void set_mana(double amount);

    /**
     * @brief updates the mana member variable and the ManaPercent member variable.
     * 
    */
    void regenerate_mana();

    /**
     * @brief restarts the time laps.
     * 
    */
    void RestartClock();


    /**
     * @brief Initiates the Player Graphical User Interface.
     * 
    */
    void initPlayerGUI();

    /**
     * @brief Updates the player Graphical User Interface.
     * 
    */
    void updatePlayerGUI();

    /**
     * @brief Renders the player Graphical User InterFace.
     * 
    */
    void renderPlayerGUI(sf::RenderTarget & target);





    private:
    //Hp
    int hitpointMax{};
    int hitpoint{};
    double HpPercent{};
    int get_hpMax() const;
    //Mana
    double manaMax{};
    double mana{};
    double ManaPercent{};
    double get_manaMax() const;
    //Time
    sf::Clock m_clock;
    sf::Time m_elapsed;
    //GUI
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;
    sf::RectangleShape playerManaBar;   
    sf::RectangleShape playerManaBarBack;
};

#endif