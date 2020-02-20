#include <iostream>

#include "Data.h"
#include "BinaryTree.h"

int main()
{
    Data data;
    BinaryTree *tree = new BinaryTree();

    data.parser(data);

    for(auto it = data.list.begin(); it != data.list.end(); it++) {
        tree->insert(std::stoi(*it));
    }

    tree->convert_print();
    tree->destroy_tree();

    return 0;
}
