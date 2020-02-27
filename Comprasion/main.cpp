#include "Tree.h"
#include "Vector.h"
#include "Hash.h"


#include <fstream>
#include <string>
#include <string.h>

int main()
{
    IComprasion::Text text;

    Vector vector;
    vector.vocebWrite();

    Tree tree;
        std::string line;

        std::string vocebPath = "../texts/dictionary.txt";

        std::ifstream in;
        if (in.is_open())
        {
            while (getline(in, line))
            {
                char* tab2;
                strcpy(tab2, line.c_str());
                tree.insertNewValue(*tab2);
            }
        }
        in.close();
    }

    
    


    return 0;
}

