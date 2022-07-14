#pragma once
#include "LinkedListTemplate.h"
#include <string>

using namespace std;

class HashTable
{
private:
	const int DEFAULT_SIZE = 100;
	LinkedList<string>** _bucket;
	int _tmpHash;

public:
	HashTable();
	void Add(string value);
	bool ContainsKey(int key);
	bool ContainsKey(string value);
	bool ContainsValue(string value);
	bool RemoveKey(int key);
	bool RemoveKey(string value);
	bool RemoveValue(string value);
	int Hash(string value);
	void Clear();
	void Delete();



};

