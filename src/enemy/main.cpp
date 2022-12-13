#include <SFML/Graphics.hpp>
#include "enemy/enemy.h"
#include "enemy/enemyHandler.h"
#include <iostream>

const size_t width = 1280;
const size_t height = 720;


int main() {
  sf::RenderWindow window{sf::VideoMode{width, height}, "Demo"};
  window.setKeyRepeatEnabled(false);
  window.setVerticalSyncEnabled(true);    


  HandleEnemies enemies;

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
    sf::Vector2i position = sf::Mouse::getPosition(window);
    
    window.clear();
    enemies.rendering(window, position);
    window.display();
  }

  return 0;
}
