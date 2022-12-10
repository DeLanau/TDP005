//
// Created by nadla777 on 12/9/22.
//

#include "utils/Button_Manager.h"
#include "utils/utility.h"

using namespace sf;

Button_Manager::Button_Manager() :
font{Resource_Manager<sf::Font>::load("resources/font/toppo.ttf")},
QQ{}, WW{}, EE{}, RR{},
circle{}

{
    QQ = Text("Q", font, 62);
    WW = Text("W", font, 62);
    EE = Text("E", font, 62);
    RR = Text("R", font, 62);

    circle.setFillColor(sf::Color(25, 25, 25, 200));
    circle.setPosition(140, 80);
    circle.setRadius(50);

    QQ.setPosition(175, 95);
    WW.setPosition(175, 95);
    EE.setPosition(175, 95);
    RR.setPosition(175, 95);

    current_button = QQ;

}

void Button_Manager::update()
{
    current_button.setColor(Color::White);
    if(utility::debounce(sf::Keyboard::Q))
    {
        current_button = QQ;
    }else if (utility::debounce(sf::Keyboard::E))
    {
        current_button = EE;
    }
}

void Button_Manager::render(sf::RenderTarget &target)
{
   target.draw(circle);
   target.draw(current_button);
}

