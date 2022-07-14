#pragma once

// 이진트리
// 노드 : 기본 단위
// 루트 노드(뿌리 노드) : 최상위 부모 노드
// 리프 노드(단말 노드) : 최하위 자식 노드
// 크기 : 노드 갯수
// 깊이(높이) : 층의 갯수
// 차수 : 간선 갯수

struct Node {
	int _data;
	Node* _left;
	Node* _right;
};

class BinaryTree
{
private:
	Node* _root, *_tmp, *_tmp2;

public:
	Node& Find(int item);
	void Insert(int item);
	bool Remove(int item);

};

