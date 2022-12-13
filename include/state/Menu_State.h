#pragma once

#include "Base_State.h"
#include "engine.h"

class Menu_State : public Base_State
{
public:
    Menu_State();

    virtual ~Menu_State() = default;

    virtual void update(sf::Time delta) override;

    virtual void render(sf::RenderTarget & target) override;
        
    virtual int get_current_state() override;

    virtual int get_next_state() override;

private:
    void move_up();
    void move_down();
    
    unsigned int curr_state{0}, button_select{}, button_state{};
    sf::Texture texture;
    sf::Font font;
    sf::Sprite sprite;
    sf::Text play_selection, exit_selection;
    bool play{false};
};
