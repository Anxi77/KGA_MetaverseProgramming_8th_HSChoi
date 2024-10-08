#pragma once
#include <iostream>
#include "Grids.h"

using namespace std;

class Character : public Grids
{
public:
    string Player;
    Character(string shape = "¡Ú") : Player(shape) {}

};

