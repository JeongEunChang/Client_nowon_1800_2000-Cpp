#include "HashTable.h"

using namespace std;

HashTable::HashTable()
    : DEFAULT_SIZE(100)
{
    //_bucket = new LinkedList
    *_bucket = new LinkedList<string>[DEFAULT_SIZE];
}

void HashTable::Add(string value)
{
    _tmpHash = Hash(value); // �߰��Ϸ��� value �� �ؽ� ���ϱ�

    // bucket ���� �ش� �ؽÿ� ���� ��ũ�� ����Ʈ�� ������ ����
    if (_bucket[_tmpHash] == nullptr)
        _bucket[_tmpHash] = new LinkedList<string>();

    _bucket[_tmpHash]->AddLast(value); // bucket ���� �ش� �ؽÿ� �ش��ϴ� ��ũ�� ����Ʈ�� ���� �߰�
}

bool HashTable::ContainsKey(int key)
{
    if (_bucket[key] == nullptr || (key >= DEFAULT_SIZE - 1)) {
        return false;
    }
    else return true;
}

bool HashTable::ContainsKey(string value)
{
    return ContainsKey(Hash(value));
}

bool HashTable::ContainsValue(string value)
{
    int key = Hash(value); // ���ڿ� ���� �ؽ� Ű ����

    // ��Ŷ�� �ش� Ű ��ũ�� ����Ʈ�� ������
    if (_bucket[key] != nullptr) {
        // ��ũ�� ����Ʈ���� ���� �˻� �� ������ false, ������ true ��ȯ
        return (&_bucket[key]->Find(value) == nullptr) ? false : true;
    }
    return false;
    // return(&_bucket[Hash(value)]->Find(value) == nullptr) ? false : true;
}

bool HashTable::RemoveKey(int key)
{
    // ���� Ű�� �ش��ϴ� ��ũ�� ����Ʈ�� ������
    if (_bucket[key] != nullptr) {
        _bucket[key]->Delete(); // ��ũ�� ����Ʈ�� ��带 ��ü
        delete _bucket[key]; // ��ũ�� ����Ʈ ��ü
        return true;
    }
    return false;
}

bool HashTable::RemoveKey(string value)
{
    return RemoveKey(Hash(value));
}

bool HashTable::RemoveValue(string value)
{
    int key = Hash(value); // ���ڷ� �ؽ� ����
    
    // �ش� Ű�� ��ũ�� ����Ʈ�� ������
    if (_bucket[key] != nullptr) {
    
        // ���ڿ� ���� �����͸� ���� ��� ����
        bool isRemoved = _bucket[key]->RemoveLast(value);

        // �����ߴµ� ��Ű�� ����Ʈ�� ��尡 ������ ��ũ�� ����Ʈ ����
        if (isRemoved && _bucket[key]->Count() <= 0)
            delete _bucket[key];

        return _bucket[key]->RemoveLast(value);
    }
    return false;
}

int HashTable::Hash(string value)
{
    _tmpHash = 0;

    for (int i = 0; i < value.length(); i++) {
        _tmpHash += value[i];
    }

    _tmpHash %= DEFAULT_SIZE;

    return _tmpHash;
}

void HashTable::Clear()
{
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        if (_bucket[i] != nullptr) {
            _bucket[i]->Delete();
            delete _bucket;
        }
    }
}

void HashTable::Delete()
{
    Clear();
    delete _bucket;
}
