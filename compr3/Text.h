#ifndef TEXT_H
#define TEXT_H

#include <vector>
#include <string>

namespace {
    const std::string DELIMETER{" "};
}

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

#endif // TEXT_H
