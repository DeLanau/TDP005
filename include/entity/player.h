#pragma once

#include "SFML/Graphics.hpp"
#include "Game_Object.h"

struct outOfWindow
{
  bool isLeft = false;
  bool isRight = false;
  bool isUp = false;
  bool isDown = false;
};

class Player : public Game_Object
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
  bool update(Player & player, Button_Manager & button, std::vector<Game_Object*> objs);
  /**
   * @brief Renders the player Graphical User InterFace.
   *
   */
  void renderPlayerGUI(sf::RenderTarget & target);

  /**
   * @brief draw player
   *
   * @param sf::RenderTarget
   */
  void render(sf::RenderTarget & target, Player & player, Button_Manager & button);

  const std::string name(){
      return "player";
  }

  /**
   * @brief get player position
   *
   * @return sf::Vector2f
   */
  sf::Vector2f getPlayerPos() {
    return direction;
  }

  /**
   * @brief get player globalbounds
   *
   * @return sf::FloatRect
   */
   sf::FloatRect getGlobalBounds(){
      return sprite.getGlobalBounds();
   }

    /**
   * @brief reset player values and position
   */
  void resetPlayer(){
    hitpoint = 100;
    mana = 100;
    sprite.setPosition(direction);
  }

  /**
   * @brief checks if player is dead
   *
   * @return bool
   */
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
