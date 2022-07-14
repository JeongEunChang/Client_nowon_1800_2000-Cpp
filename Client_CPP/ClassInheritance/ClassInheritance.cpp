#include <iostream>
#include <windows.h>
#include "Creature.h"
#include "Dog.h"

using namespace std;

int main()
{
    Creature* creature1 = new Creature();
    Dog* dog1 = new Dog();

    int elapsedTime = 0;

    while (true)
    {
        // 크리처 숨쉬기
        creature1->Breath();

        cout << "크리처 나이 " << creature1->age
            << "크리처 높이 " << creature1->height
            << "크리처 질량" << creature1->mass << endl;


        // 개 숨쉬기
        dog1->Breath();

        cout << "개 나이 " << dog1->age
            << "개 높이 " << dog1->height
            << "개 질량" << dog1->mass << endl;
        
        
        Sleep(1000);

        if (elapsedTime > 2)
        {
            dog1->Bite(creature1);
            elapsedTime = 0;
        }
        else
            elapsedTime++;
    }

    delete creature1;
    delete dog1;

    return 0;
}