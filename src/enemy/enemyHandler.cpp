#include "enemy/enemyHandler.h"
#include <iostream>

void HandleEnemies::createNewEnemy()
{
  // std::random_device rand;
  // std::uniform_int_distribution<int> randNumb(0, 924);
  
  Enemy* temporaryPtr{new Enemy{utility::randomNumber(0, 924), -100, 50}};
  bool noColidingEnemies{true};
  
  for (auto enemyList : enemy_container)
    {
      if (enemyList->checkCollision(*temporaryPtr))
	{
	  noColidingEnemies = false;
	}
    }
  if (noColidingEnemies)
    {
      enemy_container.push_back(temporaryPtr);
    }
}

std::vector<Enemy*> HandleEnemies::getEnemies()
{
  return enemy_container;
}
  
void HandleEnemies::rendering(sf::RenderTarget & target)
{
  sf::Time elapsed_time = clock.getElapsedTime();
  
  for (auto current_enemy : enemy_container)
    {
      current_enemy->update();
      current_enemy->render(target);
      if (elapsed_time > render_time)
	{
	  current_enemy->setLocation(current_enemy->getxMovement(), 1);
	}
    }

  if (elapsed_time > render_time)
    {
      render_time += sf::milliseconds(35);
    }
  if (elapsed_time > enemy_create_time)
    {
      createNewEnemy();
      enemy_create_time += sf::milliseconds(utility::randomNumber(1000, 2000));
    }
}
