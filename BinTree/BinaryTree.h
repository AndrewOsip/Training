#ifndef BINTREE_H
#define BINTREE_H

#include "ITree.h"

class BinaryTree : public ITree
{
public:
    BinaryTree() { root = nullptr; }
    ~BinaryTree() override { destroy_tree(); }

    void insert(int key) override;
    void convert_print() override;
    void destroy_tree() override;

private:
    Node *root;
    void insert(int key, Node *leaf);
    void convert_print(Node *leaf);
    void destroy_tree(Node *leaf);
};

#endif // BINTREE_H
