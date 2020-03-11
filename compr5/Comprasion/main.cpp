#include <thread>

#include "Vector.h"
#include "HashTable.h"
#include "Umap.h"
#include "Tree.h"

int main()
{
    std::string vocebPath = "../Comprasion/dictionary.txt";

    Vector vector(vocebPath);

    HashTable ht(vocebPath);

    Umap um(vocebPath);

//    Tree tree(vocebPath);






    return 0;
}
