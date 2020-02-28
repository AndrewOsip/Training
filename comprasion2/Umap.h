#ifndef UMAP_H
#define UMAP_H

#include <unordered_map>

#include "IComprasion.h"

class Umap : public IComprasion
{
public:
    void vocebWrite() override;
    void numOfCoinc() override;
private:
    std::unordered_map<uint, std::string> mUMap;
};

#endif // UMAP_H
