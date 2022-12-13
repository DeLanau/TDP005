#pragma once

#include "spells/Spell_Manager.h"

#include <iostream>

Spell_Manager::Spell_Manager() :
  water{}, earth{}, fire{}, wind{}
{

}

Spell_Manager::~Spell_Manager() {
}

void Spell_Manager::update(Player & player)
{
  buttons.update();
}

void Spell_Manager::render(sf::RenderTarget & target, Player & player)
{
  buttons.render(target);
  run_spells(target, player);
}

void Spell_Manager::run_spells(sf::RenderTarget &target, Player &player) {
  if(buttons.get_spell_active() && player.get_mana() >= 1) {
    switch (buttons.get_current_button_id()) {
    case 0:
      if (player.get_hp()< 100)
	{
      water.update(player);
      water.render(target);
      player.set_mana(-water.get_mana());
	}
      break;
    case 1:
      earth.update(player);
      earth.render(target);
      player.set_mana(-earth.get_mana());
      break;
    case 2:
      fire.update(player);
      fire.render(target);
      player.set_mana(-fire.get_mana());
      break;
    case 3:
      wind.update(player);
      wind.render(target);
      player.set_mana(-wind.get_mana());
      break;

    }
  }
  
  else
    buttons.set_spell_active(false);
}
