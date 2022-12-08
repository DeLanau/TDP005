#include <SFML/Graphics.hpp>
#include "enemy.h"
#include "enemyHandler.h"
#include <iostream>

const size_t width = 1024;
const size_t height = 768;


int main() {
    sf::RenderWindow window{sf::VideoMode{width, height}, "Demo"};
    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);    


    HandleEnemies enemies;

    int check1{40};
    int check2{1000};
    sf::Clock clock;
    sf::Time delta = sf::milliseconds(check1);
    sf::Time delta2 = sf::milliseconds(check2);
            
    bool quit = false;
    while (!quit) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                quit = true;
                break;
            default:
              break;
            }
        }

        if (quit)
          break;

        sf::Time elapsed = clock.getElapsedTime();
	

        window.clear();

        for (auto p : enemies.getEnemies())
          {
            p->update();
            window.draw(p->getCircle());
            if (elapsed > delta)
              {
                p->setLocation(0, 1);
              }
          }
        if (elapsed > delta)
          {
            delta += sf::milliseconds(check1);
          }
	if (elapsed > delta2)
          {
            enemies.createNew();
            delta2 += sf::milliseconds(check2);
          }


        window.display();
    }

    return 0;
}
