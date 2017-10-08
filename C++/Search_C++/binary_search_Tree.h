
#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>
using namespace std;
template<typename KEY, typename VALUE>
class BST
{
private:
    class Node
    {
        KEY key;
        VALUE value;
        Node * pLeft;
        Node * pRight;

    public:
        Node(KEY key,VALUE value)
        {
            this->key=key;
            this->value=value;
            this->pLeft=this->pRight=nullptr;
        }
    };

    Node * root;
    int count;

public:
    BST()
    {
        root=nullptr;
        count=0;
    }

    ~BST()
    {

    }

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void insert(KEY key, VALUE value)
    {
        root = insert(root,key,value);
    }

private:
    Node * insert(Node * root, KEY key, VALUE value)
    {
        if (root == nullptr)
        {
            count++;
            return new Node(key,value);
        }

        if(root->key == key)
        {
            root->value = value;
            return root;
        }
        else if (root->key < key)
        {
            root->pRight = insert(root->pRight,key,value);
        }
        else
        {
            root->pLeft = insert(root->pLeft,key,value);
        }

    }
};


#endif // BINARY_SEARCH_TREE_H_
