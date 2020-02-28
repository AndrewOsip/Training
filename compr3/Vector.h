#ifndef VECTOR_H
#define VECTOR_H

#include <fstream>
#include <vector>

class Vector : std::vector<std::string>
{
public:
    Vector(const std::string& fileName)
            {
                mFileName.open(fileName);
                vocebWrite();
                numOfCoinc();
            }

    const std::vector<std::string>& provideData() const { return mVocebVector; }
    ~Vector() { mFileName.close(); }
private:
    void vocebWrite();
    void numOfCoinc();

    std::vector<std::string> mVocebVector;
    std::ifstream mFileName;
};

#endif // VECTOR_H
