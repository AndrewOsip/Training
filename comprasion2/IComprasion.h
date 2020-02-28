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
    virtual void vocebWrite() = 0;
    virtual void numOfCoinc() = 0;

    class Text
    {
    public:
        Text();
        void textTransform();

        const std::vector<std::string>& getText() const { return mTextVector; }
    private:
        std::string mText;
        std::vector<std::string> mTextVector;
    };
};

#endif // TEXT_H
