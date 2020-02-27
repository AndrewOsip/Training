#ifndef TEXT_H
#define TEXT_H
#include <string>
#include <vector>

namespace {
    const std::string DELIMETER{" "};
}

class IComprasion
{
public:
    virtual ~IComprasion() = default;

    class Text
    {
    public:
        Text();
        void textTransform();

    private:
        std::string mText;
        std::vector<std::string> mTextVector;
    };
};

#endif // TEXT_H
