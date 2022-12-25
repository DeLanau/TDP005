//
// Created by nadla777 on 12/5/22.
//

#pragma  once

#include "Base_Spell.h"
#include "utils/Button_Manager.h"

class Fire_Spell : public Base_Spell
{
public:
    Fire_Spell();

    virtual ~Fire_Spell() = default;

    virtual bool update(Player &player, Button_Manager & button, std::vector<Game_Object*> objs) override;

    virtual void render(sf::RenderTarget &target, Player &player, Button_Manager & button) override;

    sf::FloatRect getGlobalBounds(){
        return sprite.getGlobalBounds();
    }

    const std::string name(){
        return "fire";
    }

    virtual double get_mana() override;

    virtual double get_damage() override;

private:
    unsigned int mana{}, damage{};
    int x{}, y{};

    sf::Sprite sprite;
    sf::Texture texture;
};
