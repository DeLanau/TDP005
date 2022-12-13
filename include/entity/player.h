#pragma once

#include "SFML/Graphics.hpp"

struct outOfWindow
{
    bool isLeft = false;
    bool isRight = false;
    bool isUp = false;
    bool isDown = false;
};

class Player
{
public:
    /**
     * @brief Initialises player object variablesS
     *
    */
    Player();
    /**
     * @brief Adds the choosen parameter "amount" to the member variable "mana"
     *
    */
    void set_hp(const double amount);
    /**
     * @brief gets the value of the hitpoint member variable
     *
     * @return int
    */
    double get_hp() const;
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

    void render(sf::RenderTarget & target);

    sf::Vector2f getPlayerPos() {
        return direction;
    }

    sf::Sprite const& get_Player_Sprite()
    {
        return sprite;
    }

    void resetPlayer(){
        hitpoint = 100;
        mana = 100;
        sprite.setPosition(direction);
    }

    bool dead(){
        if (hitpoint <= 0) {
            resetPlayer();
            return true;
        }else{
            return false;
        }
    }

private:

    outOfWindow isOutOfWindow();
    void move();

    int speed{50};

    void regenerate_mana();
    void RestartClock();
    void updatePlayerGUI();

    sf::Sprite sprite;
    sf::Texture texture;

    sf::Vector2f find_direction();
    sf::Vector2f direction{600.f, 500.f};

    //Hp
    int hitpointMax{};
    double hitpoint{};

    double HpPercent{};
    //Mana
    double manaMax{}, mana{};

    double ManaPercent{};
    //Time
    sf::Clock m_clock;
    sf::Time m_elapsed;
    //GUI
    sf::RectangleShape playerHpBar, playerHpBarBack, playerManaBar, playerManaBarBack;
};
