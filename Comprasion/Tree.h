#ifndef TREE_H
#define TREE_H

#include <iostream>

#include "IComprasion.h"

class Tree : public IComprasion
{
public:
    Tree();
    ~Tree() { deleteTree(); }

    void insertNewValue(char key);
    void deleteTree();
    void printTree();

private:
    struct Node
    {
        int value;
        Node *left;
        Node *right;

        friend std::ostream &operator<<(std::ostream &os, const Node &node)
        {
            return os << node.value;
        }
    };

    Node *mRoot;

    void insertNode(char key, Node *leaf);
    void printNode(Node *leaf);
    void deleteNode(Node *leaf);
};

#endif // TREE_H
