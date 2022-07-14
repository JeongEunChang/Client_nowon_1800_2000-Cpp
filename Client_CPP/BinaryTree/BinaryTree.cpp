#include "BinaryTree.h"

Node& BinaryTree::Find(int item)
{
    if (_root == nullptr) return;

    _tmp = _root;

    while (_tmp != nullptr)
    {
        // 찾고자 하는 값이 현재 노드보다 작을 때
        if (_tmp->_data > item)
            _tmp = _tmp->_left;
        // 찾고자 하는 값이 현재 노드보다 클 때
        else if (_tmp->_data < item)
            _tmp = _tmp->_right;
        // 찾고자 하는 값이 현재 노드와 같을 때
        else
            return *_tmp;
    }

    return *_tmp;
}

void BinaryTree::Insert(int item)
{
    if (_root != nullptr) {
        _tmp = _root;
        while (_tmp->_data > item)
        {
            // 삽입하고자 하는 값이 현재 노드보다 작을 때
            if (_tmp->_data > item)
            {
                // 현재 노드에 왼쪽 자식이 있으면
                if (_tmp->_left != nullptr)
                    _tmp = _tmp->_left;
                // 현재 노드에 왼쪽 자식이 없으면
                else {
                    _tmp->_left = new Node();
                    _tmp->_left->_data = item;
                    return;
                }
            }

            else if (_tmp->_data < item) {
                // 현재 노드에 오른쪽 자식이 있으면
                if (_tmp->_right != nullptr)
                    _tmp = _tmp->_right;
                // 현재 노드에 오른쪽 자식이 없으면
                else {
                    _tmp->_right = new Node();
                    _tmp->_right->_data = item;
                    return;
                }
            }
            else
        }
    }
    else {
        _root = new Node();
        _root->_data = item;
    }
}

bool BinaryTree::Remove(int item)
{
    bool doRemoved = false;

    if (_root == nullptr) 
        return doRemoved;

    _tmp = _root;

    while (_tmp != nullptr)
    {
        // 삭제하려는 값이 현재 노드 값보다 작을 경우
        if (_tmp->_data > item)
            _tmp = _tmp->_left;
        // 삭제하려는 값이 현재 노드 값보다 클 경우
        else if (_tmp->_data < item)
            _tmp = _tmp->_right;
        // 삭제하려는 값이 현재 노드와 같을 경우
        else{
            doRemoved = true;
            break;
        }
    }

    if (doRemoved) {

    }

    return doRemoved;
}
