#include "enemyHandler.h"


  void HandleEnemies::createNew()
  {
    std::random_device rand;
    std::uniform_int_distribution<int> dist(0, 924);
    holder.push_back(new Enemy{dist(rand), -100, 50});
  }

  std::vector<Enemy*> HandleEnemies::getEnemies()
  {
    return holder;
  }
  

