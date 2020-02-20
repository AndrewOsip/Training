#include <iostream>

#include "Data.h"
#include "BinaryTree.h"

int main()
{
    Data data;
    BinaryTree *tree = new BinaryTree();
    while (data.inputData != "0")
    {
    std::cout << "Plese enter your value: ";
    getline(std::cin, data.inputData);
    data.parser();
    }

    for(auto it = data.list.begin(); it != data.list.end(); it++) {
    tree->insert(std::stoi(*it));
    }

    tree->input_print();
    tree->convert_print();

    return 0;
}
