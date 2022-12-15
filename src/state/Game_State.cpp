#include "state/Game_State.h"
#include "utils/Button_Manager.h"

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

    Player player;
}

int Game_State::get_current_state()
{
    return curr_state;
}

void Game_State::update(sf::Time delta)
{

    if(player.get_hp() == 0 || player.get_hp() < 0)
        end_game = true;

    player.update();
    spell.update(player);

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
    spell.render(target, player);
    player.renderPlayerGUI(target);
    player.render(target);
    spell.run_spells(target, player);
    target.draw(fps);
    enemys.rendering(target, static_cast<sf::Vector2i>(player.getPlayerPos()), player, spell, end_game);
}

int Game_State::get_next_state()
{
    if(end_game) {
        player.resetPlayer();
        enemys.resetEnemies();
        end_game = false;
        return GAME_OVER_STATE;
    }
    return GAME_STATE;
}

/**    float lastTime = 0.f;
    float currentTime = clock.restart().asSeconds();
    float fps1 = 1.f / (currentTime - lastTime);
    lastTime = currentTime;

    fps = Text(std::to_string((int)fps1), font, 32);
    fps.setPosition(0, 680);
    fps.setColor(sf::Color::Black);**/