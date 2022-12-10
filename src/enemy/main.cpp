#include <SFML/Graphics.hpp>
#include "enemy/enemy.h"
#include "enemy/enemyHandler.h"
#include <iostream>

const size_t width = 1024;
const size_t height = 768;


int main() {
  sf::RenderWindow window{sf::VideoMode{width, height}, "Demo"};
  window.setKeyRepeatEnabled(false);
  window.setVerticalSyncEnabled(true);    


  HandleEnemies enemies;
  sf::Clock clock;

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


    
    window.clear();
    enemies.rendering(window, clock);
    window.display();
  }

  return 0;
}
