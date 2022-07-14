#include "BinaryTree.h"

Node& BinaryTree::Find(int item)
{
    if (_root == nullptr) return;

    _tmp = _root;

    while (_tmp != nullptr)
    {
        // ã���� �ϴ� ���� ���� ��庸�� ���� ��
        if (_tmp->_data > item)
            _tmp = _tmp->_left;
        // ã���� �ϴ� ���� ���� ��庸�� Ŭ ��
        else if (_tmp->_data < item)
            _tmp = _tmp->_right;
        // ã���� �ϴ� ���� ���� ���� ���� ��
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
            // �����ϰ��� �ϴ� ���� ���� ��庸�� ���� ��
            if (_tmp->_data > item)
            {
                // ���� ��忡 ���� �ڽ��� ������
                if (_tmp->_left != nullptr)
                    _tmp = _tmp->_left;
                // ���� ��忡 ���� �ڽ��� ������
                else {
                    _tmp->_left = new Node();
                    _tmp->_left->_data = item;
                    return;
                }
            }

            else if (_tmp->_data < item) {
                // ���� ��忡 ������ �ڽ��� ������
                if (_tmp->_right != nullptr)
                    _tmp = _tmp->_right;
                // ���� ��忡 ������ �ڽ��� ������
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
        // �����Ϸ��� ���� ���� ��� ������ ���� ���
        if (_tmp->_data > item)
            _tmp = _tmp->_left;
        // �����Ϸ��� ���� ���� ��� ������ Ŭ ���
        else if (_tmp->_data < item)
            _tmp = _tmp->_right;
        // �����Ϸ��� ���� ���� ���� ���� ���
        else{
            doRemoved = true;
            break;
        }
    }

    if (doRemoved) {

    }

    return doRemoved;
}
