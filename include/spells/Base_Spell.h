#pragma once

#include <SFML/Graphics.hpp>
#include "utils/resource_manager.h"
#include "entity/player.h"
#include "utils/Button_Manager.h"

class Base_Spell : public Game_Object
{
public:
  /**
   * @brief Destroy the Spell_Base object
   * 
   */
  virtual ~Base_Spell () = default;

  virtual void update(Player &player, Button_Manager & button) = 0;

  virtual void render(sf::RenderTarget &target, Player &player, Button_Manager & button) = 0;

  /**
   * @brief Get the mana cost of spell
   *
   * @return int
   */
  virtual double get_mana() = 0;
  /**
   * @brief Get the spell damage
   *
   * @return int
   */
  virtual double get_damage() = 0;

  /**
   * @brief get sprite
   *
   * @return sf::Sprite
   */
  virtual sf::Sprite get_sprite() = 0;

protected:
  sf::Clock clock;
  sf::Time render_time{sf::milliseconds(300)};
  bool do_render{false};
};
