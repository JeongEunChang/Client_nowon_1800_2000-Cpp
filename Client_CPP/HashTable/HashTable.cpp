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
    _tmpHash = Hash(value); // 추가하려는 value 의 해시 구하기

    // bucket 내에 해당 해시에 대한 링크드 리스트가 없으면 생성
    if (_bucket[_tmpHash] == nullptr)
        _bucket[_tmpHash] = new LinkedList<string>();

    _bucket[_tmpHash]->AddLast(value); // bucket 내의 해당 해시에 해당하는 링크드 리스트에 인자 추가
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
    int key = Hash(value); // 인자에 대한 해시 키 구함

    // 버킷에 해당 키 링크드 리스트가 있으면
    if (_bucket[key] != nullptr) {
        // 링크드 리스트에서 인자 검색 후 있으면 false, 없으면 true 반환
        return (&_bucket[key]->Find(value) == nullptr) ? false : true;
    }
    return false;
    // return(&_bucket[Hash(value)]->Find(value) == nullptr) ? false : true;
}

bool HashTable::RemoveKey(int key)
{
    // 인자 키에 해당하는 링크드 리스트가 있으면
    if (_bucket[key] != nullptr) {
        _bucket[key]->Delete(); // 링크드 리스트의 노드를 해체
        delete _bucket[key]; // 링크드 리스트 해체
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
    int key = Hash(value); // 인자로 해시 구함
    
    // 해당 키의 링크드 리스트가 있으면
    if (_bucket[key] != nullptr) {
    
        // 인자와 같은 데이터를 가진 노드 삭제
        bool isRemoved = _bucket[key]->RemoveLast(value);

        // 삭제했는데 링키드 리스트의 노드가 없으면 링크드 리스트 해제
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
