#include "state/Game_State.h"
#include "utils/Button_Manager.h"
#include "spells/Water_Spell.h"
#include "spells/Earth_Spell.h"
#include "spells/Fire_Spell.h"
#include "spells/Wind_Spell.h"

#include <iostream>

using namespace sf;

Game_State::Game_State() :
texture{Resource_Manager<sf::Texture>::load("resources/back_ground.png")},
font{Resource_Manager<sf::Font>::load("resources/font/toppo.ttf")},
fps{},
sprite{}
{
    std::cout << "Game state on" << std::endl;

    sprite.setTexture(texture);
    sprite.setOrigin(0, 0);
    fps.setPosition(1280, 100);

    game_objs.push_back(&player);

    game_objs.push_back(new Water_Spell());
    game_objs.push_back(new Earth_Spell());
    game_objs.push_back(new Fire_Spell());
    game_objs.push_back(new Wind_Spell());
    game_objs.push_back(new Enemy(25, Resource_Manager<sf::Texture>::load("resources/enemy0.png")));
    game_objs.push_back(new Enemy(30, Resource_Manager<sf::Texture>::load("resources/enemy1.png")));
    game_objs.push_back(new Enemy(35, Resource_Manager<sf::Texture>::load("resources/enemy2.png")));

    //TODO load enemy textures
}

int Game_State::get_current_state()
{
    return curr_state;
}

void Game_State::update(sf::Time delta)
{

    if(player.get_hp() == 0 || player.get_hp() < 0)
        end_game = true;

    button.update();

    check_objs();
    game_objs.push_back(new Enemy(35, Resource_Manager<sf::Texture>::load("resources/enemy2.png")));
    //TODO push new enemies med clockan

    for (auto &s : game_objs)
        s->update(player, button, game_objs);

    float lastTime = 0.f;
    float currentTime = clock.restart().asSeconds();
    float fps1 = 1.f / (currentTime - lastTime);
    lastTime = currentTime;

    fps = Text(std::to_string((int)fps1), font, 32);
    fps.setPosition(0, 680);
    fps.setColor(sf::Color::Black);

}

void Game_State::render(RenderTarget & target)
{
    target.draw(sprite);
    button.render(target);
    for(auto &s : game_objs)
        s->render(target, player, button);

    target.draw(fps);
    //enemys.rendering(target, static_cast<sf::Vector2i>(player.getPlayerPos()), player,  end_game);
}

int Game_State::get_next_state()
{
    if(end_game) {
        player.resetPlayer();
        end_game = false;
        return GAME_OVER_STATE;
    }
    return GAME_STATE;
}
//credits to Filip
void Game_State::check_objs() {
    for (size_t i = 0; i < game_objs.size(); i++) {
        if (!game_objs[i]->update(player, button, game_objs)) {
            // Remove this element.
            std::cout << "delete obj " << typeid(*game_objs[i]).name() << std::endl;
            game_objs.erase(game_objs.begin() + i);
            i--;
        }
    }
}
