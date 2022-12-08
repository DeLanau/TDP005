#pragma once
#include <SFML/Graphics.hpp>


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
   * @brief get the enemy
   *
   * @return sf::CircleShape
   */
  sf::CircleShape getCircle();
  /*
   * @brief set location of enemy
   *
   *@param x
   *
   *@param y
   */
  void setLocation(float x, float y);
  
 private:
  float yValue;
  float xValue;
  float size;
  sf::CircleShape circle{size};
  sf::Vector2f location{xValue, yValue};
  sf::Texture texture;
};
