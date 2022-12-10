#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

namespace utility 
{

  bool debounce(sf::Keyboard::Key key);

  void debug_print(std::string str);

  int randomNumber(int x, int y);
}
