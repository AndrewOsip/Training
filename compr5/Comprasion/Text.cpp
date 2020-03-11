#include <fstream>
#include <algorithm>
#include <iostream>

#include "Text.h"

bool ispunctuation(char ch) {
   if(ch == '.' || ch == ',' || ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '^' || ch == '&'
                || ch == '*' || ch == '(' || ch == ')' || ch == '-' || ch == '_' || ch == '=' || ch == '+' || ch == '/'
                || ch == '{' || ch == '}' || ch == '~' || ch == ':' || ch == ';' || ch == '"' || ch == '0' || ch == '1'
                || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9'
                || ch == '\\')
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

    std::replace(mText.begin(), mText.end(), '\n', ' ');
    std::transform(mText.begin(),   mText.end(),   mText.begin(), tolower);

    in.close();

    size_t pos = mText.find(DELIMETER);
    size_t initialPos = 0;

    while(pos != std::string::npos) {
        mTextVector.push_back(  mText.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;
        pos = mText.find(DELIMETER, initialPos);
    }

    mTextVector.push_back(  mText.substr(initialPos, std::min(pos,   mText.size()) - initialPos + 1));

    std::sort(mTextVector.begin(),   mTextVector.end());
    mTextVector.erase(std::unique(mTextVector.begin(),   mTextVector.end()),   mTextVector.end());

    std::vector<std::string> q(mTextVector.begin(), mTextVector.begin() + 100);

    int a = 1;
}
