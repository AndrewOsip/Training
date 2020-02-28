#include <fstream>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <functional>

#include "Umap.h"
#include "Text.h"

void Umap::vocebWrite()
{
    std::cout << "Umap    ";
    std::string line;
    clock_t start_time = clock();
    while (getline(mFileName, line))
    {
        std::hash<std::string> hash_fn;
        this->insert(std::make_pair(hash_fn(line), line));

    }
    clock_t end_time = clock();
    std::cout << end_time - start_time << " ";
}

void Umap::numOfCoinc()
{
    Text text;

    int a = 0;
    int b = 0;

    std::hash<std::string> hash_fn;

    clock_t start_time = clock();

    for (const auto& item : text.getText()) {
        if (this->find(hash_fn(item)) != std::end(mUMap)) {
            a += 1;
        } else {
            b += 1;
        }
    }

    clock_t end_time = clock();
    std::cout << end_time - start_time << "   ";

    std::cout << a << " " << b << std::endl;
}
