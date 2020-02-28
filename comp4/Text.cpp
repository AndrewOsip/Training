#include <fstream>
#include <algorithm>
#include <iostream>

#include "Text.h"

bool ispunctuation(char ch) {
   if(ch == '.' || ch == ',' || ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '^' || ch == '&'
                || ch == '*' || ch == '(' || ch == ')' || ch == '-' || ch == '_' || ch == '=' || ch == '+' || ch == '/'
                || ch == '{' || ch == '}' || ch == '~' || ch == ':' || ch == ';' || ch == '"' )
      return true;
   else
      return false;
}

void Text::textTransform() {

    std::ifstream in;
    in.open("../Comprasion/texts.txt");
    getline(in,  mText, '\0');

        for (uint i = 0, len = mText.size(); i < len; i++)
        {
            if (ispunctuation(mText[i]))
            {
                mText.erase(i--, 1);
                len = mText.size();
            }
        }

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
