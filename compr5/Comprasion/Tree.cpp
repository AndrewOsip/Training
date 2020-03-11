#include <chrono>
#include <iostream>

#include "Tree.h"
#include "Text.h"

void Tree::destroy_tree(Node *leaf){
    if(leaf != nullptr){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void Tree::insert(std::string key, Node *leaf){

    if(key < leaf->value){
        if(leaf->left != nullptr){
            insert(key, leaf->left);
        }else{
            leaf->left = new Node;
            leaf->left->value = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }else if(key >= leaf->value){
        if(leaf->right != nullptr){
            insert(key, leaf->right);
        }else{
            leaf->right = new Node;
            leaf->right->value = key;
            leaf->right->right = nullptr;
            leaf->right->left = nullptr;
        }
    }
}

void Tree::insert(std::string key){
    if(mRoot != nullptr){
        insert(key, mRoot);
    }else{
        mRoot = new Node;
        mRoot->value = key;
        mRoot->left = nullptr;
        mRoot->right = nullptr;
    }
}

Tree::Node *Tree::search(std::string key, Node *leaf){
    if(leaf != nullptr){
        if(key == leaf->value){
            return leaf;
        }
        if(key < leaf->value){
            return search(key, leaf->left);
        }else{
            return search(key, leaf->right);
        }
    }else{
        return nullptr;
    }
}

Tree::Node *Tree::search(std::string key){
    return search(key, mRoot);
}

void Tree::destroy_tree() {
    destroy_tree(mRoot);
}

void Tree::vocebWrite() {

    std::cout << "Tree\t";
    std::string line;

    clock_t start_time = clock();
    while (getline(mFileName, line))
    {
        insert(line);
    }

    clock_t end_time = clock();
    std::cout << end_time - start_time << "\t";
}

void Tree::numOfCoinc()
{
    Text text;

    int a = 0;
    int b = 0;

    clock_t start_time = clock();

    for (const auto& item : text.getText()) {
        if (search(item) != nullptr) {
            a += 1;
        } else {
            b += 1;
        }
    }
    clock_t end_time = clock();
    std::cout << end_time - start_time << "\t";
    std::cout << a << "\t" << b << std::endl;
 }
