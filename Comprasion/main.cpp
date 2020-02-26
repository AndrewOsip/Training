#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <functional>
#include <fstream>

namespace {
    const std::string DELIMETER{" "};
    std::list<std::string> PUNCT{{"."},{","},{"-"},{"!"}};
}

class Data
{
public:
    std::vector<std::string> vocebVector;
    std::string text;
    std::vector<std::string> textVector;
};

void textTransform(Data& data)
{
    std::ifstream in;
    in.open("../texts/book.txt");
    getline(in, data.text, '\0');
    in.close();

    data.text.erase(std::remove(data.text.begin(), data.text.end(), ','), data.text.end());
    data.text.erase(std::remove(data.text.begin(), data.text.end(), '.'), data.text.end());
    data.text.erase(std::remove(data.text.begin(), data.text.end(), '-'), data.text.end());
    data.text.erase(std::remove(data.text.begin(), data.text.end(), '"'), data.text.end());
    data.text.erase(std::remove(data.text.begin(), data.text.end(), '!'), data.text.end());
    data.text.erase(std::remove(data.text.begin(), data.text.end(), '\r'), data.text.end());
    data.text.erase(std::remove(data.text.begin(), data.text.end(), '\n'), data.text.end());
    data.text.erase(std::remove(data.text.begin(), data.text.end(), '1'), data.text.end());

    std::transform(data.text.begin(), data.text.end(), data.text.begin(), tolower);

    size_t pos = data.text.find(DELIMETER);
    size_t initialPos = 0;

    while(pos != std::string::npos) {
        data.textVector.push_back(data.text.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;
        pos = data.text.find(DELIMETER, initialPos);
    }
    data.textVector.push_back(data.text.substr(initialPos, std::min(pos, data.text.size()) - initialPos + 1));
}


void vocebWordVector(Data& data)
{
    std::string line;

    std::string vocebPath = "../texts/vocabluary.txt";

    std::ifstream in(vocebPath);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            data.vocebVector.push_back(line);
        }
    }
    in.close();
    std::sort(data.vocebVector.begin(),data.vocebVector.end());
}

int main()
{
    Data data;
    textTransform(data);

    vocebWordVector(data);

    return 0;
}
