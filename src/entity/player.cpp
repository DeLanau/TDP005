#include "entity/player.h"
#include "utils/utility.h"


/**
 *               total        used        free      shared  buff/cache   available
    Mem:       44152412    17483100    14774008      563368    11895304    25550776
    Swap:       2097148      213792     1883356
 * **/

#include "utils/resource_manager.h"
#include "config.h"

using namespace std;

Player::Player()
        : hitpointMax{static_cast<int>(config::player::hp)}, hitpoint{config::player::hp}, manaMax{config::player::mana},
        mana{config::player::mana-1}, m_clock{}, m_elapsed{}, direction{600.f, 500.f},
        texture{Resource_Manager<sf::Texture>::load("resources/player.png")},
        sprite{}
{
    //HP
    playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
    playerHpBar.setFillColor(sf::Color::Red);
    playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

    playerHpBarBack = playerHpBar;
    playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

    //Mana
    playerManaBar.setSize(sf::Vector2f(300.f, 25.f));
    playerManaBar.setFillColor(sf::Color::Blue);
    playerManaBar.setPosition(sf::Vector2f(20.f, 50.f));

    playerManaBarBack = playerManaBar;
    playerManaBarBack.setFillColor(sf::Color(25, 25, 25, 200));

    sprite.setTexture(texture);
}

//Hp
void Player::set_hp(const double amount)
{
    hitpoint += amount;
   /** if ( amount > 0) {
        sprite.setColor(sf::Color::Green);
    }
    else {
        sprite.setColor(sf::Color::Red);
    }**/
}

double Player::get_hp() const
{
    return hitpoint;
}

//Mana
double Player::get_mana() const
{
    return mana;
}

void Player::set_mana(double amount)
{
    mana += amount;
}

void Player::regenerate_mana()
{
    float regenTime = 1.0f;

    if (m_elapsed.asSeconds() >= regenTime && mana < config::player::mana)
    {
        mana += 1.0;
        if (mana > config::player::mana)
        {
            mana = config::player::mana;
        }

        ManaPercent = (mana / manaMax);

        m_elapsed -= sf::seconds(regenTime);
    }
}

//Clock
void Player::RestartClock()
{
    m_elapsed += m_clock.restart();
}

void Player::updatePlayerGUI()
{
    //HP
    HpPercent = static_cast<float>(hitpoint) / hitpointMax;
    playerHpBar.setSize(sf::Vector2f(300.0f * HpPercent, playerHpBar.getSize().y));

    //Mana
    playerManaBar.setSize(sf::Vector2f(300.0f * ManaPercent, playerManaBar.getSize().y));

}

bool Player::update(Player & player, Button_Manager & button, std::vector<Game_Object*> objs)
{
    this->sprite.setPosition(this->find_direction());
    this->regenerate_mana();
    this->RestartClock();
    this->updatePlayerGUI();
    return true;
}

void Player::renderPlayerGUI(sf::RenderTarget & target)
{
    //HP
    target.draw(playerHpBarBack);
    target.draw(playerHpBar);

    //Mana
    target.draw(playerManaBarBack);
    target.draw(playerManaBar);
}

void Player::render(sf::RenderTarget &target, Player & player, Button_Manager & button) {
    this->renderPlayerGUI(target);
    target.draw(sprite);
}

sf::Vector2f Player::find_direction() {

    auto size{texture.getSize()};
    sprite.setOrigin(size.x /2 -1, size.y / 2);

    outOfWindow limits = this->isOutOfWindow();

    if (utility::debounce(sf::Keyboard::Up) && !limits.isUp) {
        sprite.setRotation(0);
        direction.y -= config::player::speed;
    }
    if (utility::debounce(sf::Keyboard::Down) && !limits.isDown) {
        sprite.setRotation(180);
        direction.y += config::player::speed;
    }
    if (utility::debounce(sf::Keyboard::Left) && !limits.isLeft) {
        sprite.setRotation(-90);
        direction.x -= config::player::speed;
    }
    if (utility::debounce(sf::Keyboard::Right) && !limits.isRight) {
        sprite.setRotation(90);
        direction.x += config::player::speed;
    }
    return direction;
}

outOfWindow Player::isOutOfWindow()
{
    outOfWindow limits;

    if(sprite.getPosition().x > 1230.f || sprite.getPosition().x < 52.f || sprite.getPosition().y > 645.f || sprite.getPosition().y < 58.f)
    {
        if(sprite.getPosition().x > 1230.f)
        {
            sprite.setPosition(1230.f, sprite.getPosition().y);
            limits.isRight = true;
            return limits;
        }
        else if(sprite.getPosition().x < 52.f)
        {
            sprite.setPosition( 52.f, sprite.getPosition().y);
            limits.isLeft = true;
            return limits;
        }
        else if(sprite.getPosition().y > 645.f)
        {
            sprite.setPosition(sprite.getPosition().x, 645.f);
            limits.isDown = true;
            return limits;
        }
        else if(sprite.getPosition().y < 58.f)
        {
            sprite.setPosition(sprite.getPosition().x, 58.f);
            limits.isUp = true;
            return limits;
        }
    }
    return limits;
}