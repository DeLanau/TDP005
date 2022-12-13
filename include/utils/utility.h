#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
/**
 * @brief namespace utility with helpfull functions
 * 
 */
namespace utility 
{
/**
 * @brief check if key is debounced
 * 
 * @param key 
 * @return true 
 * @return false 
 */
bool debounce(sf::Keyboard::Key key);
/**
 * @brief print debug text without importing <iostream> and using std::cout & std::endl;
 * 
 * @param str 
 */
void debug_print(std::string str);

int randomNumber(int const& x, int const& y);

}