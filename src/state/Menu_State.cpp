#include "state/Menu_State.h"
#include "utils/utility.h"

using namespace sf; 

Menu_State::Menu_State() : texture{Resource_Manager<sf::Texture>::load("resources/menubg.jpg")},
                           font{Resource_Manager<sf::Font>::load("resources/font/toppo.ttf")},
                           sprite{}, play_selection{}, exit_selection{}, button_select{}, play{false}, button_state{0}
{
    utility::debug_print("Menu state on");
    sprite.setTexture(texture);
    
    sprite.setOrigin(0,0);
    play_selection = Text("Start game", font, 32);
    exit_selection = Text("Exit game", font, 32);

    button_select = 0;

    auto play_selection_bounds{play_selection.getGlobalBounds()};
    auto exit_selection_bounds{exit_selection.getGlobalBounds()};

    play_selection.setPosition((1280 - play_selection_bounds.width )/ 2, 100);
    exit_selection.setPosition((1280 - exit_selection_bounds.width )/ 2, 200);
     
}

int Menu_State::get_current_state()
{
    return curr_state;
}

void Menu_State::update(sf::Time delta)
{
    button_state = MENU_STATE;
    if (utility::debounce(sf::Keyboard::Up) && button_select != 0)
        move_up();
    else if (utility::debounce(sf::Keyboard::Down) && button_select !=  1)
        move_down();

    if(utility::debounce(Keyboard::Key::Return))
        switch(button_select)
        {
            case 0:
                button_state = GAME_STATE;
                break;
            case 1:
                button_state = QUIT_STATE;
                break;
        }
}

void Menu_State::render(RenderTarget & target)
{
    target.draw(sprite);
    target.draw(play_selection);
    target.draw(exit_selection);
}

int Menu_State::get_next_state()
{
    return button_state;
}

void Menu_State::move_up()
{
    if(button_select - 1 >= 0)
    {
        //sound.play();
        play_selection.setColor(Color::Yellow);
        play_selection.setCharacterSize(42);
        button_select--;
        exit_selection.setColor(Color::White);
        exit_selection.setCharacterSize(32);
    }
}

void Menu_State::move_down()
{
    if(button_select + 1 < 2)
    {
        //sound.play();
        play_selection.setColor(Color::White);
        play_selection.setCharacterSize(32);
        button_select++;
        exit_selection.setColor(Color::Yellow);
        exit_selection.setCharacterSize(42);
    }  
}