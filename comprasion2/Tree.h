#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <fstream>

#include "IComprasion.h"

class Tree : public IComprasion
{
private:
    struct Node
    {
        std::string value;
        Node *left;
        Node *right;
    };

        Node *mRoot;
        void destroy_tree(Node *leaf);
        void insert(std::string key, Node *leaf);

public:
    Tree();
    ~Tree() { destroy_tree(); }

    void vocebWrite() override;
    void numOfCoinc() override;

    void insert(std::string key);
    Node *search(std::string key);
    void destroy_tree();
    Node *search(std::string key, Node *leaf);

};

#endif // TREE_H
