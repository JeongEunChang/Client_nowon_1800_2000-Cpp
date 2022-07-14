#pragma once
#include<iostream>
using namespace std;

// ����ü vs Ŭ����
// ������� ���ļ� �ϳ��� �ڷ������� �����ؾ� �� ��
// ����ü�� Ŭ���� �߿� � ���� ����ϴ� ���� ���������� �Ǵ��ϴ� ������ �Ϲ�������
// 1. ������� ������ �ѷ��� 16byte ���ϸ� ����ü, �̻��̸� Ŭ����
// ����ü ��ü�� ���ڷ� ������ ���� ��� ����� ���� �����ϰ�, 
// Ŭ���� ��ü�� ���ڷ� ������ ���� �ش� ��ü�� �ּҸ� �����Ѵ�
// ����ü ��ü�� ������ ���� ���� �����ؼ� ���Ƿ�
// �ּҸ� �����ͼ� ���������ؾ� �ϴ� Ŭ�������� �⺻�����δ� ������
// ������ ���������� ũ�Ⱑ 16byte �̱� ������ ����ü�� ��� ������ �ѷ��� 16byte �� �Ѿ�� �Ǹ�
// ���� �о���̰� ���µ� �� �� �̻��� �ð��� �ҿ�Ǹ�,
// �̷� ��쿡�� Ŭ���� ��ü�� ���� �������� ������
//
// 2. ������ ������ ���� ���̺� �뵵�� ����� �� ( �Լ��� ���ڷ� �����ϰų� ��ü�� ������ ���� ���� ���� ��)
// ��ü ���� ��ȣ�ۿ뺸�ٴ� �ܼ��� ���� ������ ���� ���� ���̺��̶�� ����
// ��Ȯ�ϰ� ǥ���ϱ� ���� ������ 16byte �� �Ѱܵ� ���� ����� �� �ִ�
//
// ����ü vs Ŭ���� ���� ���ؿ� ������ ������ ���������� �� �������� ������

template <typename T>
class Node
{
public:
	T _item;
	Node* _prev;
	Node* _next;
};

template <typename T>
class LinkedList
{
private:
	Node<T>* _head, *_tail, *_tmp, *_tmp2;



	// bool Remove(T item)
	// bool RemoveLast(T item)
	// void Delete()

public:
	int Count();
	void AddFirst(T item);
	void AddLast(T item);
	void AddBefore(T target, T item);
	void AddBefore(Node<T>& node, T item);
	void AddAfter(Node<T>& target, T item);
	Node<T>& Find(T item);
	Node<T>& FindLast(T item);
	Node<T>& Frist();
	Node<T>& Last();
	bool Remove(T item);
	bool RemoveLast(T item);
	void Delete();
};

template<typename T>
inline int LinkedList<T>::Count()
{
	int tmpCount = 0;
	_tmp = first;
	while (_tmp != nullptr0)
	{
		_tmp = _tmp->_next;
		tmpCount++;
	}
	return tmpCount;
}

template<typename T>
inline void LinkedList<T>::AddFirst(T item)
{
	_tmp = new Node<T>();
	_tmp->_item= item;
	if (_first != nullptr) {
		_tmp->_next = _head;
		_first->_prev = _tmp;
	}
	if (_last = nullptr) {
		_last = _tmp;
	}
	_first = _tmp;
}

template<typename T>
inline void LinkedList<T>::AddLast(T item)
{
}

template<typename T>
inline void LinkedList<T>::AddBefore(T target, T item)
{
	_tmp = _head; // ù ������ �˻� ����
	
	while (_tmp != nullptr)cout << *c << endl;
	{
		// ��� ã������ 
		if (_tmp == target) {
			_tmp2 = new Node<T>(); // �ű� ��� ����
			
			// Ÿ�� ����� ���� ��尡 �����ϸ�
			if (_tmp->_prev != nullptr) {
				_tmp->_prev->_next = _tmp2; // Ÿ�� ����� ���� ����� ���� ��� �����Ͱ� �ű� ��带 ����Ű���� ��
				_tmp2->_prev = _tmp->_prev; // �ű� ����� ���� ��� �����Ͱ� Ÿ�� ����� ���� ��带 ����Ű���� ��
			}

			_tmp->_prev = _tmp2; // Ÿ�� ����� ���� ��� �����Ͱ� �ű� ��带 ����Ű���� ��
			_tmp2->_next = _tmp; // �ű� ����� ���� ��� �����Ͱ�

			_tmp2->_item = item; // �ű� ����� ������ �ʱ�ȭ

			return;
		}

		_tmp = _tmp->_next;
	}
}

template<typename T>
inline void LinkedList<T>::AddBefore(Node<T>& target, T item)
{
}

template<typename T>
inline void LinkedList<T>::AddAfter(Node<T>& target, T item)
{
	_tmp = _head; // ù ������ �˻� ����

	while (_tmp != nullptr)
	{
		// ��� ã������
		if (_tmp->_item == item) {
			_tmp2 = new Node<T>(); // �űԳ�� ����

			// Ÿ�� ����� ���� ��尡 �����ϸ�
			if (_tmp->_next != nullptr) {
				_tmp->_next->_prev = tmp2;
				_tmp2->_next = _tmp->_next;
			}

			_tmp->_next = _tmp2; // 
			_tmp2->_prev = _tmp

			return;
		}

		_tmp = _tmp->_next;
	}

}

template<typename T>
inline Node<T>& LinkedList<T>::Find(T item)
{
	_tmp = _head; // ���� ù ������ �˻�

	while (_tmp != nullptr) 
	{
		if (_tmp->_item == item)
			return *_tmp;

		_tmp = _tmp->_next; // �� ���� ��� �˻�
	}
	return NULL;
}

template<typename T>
inline Node<T>& LinkedList<T>::FindLast(T item)
{
	_tmp = _last; // ���� �� ������ �˻�

	while (_tmp != nullptr)
	{
		if (_tmp->_item == item)
			return _tmp;

		_tmp = _tmp->_prev; // �� �� ��� �˻�
	}
	
	return NULL;
}

template<typename T>
inline Node<T>& LinkedList<T>::Frist()
{
	return _head;
}

template<typename T>
inline Node<T>& LinkedList<T>::Last()
{
	return _tail;
}

template<typename T>
inline bool LinkedList<T>::Remove(T item)
{
	bool IsRemoved = flase;

	_tmp = Find(item);

	if (_tmp != nullptr) {
		if (_tmp->_prev != nullptr)
			_tmp->_prev->_next = _tmp->_next;

		if (_tmp->_prev != nullptr)
			_tmp->_next->_prev = _tmp->_prev;

		delete _tmp;
		isRemoved = true;
	}

	_tmp = nullptr;
	return IsRemoved;
}

template<typename T>
inline bool LinkedList<T>::RemoveLast(T item)
{
	bool IsRemoved = flase;

	_tmp = FindLast(item);

	if (_tmp != nullptr) {
		if (_tmp->_prev != nullptr)
			_tmp->_prev->_next = _tmp->_next;

		if (_tmp->_prev != nullptr)
			_tmp->_next->_prev = _tmp->_prev;

		delete _tmp;
		isRemoved = true;
	}

	_tmp = nullptr;
	return IsRemoved;
}

template<typename T>
inline void LinkedList<T>::Delete()
{
	_tmp = _first;

	while (_tmp != nullptr)
	{
		_tmp2 = _tmp->_next;
		delete _tmp;
		_tmp = _tmp2;
	}
}

