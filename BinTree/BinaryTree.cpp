#include <iostream>

#include "BinaryTree.h"

void BinaryTree::destroy_tree(Node *leaf){
    if(leaf != nullptr){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BinaryTree::insert(int key, Node *leaf){

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

void BinaryTree::insert(int key){
    if(root != nullptr){
        insert(key, root);
    }else{
        root = new Node;
        root->value = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}

void BinaryTree::destroy_tree(){
    destroy_tree(root);
}

void BinaryTree::convert_print(){
    convert_print(root);
    std::cout << "\n";
}

void BinaryTree::convert_print(Node *leaf){
    if(leaf != nullptr){
        convert_print(leaf->left);
        std::cout << leaf->value << " ";
        convert_print(leaf->right);
    }
}
