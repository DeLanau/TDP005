#pragma once
#include <SFML/Graphics.hpp>
#include "../utils/resource_manager.h"
#include <cmath>

class Enemy
{
public:
  /*
   * @brief create the Enemy object
   */
  Enemy(float x, float y, float size);
  /*
   * @brief update enemy location
   */
  void update();
  /*
   * @brief render enemy
   *
   * @param target
   */
  void render(sf::RenderTarget & target);
  /*
   * @brief get the enemy
   *
   * @return sf::CircleShape
   */
  sf::CircleShape getCircle();
  /*
   * @brief set location of enemy
   *
   * @param x
   *
   * @param y
   */
  void setLocation(float x, float y);
  /*
   * @brief get location
   *
   * @return sf::Vector2f
   */
  sf::Vector2f getLocation();
  /*
   * @brief get distance between two enemies
   *
   * @param otherEnemy
   *
   * @return int
   */
  int getDistanceCircles(Enemy& otherEnemy);
  /*
   * @brief check overlape between two enemies
   *
   * @param otherEnemy
   *
   * @return bool
   */
  bool checkCollision(Enemy& otherEnemy);
  /*
   * @brief get x movement
   *
   * @return double
   */
  double getxMovement();
  
private:
  float yValue;
  float xValue;
  float size;
  double xMovement;
  sf::CircleShape circle{size};
  sf::Vector2f location{xValue, yValue};
  sf::Texture texture;
};
