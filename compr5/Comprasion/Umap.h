#ifndef UMAP_H
#define UMAP_H

#include <fstream>
#include <unordered_map>

class Umap : std::unordered_map<uint, std::string>
{
public:
    Umap(const std::string& fileName) {
        mFileName.open(fileName);
        vocebWrite();
        numOfCoinc();
    }

    ~Umap() { mFileName.close(); }

    const std::unordered_map<uint, std::string> provideData() const { return *this; }
private:
    void vocebWrite();
    void numOfCoinc();
    std::unordered_map<uint, std::string> mUMap;

    std::ifstream mFileName;
};

#endif // UMAP_H
