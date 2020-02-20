#ifndef IDATA_H
#define IDATA_H

class IData
{
public:
    virtual ~IData() = default;
    virtual void parser() = 0;
};

#endif // IDATA_H
