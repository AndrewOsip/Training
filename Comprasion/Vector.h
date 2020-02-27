#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <string>

#include "IComprasion.h"

class Vector : public IComprasion
{
public:
    void vocebWrite();
private:
    std::vector<std::string> mVocebVector;
};

#endif // VECTOR_H
