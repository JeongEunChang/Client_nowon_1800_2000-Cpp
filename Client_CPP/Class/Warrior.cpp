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
	cout << "����!" << endl;
}

void Warrior::SetHP(int hp)
{
	_hp = hp;
	cout << "�� ä���� ����" << _hp << "��" << endl;
}

int Warrior::GetHP()
{
	return _hp;
}