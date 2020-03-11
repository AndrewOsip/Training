#ifndef TEXT_H
#define TEXT_H

#include <vector>
#include <string>
#include <fstream>

namespace {
    const std::string DELIMETER{" "};
}

class Text
    {
    public:
        Text()
        {
            mFileName.open(pathText);
            textTransform();
        }

        ~Text() { mFileName.close(); }

        const std::vector<std::string>& getText() const { return mTextVector; }
    private:
        void textTransform();
        std::string mText;
        std::vector<std::string> mTextVector;
        std::ifstream mFileName;
        std::string pathText = "../Comprasion/texts.txt";
    };

#endif // TEXT_H
