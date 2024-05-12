//
// Created by loading on 12-05-2024.
//

#include "menu.h"
#include "structs/toy_sets.h"
#include "structs/Graph.h"
using namespace std;

int main()
{
    Toyset toy_set;
    toy_set.ReadLines(3);
    for(auto a: toy_set.toy_set.getVertexSet()) {

        for(auto b: a->getAdj())
        {
            cout << a->getInfo() << "   " << b->getDest()->getInfo() << "   " << b->getWeight()<< endl;

        }


    }
    return  0;
}