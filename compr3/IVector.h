#ifndef IFILEWRAPER_H
#define IFILEWRAPER_H

#include <string>
#include <vector>

class IVector {
public:
    virtual const std::vector<std::string>& provideData() const = 0;
    virtual ~IVector() = default;
};

#endif // IFILEWRAPER_H
