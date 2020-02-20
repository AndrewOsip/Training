#ifndef IBINTREE_H
#define IBINTREE_H

#include "Node.h"

class ITree{
public:
    ITree() = default;
    virtual ~ITree() = default;

    virtual void insert(int key) = 0;
    virtual Node *search(int key) = 0;
    virtual void destroy_tree() = 0;
    virtual void convert_print() = 0;
    virtual void input_print() = 0;
};

#endif // IBINTREE_H
