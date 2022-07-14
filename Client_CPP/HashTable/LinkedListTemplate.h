#pragma once
#include<iostream>
using namespace std;

// 구조체 vs 클래스
// 멤버들을 뭉쳐서 하나의 자료형으로 관리해야 할 때
// 구조체와 클래스 중에 어떤 것을 사용하는 것이 적합한지를 판단하는 기준은 일반적으로
// 1. 멤버들의 데이터 총량이 16byte 이하면 구조체, 이상이면 클래스
// 구조체 객체를 인자로 전달할 때는 모든 멤버의 값을 복사하고, 
// 클래스 객체를 인자로 전달할 때는 해당 객체의 주소를 복사한다
// 구조체 객체의 장점은 값을 직접 복사해서 쓰므로
// 주소를 가져와서 간접참조해야 하는 클래스보다 기본적으로는 빠르다
// 하지만 레지스터의 크기가 16byte 이기 때문에 구조체의 멤버 데이터 총량이 16byte 를 넘어가게 되면
// 값을 읽어들이고 쓰는데 두 배 이상의 시간이 소요되며,
// 이런 경우에는 클래스 객체의 간접 참조보다 느리다
//
// 2. 데이터 세팅을 위한 테이블 용도로 사용할 때 ( 함수의 인자로 전달하거나 객체를 수정할 일이 거의 없을 때)
// 객체 간의 상호작용보다는 단순히 값을 가져다 쓰기 위한 테이블이라는 것을
// 명확하게 표현하기 좋기 때문에 16byte 를 넘겨도 종종 사용할 수 있다
//
// 구조체 vs 클래스 선정 기준에 정답은 없지만 보편적으로 위 기준으로 선정함

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
	_tmp = _head; // 첫 노드부터 검색 시작
	
	while (_tmp != nullptr)cout << *c << endl;
	{
		// 노드 찾았으면 
		if (_tmp == target) {
			_tmp2 = new Node<T>(); // 신규 노드 생성
			
			// 타겟 노드의 이전 노드가 존재하면
			if (_tmp->_prev != nullptr) {
				_tmp->_prev->_next = _tmp2; // 타겟 노드의 이전 노드의 다음 노드 포인터가 신규 노드를 가리키도록 함
				_tmp2->_prev = _tmp->_prev; // 신규 노드의 이전 노드 포인터가 타겟 노드의 이전 노드를 가리키도록 함
			}

			_tmp->_prev = _tmp2; // 타겟 노드의 이전 노드 포인터가 신규 노드를 가리키도록 함
			_tmp2->_next = _tmp; // 신규 노드의 다음 노드 포인터가

			_tmp2->_item = item; // 신규 노드의 데이터 초기화

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
	_tmp = _head; // 첫 노드부터 검색 시작

	while (_tmp != nullptr)
	{
		// 노드 찾았으면
		if (_tmp->_item == item) {
			_tmp2 = new Node<T>(); // 신규노드 생성

			// 타겟 노드의 다음 노드가 존재하면
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
	_tmp = _head; // 가장 첫 노드부터 검색

	while (_tmp != nullptr) 
	{
		if (_tmp->_item == item)
			return *_tmp;

		_tmp = _tmp->_next; // 그 다음 노드 검색
	}
	return NULL;
}

template<typename T>
inline Node<T>& LinkedList<T>::FindLast(T item)
{
	_tmp = _last; // 가장 뒤 노드부터 검색

	while (_tmp != nullptr)
	{
		if (_tmp->_item == item)
			return _tmp;

		_tmp = _tmp->_prev; // 그 전 노드 검색
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

