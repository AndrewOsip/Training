#ifndef IBINTREE_H
#define IBINTREE_H

class IBinTree{
public:
    struct Node
    {
        int value;
        Node *left;
        Node *right;
    };

    IBinTree() = default;
    virtual ~IBinTree() = default;

    virtual void destroy_tree(Node *leaf) = 0;
    virtual void insert(int key, Node *leaf) = 0;
    virtual Node *search(int key, Node *leaf) = 0;
    virtual void convert_print(Node *leaf) = 0;
    virtual void input_print(Node *leaf) = 0;

    Node *root;

    virtual void insert(int key) = 0;
    virtual Node *search(int key) = 0;
    virtual void destroy_tree() = 0;
    virtual void convert_print() = 0;
    virtual void input_print() = 0;
};

#endif // IBINTREE_H
