//
// Created by nadla777 on 12/5/22.
//

#pragma  once

#include "Base_Spell.h"

class Fire_Spell : public Base_Spell
{
public:
    Fire_Spell();

    virtual ~Fire_Spell() = default;

    virtual void update() override;

    virtual void render(sf::RenderTarget & target) override;

    virtual int get_mana() override;

    virtual int get_damage() override;

private:
    unsigned int mana{}, damage{};
    int x{}, y{};

    sf::Sprite sprite;
    sf::Texture texture;
};