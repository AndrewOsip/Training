#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <string>

#include "IComprasion.h"

class Vector : public IComprasion
{
public:
    void vocebWrite() override;
    void numOfCoinc() override;
    std::vector<std::string> mVocebVector;
private:
};

#endif // VECTOR_H
