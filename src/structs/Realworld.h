//
// Created by loading on 12-05-2024.
//

#include <unordered_set>
#include "Graph.h"
using namespace std;

#ifndef DA_PROJ2_REALWORLD_H
#define DA_PROJ2_REALWORLD_H


class Realworld {
public:
    vector<int> tour;

    Graph<int> realworld;









    void printTour(const vector<int> &path) const;


    void solveTSP(int origin);

    void
    backtrack(int currentNode, vector<int> &tour, vector<bool> &visited, int numVisited, int totalCost, int optimalCost,
              vector<int> &optimalPath);

    vector<pair<int, int>> primMST(int start);

    vector<int> findHamiltonianCycle(const Realworld &realworld, const vector<std::pair<int, int>> &mst,
                                     const vector<std::pair<int, int>> &matching, int start);

    vector<pair<int, int>> findMinimumMatching(const Realworld &realworld, const vector<int> &oddVertices);

    vector<int> solveTSP(const Realworld &realworld, int start);

    vector<pair<int, int>> primMST(const Realworld &realworld, int start);
};


class Nodes{
    public:
        int id;
        float lon;
        float lat;


        Nodes(int id, float lon, float lat);
        int get_id() const;
        float get_lon() const;
        float get_lat() const;

};

struct NodesHash{
    int operator() (const Nodes& b) const {
        const int id = b.get_id();
        unsigned int hash = 5381;

        hash = 33 * hash + id;

        return hash % 3019;
    }

    bool operator()(const Nodes &b1, const Nodes &b2) const {
        return b1.get_id() == b2.get_id();
    }

};

typedef unordered_set<Nodes, NodesHash,NodesHash> NodesTable;
class HashNodes{
public:
    NodesTable nodesTable;
    static void Nodes_ReadLines(Realworld& realworld, int decision);
    void Graph_ReadLines(int decision, HashNodes hashnodes, Realworld realworld);
    bool check_if(int id1, int id2,HashNodes hashNodes, Realworld realworld);

    const Nodes* findNode(const int& code) const{
        Nodes dummy(code,1,1);
        auto it = nodesTable.find(dummy);
        if(it !=nodesTable.end())
        {
            return&(*it);
        }
        return nullptr;

    }

};


#endif //DA_PROJ2_REALWORLD_H
