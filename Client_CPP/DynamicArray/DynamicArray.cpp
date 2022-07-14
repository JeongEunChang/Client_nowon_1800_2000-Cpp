#include "DynamicArray.h"

// Camel case : �� �ܾ��� ���� ���ĺ��� �빮�ڷ� ǥ���ϴ� ���
// ���� ���� �̸� ���� ���ĺ��� �ҹ���, �׿� ����� ǥ����


int DynamicArray::Length()
{
    return this->_length;
}

void DynamicArray::Add(int item)
{
    // �迭�� ũ�Ⱑ ������� ������ ���� ������ �� ��� �ø���
    if (_length >= _capacity) {
        _capacity *= 2;
        int* tmp = new int[_capacity];

        for (int i = 0; i < _length; i++)
            tmp[i] = _data[i];
        delete[] _data;
        _data = new int[_capacity];

        for (int i = 0; i < _length; i++)
            _data[i] = tmp[i];
        delete[] tmp;
    }
    _data[_length] = item;
    _length++;
}

// ������ �˻� ���� �� �ش� ������ �ε��� ��ȯ, ���� �� -1 ��ȯ
int DynamicArray::Find(int item)
{
    for (int i = 0; i < _length; i++) {
        if (_data[i] == item)
            return i;
    }
    return -1;
}

// ������ �˻� ���� �� �ش� ������ 1 ��ȯ, ���� �� 0 ��ȯ
bool DynamicArray::IsExist(int item)
{
    for (int i = 0; i < _length; i++) {
        if (_data[i] == item)
            return true;
    }
    return false;
}

// Ư�� �������� ����� �Լ�
//����µ� �����ϸ� true, �����ϸ� false
bool DynamicArray::Remove(int item)
{
    for (int i = 0; i < _length; i++) {
        if (_data[i] == item)
            return RemoveAt(i);
    }
    return false;
}

// Ư�� �ε����� ����� �Լ�
// ����µ� �����ϸ� true, ������� false ��ȯ
bool DynamicArray::RemoveAt(int index)
{
    if (index >= _length) {
        for (int i = index; i < _length - 1; i++) {
            _data[i] = _data[i + 1];
        }
        _length--;
        return true;
    }
    return false;
}

//void DynamicArray::Delete()
//{
//    delete[] _data;
//}

DynamicArray::DynamicArray()
    : DEFAULT_SIZE(1)
    // �̴ϼ� ������ : ������ �Լ� ���� ���� ���� ��� �ʱ�ȭ�� �� �� ����Ѵ�
{
    _length = 0;
    _capacity = DEFAULT_SIZE;
    _data = new int[_capacity];
}

DynamicArray::~DynamicArray()
{
    delete[] _data;
}
