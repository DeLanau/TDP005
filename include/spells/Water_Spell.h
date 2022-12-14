#pragma  once

#include "Base_Spell.h"

class Water_Spell : public Base_Spell
{
public:
    Water_Spell();

    virtual ~Water_Spell() = default;

    virtual void update(Player & player) override;

    virtual void render(sf::RenderTarget & target) override;

    virtual double get_mana() override;

    virtual double get_damage() override;

    virtual sf::Sprite get_sprite() override {
        return sprite;
    }
private:
    unsigned int mana{}, damage{};
    int x{}, y{};

    sf::Sprite sprite;
    sf::Texture texture;
};

