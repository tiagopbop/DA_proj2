#include "menu.h"
#include "structs/Realworld.h"
#include "structs/toy_sets.h"
#include <iostream>

using namespace std;

int menu::Terminal() {
    Realworld realworld;
    Toyset toyset;
    HashNodes hashNodes;

    Vertex<int>* a;
    int st;
    pair<vector<int>, double> tour2;
    std::vector<int> tour;
    double time;
    double init_time;
    int decision;
    int chs_fl;
    string input;

    cout << endl;
    cout << "\033[1;34mWelcome to the Analysis and Synthesis of Algorithms Tool\033[0m" << endl;
    cout << endl;
    cout << "\033[1;33mPlease select the kind of file to be analyzed\033[0m" << endl;
    cout << "\033[1;33m[ 1 ]\033[0m" << " ToySets" << endl;
    cout << "\033[1;33m[ 2 ]\033[0m" << " RealWorld" << endl;
    cout << "\033[1;33m[ 3 ]\033[0m" << " Extra" << endl;

    cout << "\033[0;33mDISCLAIMER : This can be changed later without restarting the program\033[0m" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    cin >> chs_fl;
    cout << endl;

    if (chs_fl == 1) {
        int toy;
        cout << "\033[1;32mToyset chosen successfully\033[0m" << endl;
        cout << "\033[1;33mPlease select the file\033[0m" << endl;
        cout << "\033[1;33m[ 1 ]\033[0m" << " shipping.csv" << endl;
        cout << "\033[1;33m[ 2 ]\033[0m" << " stadiums.csv" << endl;
        cout << "\033[1;33m[ 3 ]\033[0m" << " tourism.csv" << endl;
        cout << endl;
        cout << "\033[1;34mDecision: \033[0m";
        cin>>toy;
        cout<<endl;
        toyset.ReadLines(toy);

    } else if (chs_fl == 2) {
        int real;
        cout << "\033[1;32mRealWorld chosen successfully\033[0m" << endl;
        cout << "\033[1;33mPlease select the file\033[0m" << endl;
        cout << "\033[1;33m[ 1 ]\033[0m" << " graph1" << endl;
        cout << "\033[1;33m[ 2 ]\033[0m" << " graph2" << endl;
        cout << "\033[1;33m[ 3 ]\033[0m" << " graph3" << endl;
        cout << endl;
        cout << "\033[1;34mDecision: \033[0m";
        cin >> real;
        cout << endl;
        hashNodes.Nodes_ReadLines(realworld, real);
        hashNodes.Graph_ReadLines(real, hashNodes, realworld);
    }
     else if(chs_fl==3){

        int extra;
        cout << "\033[1;32mRealWorld chosen successfully\033[0m" << endl;
        cout << "\033[1;33mPlease select the file\033[0m" << endl;
        cout << "\033[1;33m[ 1 ]\033[0m" << " 25edges" << endl;
        cout << "\033[1;33m[ 2 ]\033[0m" << " 400edges" << endl;
        cout << "\033[1;33m[ 3 ]\033[0m" << " 900edges" << endl;
        cout << endl;
        cout << "\033[1;34mDecision: \033[0m";
        cin >> extra;
        cout << endl;
        hashNodes.Nodes_ReadLines(realworld, extra+3);
        hashNodes.Graph_ReadLines(extra+3, hashNodes, realworld);
    }
    else {
        cout << "\033[1;33mUnrecognized answer - Proceeding with Toyset\033[0m" << endl;
        cout << endl;
        int toy;
        cout << "\033[1;32mToyset chosen successfully\033[0m" << endl;
        cout << "\033[1;33mPlease select the file\033[0m" << endl;
        cout << "\033[1;33m[ 1 ]\033[0m" << " shipping.csv" << endl;
        cout << "\033[1;33m[ 2 ]\033[0m" << " stadiums.csv" << endl;
        cout << "\033[1;33m[ 3 ]\033[0m" << " tourism.csv" << endl;
        cout << endl;
        cout << "\033[1;34mDecision: \033[0m";
        cin>>toy;
        cout<<endl;
        toyset.ReadLines(toy);
    }


    cout << endl << endl;
    cout << "\033[1;34mWhat do you wish to do?\033[0m" << endl;

    cout << "\033[1;36m[ 1 ]\033[0m" << " Use the Backtracking Algorithm" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Use the Triangular Approximation Heuristic" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Use other Heuristics" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Use TSP in the real world" << endl;
    cout << "\033[1;33m[ 9 ] Change the input data being analyzed\033[0m" << endl;
    cout << "\033[1;31m[ 0 ] Quit\033[0m" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    cin >> decision;
    cout << endl << endl;

    while (decision != 0) {
        switch (decision) {
            case 1:
                if(chs_fl!=1)
                {
                    toyset.toy_set=realworld.realworld;
                }
                for(auto a:toyset.toy_set.getVertexSet())
                {
                    a->setVisited(false);
                }
                cout << endl << endl;

                init_time = ( ( (double) clock() ) / CLOCKS_PER_SEC);
                a = *toyset.toy_set.getVertexSet().begin();
                a->setVisited(true);
                toyset.backtrack(toyset.toy_set);
                cout << "Tour: ";
                for (const int& city : tour) {
                    cout << city << " ";
                }


                time =  ( ( (double) clock() ) / CLOCKS_PER_SEC) - init_time;
                cout << "The elapsed time was %f seconds" << time << endl;


                break;
      case 2:
          if(chs_fl!=1)
          {
              toyset.toy_set=realworld.realworld;
          }
                init_time = ( ( (double) clock() ) / CLOCKS_PER_SEC);

                tour2 = toyset.triangularApproximation(toyset.toy_set);
                time =  ( ( (double) clock() ) / CLOCKS_PER_SEC) - init_time;

                cout << "Tour: ";
                for (const int& city : tour2.first) {
                    cout << city << " ";
                }
                cout << endl;
                cout<<"Distance = "<<tour2.second<<endl;
                cout << "The elapsed time was %f seconds" << time << endl;


          break;
      case 3:

          if(chs_fl!=1)
          {
              toyset.toy_set=realworld.realworld;
          }
                cout << endl << endl;
                cout<<toyset.toy_set.getNumVertex();
                cout << "\033[1;34mSelect strating node?\033[0m" << endl;
                cout << "\033[1;34mDecision: \033[0m";


                cin >> st;
                init_time = ( ( (double) clock() ) / CLOCKS_PER_SEC);

                tour2 = toyset.nearestNeighborTSP(toyset.toy_set,st);
                time =  ( ( (double) clock() ) / CLOCKS_PER_SEC) - init_time;

                cout << "Tour: ";
                for (const int& city : tour2.first) {
                    cout << city << " ";
                }
                cout << endl;
                cout<<"Distance = "<<tour2.second<<endl;
                cout << "The elapsed time was %f seconds" << time << endl;


          break;
      case 4:
          if(chs_fl!=1)
          {
              toyset.toy_set=realworld.realworld;
          }

                cin >> st;
                init_time = ( ( (double) clock() ) / CLOCKS_PER_SEC);

                tour2 = toyset.TSP(toyset.toy_set);
                time =  ( ( (double) clock() ) / CLOCKS_PER_SEC) - init_time;

                cout << "Tour: ";
                for (const int& city : tour2.first) {
                    cout << city << " ";
                }
                cout << endl;
                cout<<"Distance = "<<tour2.second<<endl;
                cout << "The elapsed time was %f seconds" << time << endl;


          break;
      case 9:
          int select_file;
          if (chs_fl == 1) {
              cout << "\033[1;34mDecision: \033[0m";
              cin >> select_file;
              if (select_file == 1) {
                  cout << "\033[1;32mRealWorld chosen successfully\033[0m" << endl;
                  chs_fl = 2;
              }
              else{
                  cout << "\033[1;32mExtra chosen successfully\033[0m" << endl;
                  chs_fl = 3;
              }

          }
          else if(chs_fl==2) {
              cout << "\033[1;34mDecision: \033[0m";
              cin >> select_file;
              if (select_file == 1) {
                  cout << "\033[1;32mToyset chosen successfully\033[0m" << endl;
                  chs_fl = 1;
              }
              else{
                  cout << "\033[1;32mExtra chosen successfully\033[0m" << endl;
                  chs_fl = 3;
              }
          }
          else{
              cout << "\033[1;34mDecision: \033[0m";
              cin >> select_file;
              if (select_file == 1) {
                  cout << "\033[1;32mToyset chosen successfully\033[0m" << endl;
                  chs_fl = 1;
              }
              else{
                  cout << "\033[1;32mRealworld chosen successfully\033[0m" << endl;
                  chs_fl = 2;
              }
          }



          break;
      case 0:

          break;
      default:

          cout << "\033[1;31mInput error - Going back\033[0m" << endl << endl;
          decision = 1;

          break;
  }

  if (decision != 0) {

      cout << "\033[1;34mWish to do anything else?\033[0m" << endl;

      cout << "\033[1;36m[ 1 ]\033[0m" << " Use the Backtracking Algorithm" << endl;
      cout << "\033[1;36m[ 2 ]\033[0m" << " Use the Triangular Approximation Heuristic" << endl;
      cout << "\033[1;36m[ 3 ]\033[0m" << " Use other Heuristics" << endl;
      cout << "\033[1;36m[ 4 ]\033[0m" << " Use TSP in the real world" << endl;
      cout << "\033[1;33m[ 9 ] Change the input data being analyzed\033[0m" << endl;
      cout << "\033[1;31m[ 0 ] Quit\033[0m" << endl;
      cout << endl;

      cout << "\033[1;34mDecision: \033[0m";
      cin >> decision;
      cout << endl << endl;

  }

}

return 0;
}