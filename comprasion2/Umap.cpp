#include <fstream>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <functional>

#include "Umap.h"

void Umap::vocebWrite()
{
    std::string line;

    std::string vocebPath = "../texts/dictionary.txt";

    std::ifstream in(vocebPath);
    if (in.is_open())
    {
        std::cout << "Umap ";
        clock_t start_time = clock();
        while (getline(in, line))
        {
            std::hash<std::string> hash_fn;
            mUMap.insert(std::make_pair(hash_fn(line), line));

        }
        clock_t end_time = clock();
        std::cout << end_time - start_time << " ";
    }
    in.close();
}

void Umap::numOfCoinc()
{
    IComprasion::Text text;

    int a = 0;
    int b = 0;

    std::hash<std::string> hash_fn;

    clock_t start_time = clock();

    for (const auto& item : text.getText()) {
        if (mUMap.find(hash_fn(item)) != std::end(mUMap)) {
            a += 1;
        } else {
            b += 1;
        }
    }

    clock_t end_time = clock();
    std::cout << end_time - start_time << " ";

    std::cout << a << " " << b << std::endl;
}
