#ifndef DATA_H
#define DATA_H

#include "IData.h"
#include <string>
#include <list>

class Data : public IData
{
public:
    void parser() override;

    std::string inputData;
    std::list<std::string> list;
    std::string delimiter = " ";
};

#endif // DATA_H
