#ifndef BINTREE_H
#define BINTREE_H

#include "ITree.h"

class BinaryTree : public ITree
{
public:
    BinaryTree() { root = nullptr; }
    ~BinaryTree() override { destroy_tree(); }

    void insert(int key) override;
    Node *search(int key) override;
    void destroy_tree() override;
    void convert_print() override;
    void input_print() override;

private:
    Node *root;
    void destroy_tree(Node *leaf);
    void insert(int key, Node *leaf);
    Node *search(int key, Node *leaf);
    void convert_print(Node *leaf);
    void input_print(Node *leaf);
};

#endif // BINTREE_H
