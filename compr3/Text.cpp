#include <fstream>
#include <algorithm>

#include "Text.h"

Text::Text()
{
    textTransform();
}

void Text::textTransform()
{
    std::ifstream in;
    in.open("../Comprasion/texts.txt");
    getline(in,  mText, '\0');

    mText.erase(std::remove(  mText.begin(),   mText.end(), '.'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), ','),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '.'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '-'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '"'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '!'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '\r'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '\n'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '1'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '#'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '2'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '3'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '4'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '5'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '6'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '7'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '8'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '9'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '['),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), ']'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '&'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '*'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '+'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '-'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '/'),   mText.end());
    mText.erase(std::remove(  mText.begin(),   mText.end(), '^'),   mText.end());


    std::transform(  mText.begin(),   mText.end(),   mText.begin(), tolower);
    mText.erase(std::unique(mText.begin(),   mText.end()),   mText.end());



    in.close();

    size_t pos =   mText.find(DELIMETER);
    size_t initialPos = 0;

    while(pos != std::string::npos) {
          mTextVector.push_back(  mText.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;
        pos =   mText.find(DELIMETER, initialPos);
    }
      mTextVector.push_back(  mText.substr(initialPos, std::min(pos,   mText.size()) - initialPos + 1));
}
