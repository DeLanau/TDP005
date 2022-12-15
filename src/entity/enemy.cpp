#include "entity/enemy.h"


Enemy::Enemy(float size, sf::Texture &texture): size{size}, location{spawnPoint()}
{
    circle.setTexture(&texture);
}

void Enemy::update(sf::Vector2i pos)
{
    circle.setPosition(location);
    setMovement(pos);
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

double Enemy::getyMovement()
{
    return yMovement;
}

void Enemy::setMovement(sf::Vector2i pos)
{
    if (pos.y > location.y + circle.getRadius())
        yMovement = 1;
    else if (pos.y < location.y + circle.getRadius())
        yMovement = -1;

    if (pos.x > location.x + circle.getRadius())
        xMovement = 1;
    else if (pos.x < location.x + circle.getRadius())
        xMovement = -1;

    if (pos.x == location.x + circle.getRadius())
        xMovement = 0;
    if (pos.y == location.y + circle.getRadius())
        yMovement = 0;
}


sf::Vector2f Enemy::spawnPoint()
{
    int spawn{utility::randomNumber(0, 3)};
    sf::Vector2f loc;

    if (spawn == 0)
    {
        loc.x = 1280;
        loc.y = utility::randomNumber(250, 450);
    }
    else if (spawn == 1)
    {
        loc.x = -100;
        loc.y = utility::randomNumber(250, 450);
    }
    else if (spawn == 2)
    {
        loc.x = utility::randomNumber(500, 700);
        loc.y = 720;
    }
    else if (spawn == 3)
    {
        loc.x = utility::randomNumber(500, 700);
        loc.y = -100;
    }
    return loc;
}
