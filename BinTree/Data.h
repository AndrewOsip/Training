#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <iostream>
#include <list>

class Data
{
public:
    static std::list<std::string> parser(Data& data)
    {
        while (data.inputData != "0")
        {
            std::cout << "Plese enter your value: ";
            getline(std::cin, data.inputData);
            size_t pos = data.inputData.find(data.delimiter);
            size_t initialPos = 0;
                while(pos != std::string::npos)
                {
                    data.list.push_back(data.inputData.substr(initialPos, pos - initialPos));
                    initialPos = pos + 1;
                    pos = data.inputData.find(data.delimiter, initialPos);
                }
                data.list.push_back(data.inputData.substr(initialPos, std::min(pos, data.inputData.size()) - initialPos + 1));
        }

        return data.list;
    }

    std::string inputData;
    std::list<std::string> list;
    std::string delimiter = " ";
};

#endif // DATA_H
