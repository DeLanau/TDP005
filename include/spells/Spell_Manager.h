//
// Created by nadla777 on 12/6/22.
//

#pragma once
#include "Base_Spell.h"

class Spell_Manager
{

public:

    Spell_Manager();
    ~Spell_Manager();

    void update();

    void render();

private:
    std::map<int, std::unique_ptr<Base_Spell>> spells;
};
