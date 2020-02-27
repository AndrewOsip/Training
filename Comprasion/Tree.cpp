#include "Tree.h"



Tree::Tree()
    : mRoot{nullptr}
{
}

void Tree::deleteNode(Node *leaf)
{
    if (leaf != nullptr)
    {
        deleteNode(leaf->left);
        deleteNode(leaf->right);
        delete leaf;
    }
}

void Tree::insertNode(char key, Node *leaf)
{
    if (key < leaf->value)
    {
        if (leaf->left != nullptr)
        {
            insertNode(key, leaf->left);
        }
        else
        {
            leaf->left = new Node;
            leaf->left->value = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }
    else if (key >= leaf->value)
    {
        if (leaf->right != nullptr)
        {
            insertNode(key, leaf->right);
        }
        else
        {
            leaf->right = new Node;
            leaf->right->value = key;
            leaf->right->right = nullptr;
            leaf->right->left = nullptr;
        }
    }
}

void Tree::insertNewValue(char key)
{
    if (mRoot != nullptr)
    {
        insertNode(key, mRoot);
    }
    else
    {
        mRoot = new Node;
        mRoot->value = key;
        mRoot->left = nullptr;
        mRoot->right = nullptr;
    }
}

void Tree::deleteTree()
{
    deleteNode(mRoot);
}

void Tree::printTree()
{
    printNode(mRoot);
    std::cout << "\n";
}

void Tree::printNode(Node *leaf)
{
    if (leaf != nullptr)
    {
        printNode(leaf->left);
        std::cout << *leaf << " ";
        printNode(leaf->right);
    }
}


