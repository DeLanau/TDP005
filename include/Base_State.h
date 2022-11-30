#pragma once

#include <SFML/Graphics.hpp>

int const MENU_STATE{0};
int const GAME_STATE{1};
int const GAME_OVER_STATE{3};

class Base_State
{

public:

    virtual ~Base_State() = default;
       
    virtual void update() = 0;

    virtual void render(sf::RenderTarget & target) = 0;
       
    virtual int get_current_state() = 0;

    virtual int get_next_state() = 0; 
};

class Menu_State : public Base_State
{
public:
    Menu_State();

    virtual ~Menu_State() = default;

    virtual void update() override;

    virtual void render(sf::RenderTarget & target) override;
        
    virtual int get_current_state() override;

    virtual int get_next_state() override;

private:
    unsigned int curr_state{0};
};

class Game_State : public Base_State
{
public:
    Game_State();
        
    virtual ~Game_State() = default;
        
    virtual void update() override;

    virtual void render(sf::RenderTarget & target) override;
        
    virtual int get_current_state() override;

    virtual int get_next_state() override;
private:
     unsigned int curr_state{1};
};

class Game_Over_State : public Base_State
{
public:
    Game_Over_State();

    virtual ~Game_Over_State() = default;

    virtual void update() override;

    virtual void render(sf::RenderTarget & target) override;
        
    virtual int get_current_state() override;

    virtual int get_next_state() override;

private:
    unsigned int curr_state{2};
};
