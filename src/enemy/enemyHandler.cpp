#include "enemy/enemyHandler.h"
#include <iostream>

void HandleEnemies::createNewEnemy()
{
  
  Enemy* temporaryPtr{new Enemy{25}};
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
  
void HandleEnemies::rendering(sf::RenderTarget & target, sf::Vector2i pos)
{
  sf::Time elapsed_time = clock.getElapsedTime();
  
  for (auto current_enemy : enemy_container)
    {
      current_enemy->update(pos);
      current_enemy->render(target);
      if (elapsed_time > render_time)
	{
	  current_enemy->setLocation(current_enemy->getxMovement(), current_enemy->getyMovement());
	}
    }

  if (elapsed_time > render_time)
    {
      render_time += sf::milliseconds(35);
    }
  if (elapsed_time > enemy_create_time)
    {
      createNewEnemy();
      enemy_create_time += sf::milliseconds(utility::randomNumber(2500, 5000));
    }
}
