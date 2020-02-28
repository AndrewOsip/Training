#include <iostream>
#include <ctime>
#include <algorithm>

#include "Vector.h"
#include "Text.h"

void Vector::vocebWrite() {
    std::cout << "Vector " << " ";
    std::string line;
    clock_t s_time = clock();
    while (getline(mFileName, line))
    {
        mVocebVector.push_back(line);
    }
    clock_t e_time = clock();
    std::cout << e_time - s_time << " ";
}

void Vector::numOfCoinc() {
    clock_t s_time = clock();
    Text text;
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
