#include "utils/utility.h"
#include <bitset>
#include <random>

namespace utility{
  std::bitset<101> debounce_list{};

  bool debounce(sf::Keyboard::Key key)
  {
    if (sf::Keyboard::isKeyPressed(key) && !debounce_list.test(key))
      {
	debounce_list.set(key);
	return true;
      }
    else if(!sf::Keyboard::isKeyPressed(key) && debounce_list.test(key))
      {
	debounce_list.set(key, false);
      }

    return false;
  }

  void debug_print(std::string string)
  {
    std::cout << "Debug print: " + string << std::endl;
  }

  int randomNumber(int x, int y)
  {
    std::random_device rand;
    std::uniform_int_distribution<int> randNumb(x, y);
    return randNumb(rand);
  }

}
