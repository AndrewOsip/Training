#include <fstream>
#include <algorithm>

#include "IComprasion.h"

IComprasion::Text::Text()
{
    textTransform();
}

void IComprasion::Text::textTransform()
{
    std::ifstream in;
    in.open("../texts/texts.txt");
    getline(in,  mText, '\0');
    in.close();

      mText.erase(std::remove(  mText.begin(),   mText.end(), ','),   mText.end());
      mText.erase(std::remove(  mText.begin(),   mText.end(), '.'),   mText.end());
      mText.erase(std::remove(  mText.begin(),   mText.end(), '-'),   mText.end());
      mText.erase(std::remove(  mText.begin(),   mText.end(), '"'),   mText.end());
      mText.erase(std::remove(  mText.begin(),   mText.end(), '!'),   mText.end());
      mText.erase(std::remove(  mText.begin(),   mText.end(), '\r'),   mText.end());
      mText.erase(std::remove(  mText.begin(),   mText.end(), '\n'),   mText.end());
      mText.erase(std::remove(  mText.begin(),   mText.end(), '1'),   mText.end());
    //  mText.erase(std::remove(  mText.begin(),   mText.end(), PUNCT),   mText.end());

    std::transform(  mText.begin(),   mText.end(),   mText.begin(), tolower);

    size_t pos =   mText.find(DELIMETER);
    size_t initialPos = 0;

    while(pos != std::string::npos) {
          mTextVector.push_back(  mText.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;
        pos =   mText.find(DELIMETER, initialPos);
    }
      mTextVector.push_back(  mText.substr(initialPos, std::min(pos,   mText.size()) - initialPos + 1));
}
