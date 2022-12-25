#pragma  once

#include "Base_Spell.h"

class Wind_Spell : public Base_Spell
{
public:
    Wind_Spell();

    virtual ~Wind_Spell() = default;

    virtual bool update(Player &player, Button_Manager & button, std::vector<Game_Object*> objs) override;

    virtual void render(sf::RenderTarget &target, Player &player, Button_Manager & button) override;

    sf::FloatRect getGlobalBounds(){
        return sprite.getGlobalBounds();
    }

    const std::string name(){
        return "wind";
    }

    virtual double get_mana() override;

    virtual double get_damage() override;

private:
    unsigned int mana{}, damage{};
    int x{}, y{};

    sf::Sprite sprite;
    sf::Texture texture;
};

