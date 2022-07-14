#pragma once
#include "Creature.h"

// 클래스 상속
// class 클래스 이름 : 상속 받을 이름 (부모 클래스)

class Dog :
    public Creature
{
public:
    int tailLength;
    
public:
    void Bite(Creature* creature);
};

