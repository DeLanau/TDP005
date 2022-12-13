#include "engine.h"
#include "utils/utility.h"

using namespace sf;

#define Game_state::Game_State(), Menu_State::Menu_State(), Game_Over_State::Game_Over_State();

Engine::Engine() :
    window { VideoMode{1280, 720, 64 },
    "TDP005", Style::Titlebar | Style::Close},
    current_state{MENU_STATE},
    states{}
{

    states.insert(std::pair<int, std::unique_ptr<Base_State>>({MENU_STATE, std::make_unique<Menu_State>()}));
    states.insert(std::pair<int, std::unique_ptr<Base_State>>({GAME_STATE, std::make_unique<Game_State>()}));
    //  states.insert(std::pair<int, std::unique_ptr<Base_State>>({GAME_OVER_STATE, std::make_unique<Game_Over_State>()}));

}

int Engine::run()
{
    sf::Clock clock;

    while(window.isOpen()) {

        if (utility::debounce(sf::Keyboard::Escape))
            window.close();

        current_state = states.at(current_state)->get_current_state();
        states.at(current_state)->update(clock.restart());
        window.clear();
        states.at(current_state)->render(window);
        window.display();
        current_state = states.at(current_state)->get_next_state();

        if (current_state == QUIT_STATE)
            window.close();

        window.setFramerateLimit(60);
    }
}