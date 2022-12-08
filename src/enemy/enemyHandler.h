#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.h"
#include <random>

class HandleEnemies
{
public:
  /*
   * @brief Create new enemy
   */
  void createNew();
  /*
   * @brief get enemy vector
   */
  std::vector<Enemy*> getEnemies();
  
private:
  std::vector<Enemy*> holder;
};
