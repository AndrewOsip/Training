#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>

#include "HashTable.h"
#include "Text.h"

void HashTable::add(const std::string &value)
{
    uint ind = hashFunction(value);
    int start_index = ind;
    while (m_table[ind] != "" && ind < TABLE_SIZE)
        ++ind;
    if (ind == TABLE_SIZE)
        throw std::runtime_error("Can't add value to table!");
    if (ind - start_index >= max_collisions)
        max_collisions = ind - start_index;
    m_table[ind] = value;
}

bool HashTable::check(const std::string &value) const
{
    uint ind = hashFunction(value);
    for (int i = ind; i < TABLE_SIZE; ++i)
        if (m_table[i] == value)
            return true;
    return false;
}

uint HashTable::hashFunction(const std::string &s) const
{
    uint ind = 0;
    for (int i = 0; i < s.length(); ++i)
        ind += s[i] * (i+1);
    return ind % (TABLE_SIZE * 3 / 4);
}

void HashTable::vocebWrite() {
    std::cout << "Hash    ";
    std::string line;
        clock_t start_time = clock();
        while (getline(mFileName, line))
        {
            add(line);
        }
        clock_t end_time = clock();
        std::cout << end_time - start_time << " ";
    }

void HashTable::numOfCoinc()
{
    Text text;

    int a = 0;
    int b = 0;
    clock_t start_time = clock();
    for (const auto& item : text.getText()) {
        if (check(item)) {
            a += 1;
        } else {
            b += 1;
        }
    }
    clock_t end_time = clock();
    std::cout << end_time - start_time << " ";
    std::cout << a << " " << b << std::endl;
}
