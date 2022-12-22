#pragma  once

#include "Base_Spell.h"

class Earth_Spell : public Base_Spell
{
public:
    Earth_Spell();

    virtual ~Earth_Spell() = default;

    virtual void update(Player &player, Button_Manager & button) override;

    virtual void render(sf::RenderTarget &target, Player &player, Button_Manager & button) override;

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
