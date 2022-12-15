#pragma once
#include <SFML/Graphics.hpp>
#include "../utils/resource_manager.h"
#include "../utils/utility.h"
#include <cmath>
#include <vector>

class Enemy
{
public:
  /**
   * @brief create the Enemy object
   *
   * @param size float
   *
   * @param texture sf::Texture
   */
  Enemy(float size, sf::Texture &texture);
  /**
   * @brief update enemy location
   */
  void update(sf::Vector2i pos);
  /**
   * @brief render enemy
   *
   * @param target
   */
  void render(sf::RenderTarget & target);
  /**
   * @brief get the enemy
   *
   * @return sf::CircleShape
   */
  sf::CircleShape getCircle();
  /**
   * @brief set location of enemy
   *
   * @param x
   *
   * @param y
   */
  void setLocation(float x, float y);
  /**
   * @brief get location
   *
   * @return sf::Vector2f
   */
  sf::Vector2f getLocation();
  /**
   * @brief get distance between two enemies
   *
   * @param otherEnemy
   *
   * @return int
   */
  int getDistanceCircles(Enemy& otherEnemy);
  /**
   * @brief check overlape between two enemies
   *
   * @param otherEnemy
   *
   * @return bool
   */
  bool checkCollision(Enemy& otherEnemy);
  /**
   * @brief get x movement
   *
   * @return double
   */
  double getxMovement();
  /**
   * @brief get y movement
   *
   * @return double
   */
  double getyMovement();

  /**
   * @brief set enemy movement
   *
   * @param pos sf::Vector2i
   */  
  void setMovement(sf::Vector2i pos);

  /**
   * @brief returns random spawn point
   *
   * @return sf::Vector2f
   */
  sf::Vector2f spawnPoint();

private:
  float size;
  double xMovement;
  double yMovement;
  sf::CircleShape circle{size};
  sf::Vector2f location{};
  sf::Texture texture;
  std::vector<sf::Texture*> textures; // unused
  double hp{10000};
};
