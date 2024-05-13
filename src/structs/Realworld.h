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
    void Graph_ReadLines(int decision);

    Graph<int> realworld;
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

};


#endif //DA_PROJ2_REALWORLD_H
