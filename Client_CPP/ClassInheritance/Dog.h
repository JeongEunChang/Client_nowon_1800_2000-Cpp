#pragma once
#include "Creature.h"

// Ŭ���� ���
// class Ŭ���� �̸� : ��� ���� �̸� (�θ� Ŭ����)

class Dog :
    public Creature
{
public:
    int tailLength;
    
public:
    void Bite(Creature* creature);
};

