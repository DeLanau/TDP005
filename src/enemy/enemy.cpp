#include "enemy/enemy.h"



Enemy::Enemy(float x, float y, float size): xValue{x}, yValue{y}, size{size}, texture{Resource_Manager<sf::Texture>::load("resources/enemy.png")}
{
  circle.setTexture(&texture);
  xMovement = (450-location.x)/800;
}

  
void Enemy::update()
{
  circle.setPosition(location);
}

void Enemy::render(sf::RenderTarget & target)
{
  target.draw(circle);
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

sf::Vector2f Enemy::getLocation()
{
  return location;
}

int Enemy::getDistanceCircles(Enemy& otherEnemy)
{
  sf::Vector2f firstRadius{circle.getRadius(), circle.getRadius()};
  sf::Vector2f secondRadius{otherEnemy.getCircle().getRadius(), otherEnemy.getCircle().getRadius()};

  sf::Vector2f centerLocationThis{location + firstRadius};
  sf::Vector2f centerLocationOther{otherEnemy.getLocation() + secondRadius};

  int xval = abs(centerLocationThis.x - centerLocationOther.x);
  int yval = abs(centerLocationThis.y - centerLocationOther.y);

  return sqrt(pow(xval, 2) + pow(yval, 2));
}

bool Enemy::checkCollision(Enemy& otherEnemy)
{
  if (getDistanceCircles(otherEnemy) < circle.getRadius() + getCircle().getRadius())
    {
      return true;
    }
  else
    {
      return false;
    }
}

double Enemy::getxMovement()
{
  return xMovement;
}
