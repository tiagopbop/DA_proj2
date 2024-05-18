//
// Created by loading on 12-05-2024.
//

#include "menu.h"
#include "structs/toy_sets.h"
#include "structs/Graph.h"
#include "structs/Realworld.h"

using namespace std;

int main()
{
    Toyset toy_set;
    toy_set.ReadLines(2);
    for(auto a: toy_set.toy_set.getVertexSet()) {

        for(auto b: a->getAdj())
        {
            //cout << a->getInfo() << "   " << b->getDest()->getInfo() << "   " << b->getWeight()<< endl;

        }


    }
 /*  Realworld realworld;
   HashNodes hashNodes;
   hashNodes.Nodes_ReadLines(realworld,1);
   realworld.Graph_ReadLines(1);
   int count = 0;
   for(auto  a:realworld.realworld.getVertexSet())
   {
       for(auto b: a->getAdj())
       {
           count++;
           cout << a->getInfo() << "   " << b->getDest()->getInfo() << "   " << b->getWeight()<< endl;
           if(count == 10) return 0;
       }
   }

*/

    for(auto a:toy_set.toy_set.getVertexSet())
    {
        a->setVisited(false);
    }
    //RESPOSTA 4.1

     //Vertex<int>* a = *toy_set.toy_set.getVertexSet().begin();
     //a->setVisited(true);


    //toy_set.backtrack(toy_set.toy_set);
    //return  0;


    pair<vector<int>, double> tour = toy_set.triangularApproximation(toy_set.toy_set);

    cout << "Tour: ";
    for (const int& city : tour.first) {
        cout << city << " ";
    }
    cout << endl;
    cout<<"Distance = "<<tour.second<<endl;


    return 0;
}