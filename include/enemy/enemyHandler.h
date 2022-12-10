#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.h"
#include "../utils/resource_manager.h"
#include "../utils/utility.h"

class HandleEnemies
{
public:
  /*
   * @brief Create new enemy
   */
  void createNewEnemy();
  /*
   * @brief get enemy vector
   */
  std::vector<Enemy*> getEnemies();

  /*
   * @brief render all enemies
   *
   * @param target
   *
   * @param clock
   */
  void rendering(sf::RenderTarget & target);
  
private:
  std::vector<Enemy*> enemy_container;
  sf::Time render_time{sf::milliseconds(35)};
  sf::Time enemy_create_time{sf::milliseconds(1000)};
  sf::Clock clock;
};
