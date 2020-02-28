#ifndef LINEAR_H
#define LINEAR_H

#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <fstream>

#include <functional>

#include "IComprasion.h"

#define TABLE_SIZE 5000

class HashTable : public IComprasion {
public:
    void add(const std::string &value);
    bool check(const std::string &value) const;
    int getMaxCollisions() const;
    void print() const;
    void vocebWrite();
    void numOfCoinc();
private:
    std::string m_table[TABLE_SIZE];
    int max_collisions = 0;

    uint hashFunction(const std::string& s) const;
};



#endif // LINEAR_H
