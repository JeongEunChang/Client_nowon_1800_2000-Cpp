#include "Warrior.h"
#include <iostream>
using namespace std;

/*arrior* Warrior::GetInstance()
{
	if (_instance == nullptr)
		_instance = new Warrior();
	return _instance;
}*/

Warrior* Warrior::_instance = NULL;

Warrior* Warrior::GetInstance()
{
	if (_instance == nullptr)
		_instance = new Warrior();
	return _instance;
}

void Warrior::Attack()
{
	cout << "공격!" << endl;
}

void Warrior::SetHP(int hp)
{
	_hp = hp;
	cout << "내 채력은 현재" << _hp << "야" << endl;
}

int Warrior::GetHP()
{
	return _hp;
}