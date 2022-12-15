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
  /**
   * @brief create Button_Manager object
   */
  Button_Manager();

  /**
   * @brief sets new spell and deactivates last spell
   */
  void update();
  
  /**
   * @brief draws circle and last pressed button
   */
  void render(sf::RenderTarget & target);

  /**
   * @brief get current spell
   *
   * @return bool
   */
  bool &get_spell_active()
  {
    return spell_activate;
  };

  /**
   * @brief get latest pressed button
   *
   * @return sf::Text
   */
  sf::Text &get_current_button()
  {
    return current_button;
  };
  
  /**
   * @brief get latest pressed button id
   *
   * @return unsigned int
   */
  unsigned int get_current_button_id()
  {
    return button_id;
  }

  /**
   * @brief checks if spell matches active spell
   *
   * @param c char
   *
   * @return bool
   */
  
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
