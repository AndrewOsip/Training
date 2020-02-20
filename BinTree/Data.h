#ifndef DATA_H
#define DATA_H

#include <IData.h>

class Data : public IData
{
public:
    Data() {
        inputPrint();
    }
    void parser() override;
    void inputPrint() override;

private:
    std::string mInputData;
    std::list<std::string> mList;
    std::string mDelimiter = " ";
};

#endif // DATA_H
