#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 150000

#include <string>
#include <fstream>

class HashTable
{
public:
    HashTable(const std::string& fileName) {
        mFileName.open(fileName);
        vocebWrite();
        numOfCoinc();
    }

    ~HashTable() { mFileName.close(); }
private:
    std::string m_table[TABLE_SIZE];
    int max_collisions = 0;
    uint hashFunction(const std::string& s) const;

    void add(const std::string &value);
    bool check(const std::string &value) const;
    void vocebWrite();
    void numOfCoinc();

    std::ifstream mFileName;
};

#endif // HASHTABLE_H
