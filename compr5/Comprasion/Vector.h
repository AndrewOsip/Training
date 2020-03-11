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

    ~Vector() { mFileName.close(); }
    const std::vector<std::string>& provideData() const { return *this; }
private:
    void vocebWrite();
    void numOfCoinc();

    std::ifstream mFileName;
};

#endif // VECTOR_H
