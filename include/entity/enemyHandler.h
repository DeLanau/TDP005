#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.h"
#include "../utils/resource_manager.h"
#include "../utils/utility.h"
#include "player.h"
#include "spells/Spell_Manager.h"

class HandleEnemies
{
public:

  HandleEnemies();

  ~HandleEnemies();

  /**
   * @brief Create new enemy
   */
  void createNewEnemy();
  /**
   * @brief get enemy vector
   */
  std::vector<Enemy*> getEnemies();

  /**
   * @brief render all enemies
   *
   * @param target
   *
   * @param clock
   */
  void rendering(sf::RenderTarget & target, sf::Vector2i pos, Player & player, Spell_Manager & spells, bool const& b);

  /**
   * @brief removes enemy
   *
   * @param pos unsigned int
   */
  void delete_enemy(unsigned int const& pos);
  //void damage_enemy(Enemy* enemy);

  /**
   * @brief load enemy texture
   */
  void load_enemy_texture();

  /**
   * @brief deletes all enemies
   */  
  void resetEnemies()
  {
    for (auto s : enemy_container)
      delete s;
    enemy_container.clear();
  }

private:

  sf::Font font;
  sf::Text text;
  int score{};
  sf::RectangleShape box;

  std::vector<Enemy*> enemy_container;
  std::vector<sf::Texture> textures;
  sf::Time render_time{sf::milliseconds(35)};
  sf::Time enemy_create_time{sf::milliseconds(1000)};
  sf::Clock clock;
};
