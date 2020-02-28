#ifndef VECTOR_H
#define VECTOR_H

#include <fstream>

#include "IVector.h"

class Vector : public IVector
{
public:
    Vector(const std::string& fileName)
            {
                mFileName.open(fileName);
                vocebWrite();
                numOfCoinc();
            }

    const std::vector<std::string>& provideData() const override { return mVocebVector; }
    ~Vector() override { mFileName.close(); }
private:
    void vocebWrite();
    void numOfCoinc();

    std::vector<std::string> mVocebVector;
    std::ifstream mFileName;
};

#endif // VECTOR_H
