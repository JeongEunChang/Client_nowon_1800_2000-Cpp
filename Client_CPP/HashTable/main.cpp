#include <iostream>
#include "HashTable.h"

int main()
{
    HashTable *hashTable = new HashTable();
    hashTable->Add("철수");
    hashTable->Add("영희");
    cout << "철수 저장되었나요?" << hashTable->ContainsValue("철수") << endl;

    hashTable->Delete();
    return 0;
}

