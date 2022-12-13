//
// Created by nadla777 on 12/5/22.
//

#pragma  once

#include "Base_Spell.h"

class Wind_Spell : public Base_Spell
{
public:
    Wind_Spell();

    virtual ~Wind_Spell() = default;

    virtual void update(Player & player) override;

    virtual void render(sf::RenderTarget & target) override;

    virtual double get_mana() override;

    virtual double get_damage() override;

private:
    unsigned int mana{}, damage{};
    int x{}, y{};

    sf::Sprite sprite;
    sf::Texture texture;
};
