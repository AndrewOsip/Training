#ifndef BINTREE_H
#define BINTREE_H

#include "IBinTree.h"

class BinTree : public IBinTree
{
public:
    BinTree() { root = nullptr; }
    ~BinTree() override { destroy_tree(); }
    void destroy_tree(Node *leaf) override;
    void insert(int key, Node *leaf) override;
    Node *search(int key, Node *leaf) override;
    void convert_print(Node *leaf) override;
    void input_print(Node *leaf) override;

    void insert(int key) override;
    Node *search(int key) override;
    void destroy_tree() override;
    void convert_print() override;
    void input_print() override;
};

#endif // BINTREE_H
