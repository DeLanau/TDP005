#include "entity/enemyHandler.h"
#include <iostream>

HandleEnemies::HandleEnemies() :
  font{Resource_Manager<sf::Font>::load("resources/font/toppo.ttf")}
{
  load_enemy_texture();
  box.setSize(sf::Vector2f{200, 40});
  box.setFillColor(sf::Color(25, 25, 25, 200));
  box.setPosition(1060, 20);
}

HandleEnemies::~HandleEnemies() {
  for(auto e : enemy_container)
    delete e;

  enemy_container.clear();
}

void HandleEnemies::createNewEnemy()
{
  Enemy* temporaryPtr{new Enemy{25, textures.at(utility::randomNumber(0, 2))}};
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

void HandleEnemies::rendering(sf::RenderTarget & target, sf::Vector2i pos, Player & player, bool const& b)
{
  text = sf::Text("Score: " + std::to_string(score), font, 32);
  text.setPosition(1100, 20);
  target.draw(box);
  target.draw(text);


  if(!b) {
    sf::Time elapsed_time = clock.getElapsedTime();

    for (auto current_enemy: enemy_container) {
     // current_enemy->update(pos);
     // current_enemy->render(target);
      if (elapsed_time > render_time) {
	  current_enemy->setLocation(current_enemy->getxMovement(), current_enemy->getyMovement());
      }

     /** if (current_enemy->getCircle().getGlobalBounds().intersects(player.get_Player_Sprite().getGlobalBounds()))
	    player.set_hp(-1);

      if(current_enemy->getCircle().getGlobalBounds().intersects(spells.get_sprite(player).getGlobalBounds()) && spells.get_current_spell() == 1)
	    current_enemy->setLocation(-current_enemy->getxMovement(), -current_enemy->getyMovement()); **/
    }


    /**for (size_t i = 0; i < enemy_container.size(); i++) {
      if(enemy_container[i]->getCircle().getGlobalBounds().intersects(spells.get_sprite(player).getGlobalBounds())
	 && (spells.get_current_spell() == 2 || spells.get_current_spell() == 3)) {
	score += 10;
	delete_enemy(i);
      }
    }**/

    if (elapsed_time > render_time) {
      render_time += sf::milliseconds(updateTime);
    }
    if (elapsed_time > enemy_create_time) {
      if (firstEnemy)
	{
	  clock.restart();
	  firstEnemy = false;
	}
      createNewEnemy();
      enemy_create_time += sf::milliseconds(utility::randomNumber(2500, 5000));
    }
  }
}

void HandleEnemies::delete_enemy(unsigned int const& pos) {
  enemy_container.erase(enemy_container.begin() + pos);
}

void HandleEnemies::load_enemy_texture() {
  textures.push_back(Resource_Manager<sf::Texture>::load("resources/enemy0.png"));
  textures.push_back(Resource_Manager<sf::Texture>::load("resources/enemy1.png"));
  textures.push_back(Resource_Manager<sf::Texture>::load("resources/enemy2.png"));
}

