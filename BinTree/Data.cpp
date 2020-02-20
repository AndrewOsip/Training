#include "Data.h"
#include "BinaryTree.h"

#include <iostream>

void Data::parser(){
    size_t pos = inputData.find(delimiter);
    size_t initialPos = 0;
    list.clear();

    while(pos != std::string::npos) {
        list.push_back(inputData.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;
        pos = inputData.find(delimiter, initialPos);
    }
    list.push_back(inputData.substr(initialPos, std::min(pos, inputData.size()) - initialPos + 1));
}

