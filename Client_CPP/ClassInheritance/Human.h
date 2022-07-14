#pragma once
#include <string>
#include "Creature.h"

using namespace std;

class Human :
    public Creature
{

private:
    int clothesNum;

public:
    string* clothes;

public:
    void WearCloth(string cloth);
};

