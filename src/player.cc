#include "/home/lukfr510/tdp005-test/include/player.h"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Player::Player()
: hitpointMax{100}, hitpoint{hitpointMax}, manaMax{100}, mana{manaMax}
{}

Player::~Player()
{

}

//Hp
void Player::set_hp(const int amount) 
{
    hitpoint += amount;
}

int Player::get_hpMax() const
{
    return hitpointMax;
}

int Player::get_hp() const
{
    return hitpoint;
}


//Mana
double Player::get_mana() const
{
    return mana;
}

double Player::get_manaMax() const
{
    return manaMax;
}


void Player::set_mana(double amount)
{
    mana += amount;
}

void Player::regenerate_mana()
{
    float regenTime = 1.0f;

    if (m_elapsed.asSeconds() >= regenTime && mana < 100)
    {
        mana += 1.0;
        if (mana > 100)
        {
            mana = 100;
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

//GUI
void Player::initPlayerGUI()
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
}

void Player::updatePlayerGUI()
{
    //HP
    HpPercent = static_cast<float>(hitpoint) / hitpointMax;
    playerHpBar.setSize(sf::Vector2f(300.0f * HpPercent, playerHpBar.getSize().y));

    //Mana
    playerManaBar.setSize(sf::Vector2f(300.0f * ManaPercent, playerManaBar.getSize().y));

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


//----------------------------------------------------------------------

