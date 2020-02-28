#include <fstream>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>

#include "Vector.h"

void Vector::vocebWrite()
{
    std::string line;

    std::string vocebPath = "../texts/dictionary.txt";

    std::ifstream in(vocebPath);
    if (in.is_open())
    {
        std::cout << "Vector ";
        clock_t start_time = clock();
        while (getline(in, line))
        {
            mVocebVector.push_back(line);
        }

        clock_t end_time = clock();
        std::cout << end_time - start_time << " ";
    }
    in.close();
    std::sort(mVocebVector.begin(),mVocebVector.end());
}

void Vector::numOfCoinc()
{
    clock_t s_time = clock();
    IComprasion::Text text;
    std::vector<std::string> v;

    int a = 0;
    int b = 0;

    for (auto& item : text.getText()) {
        if (std::binary_search(mVocebVector.begin(), mVocebVector.end(), item)) {
            a += 1;
        } else {
            b += 1;
        }
    }

    clock_t e_time = clock();

    std::cout << e_time - s_time << " ";
    std::cout << a << " " << b << std::endl;
}
