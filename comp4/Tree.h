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


    void insert(std::string key);
    Node *search(std::string key);
    void destroy_tree();
    Node *search(std::string key, Node *leaf);

private:
    void vocebWrite();
    void numOfCoinc();

        Node *mRoot;
        void destroy_tree(Node *leaf);
        void insert(std::string key, Node *leaf);

        std::ifstream mFileName;
};


#endif // TREE_H
