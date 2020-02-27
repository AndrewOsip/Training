#include <fstream>
#include <algorithm>

#include "Vector.h"

void Vector::vocebWrite()
{
    std::string line;

    std::string vocebPath = "../texts/dictionary.txt";

    std::ifstream in(vocebPath);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            mVocebVector.push_back(line);
        }
    }
    in.close();
    std::sort(mVocebVector.begin(),mVocebVector.end());
}
