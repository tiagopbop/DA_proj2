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
    menu::Terminal();

   /* Toyset toy_set;
    toy_set.ReadLines(4);
    for(auto a: toy_set.toy_set.getVertexSet()) {

        for(auto b: a->getAdj())
        {
            //cout << a->getInfo() << "   " << b->getDest()->getInfo() << "   " << b->getWeight()<< endl;

        }


    }/*
  Realworld realworld;
    realworld.realworld= toy_set.toy_set;
  //HashNodes hashNodes;
  //hashNodes.Nodes_ReadLines(realworld,1);
  //hashNodes.Graph_ReadLines(1,hashNodes,realworld);

  /* int count = 0;
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
  /*  double init_time = ( ( (double) clock() ) / CLOCKS_PER_SEC);
    int startNode = 0; // Change this to specify the starting node
    std::vector<int> tour = realworld.solveTSP(realworld, startNode);

    // Print the tour
       double time =  ( ( (double) clock() ) / CLOCKS_PER_SEC) - init_time;
    printf("The elapsed time was %f seconds\n", time);

    for(auto a:toy_set.toy_set.getVertexSet())
   {
        a->setVisited(false);
    }*/
    //RESPOSTA 4.1
/*
     Vertex<int>* a = *toy_set.toy_set.getVertexSet().begin();
     a->setVisited(true);
    Vertex<int>* b = *realworld.realworld.getVertexSet().begin();
    b->setVisited(true);
  //  double init_time = ( ( (double) clock() ) / CLOCKS_PER_SEC);
   // toy_set.backtrack(toy_set.toy_set);
   // double time =  ( ( (double) clock() ) / CLOCKS_PER_SEC) - init_time;
    //printf("The elapsed time was %f seconds\n", time);
    //return  0;
*/
    /*
    pair<vector<int>, double> tour = toy_set.triangularApproximation(toy_set.toy_set);

    cout << "Tour: ";
    for (const int& city : tour.first) {
        cout << city << " ";
    }
    cout << endl;
    cout<<"Distance = "<<tour.second<<endl;
*/
 /*   int start = 0;
    pair<vector<int>, double> tour = toy_set.nearestNeighborTSP(toy_set.toy_set, start);

    cout << "Tour: ";
    for (int city : tour.first) {
        cout << city << " ";
    }
    cout << endl;
    cout<<"Distance = "<<tour.second<<endl;
*/

    return 0;
}