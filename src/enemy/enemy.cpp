#include "enemy.h"


Enemy::Enemy(float x, float y, float size): xValue{x}, yValue{y}, size{size}
{
 texture.loadFromFile("/home/elliot/Desktop/git/tdp005/src/enemy.png");
 circle.setTexture(&texture);
}
  
void Enemy::update()
{
  circle.setPosition(location);
}

sf::CircleShape Enemy::getCircle()
{
  return circle;
}

void Enemy::setLocation(float x, float y)
{
  location.x += x;
  location.y += y;
}

