#ifndef TREE_H
#define TREE_H

#include <string>
#include <fstream>

class Tree
{
private:
    struct Node
    {
        std::string value;
        Node *left;
        Node *right;
    };

public:
    Tree(const std::string& fileName) : mRoot{nullptr}
    {
        mFileName.open(fileName);
        vocebWrite();
        numOfCoinc();
    }

    ~Tree()
    {
        destroy_tree();
        mFileName.close();
    }

private:
    void insert(std::string key);
    void insert(std::string key, Node *leaf);
    Node *search(std::string key);
    Node *search(std::string key, Node *leaf);
    void destroy_tree();
    void destroy_tree(Node *leaf);

    void vocebWrite();
    void numOfCoinc();

    std::ifstream mFileName;
    Node *mRoot;
};


#endif // TREE_H
