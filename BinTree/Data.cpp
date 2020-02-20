#include "Data.h"
#include "BinTree.h"

#include <iostream>

void Data::parser(){
    size_t pos = mInputData.find(mDelimiter);
    size_t initialPos = 0;
    mList.clear();

    while(pos != std::string::npos) {
        mList.push_back(mInputData.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;
        pos = mInputData.find(mDelimiter, initialPos);
    }
    mList.push_back(mInputData.substr(initialPos, std::min(pos, mInputData.size()) - initialPos + 1));
}

void Data::inputPrint()
{
    BinTree *tree = new BinTree();
    std::cout << "Plese enter your values with spaces: ";
    getline(std::cin, mInputData);
    parser();

    for(auto it = mList.begin(); it != mList.end(); it++) {
    tree->insert(std::stoi(*it));
    }

    tree->input_print();
    tree->convert_print();

    delete tree;
}
