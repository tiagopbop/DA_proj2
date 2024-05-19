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
    /**
 * @brief Reads node data from a CSV file and adds nodes to the Realworld graph.
 *
 * This function reads node data from a CSV file and adds nodes to the Realworld graph.
 * The CSV file should contain node information in the format: node_id, longitude, latitude.
 * The decision parameter determines which CSV file to read based on the specified options.
 *
 * @param realworld An instance of Realworld class where nodes will be added.
 * @param decision The decision parameter to choose the CSV file.
 *
 * @note The CSV files should be properly formatted and exist in the specified paths.
 */
    static void Nodes_ReadLines(Realworld& realworld, int decision);
    /**
 * @brief Reads edge data from a CSV file and adds edges to the Realworld graph.
 *
 * This function reads edge data from a CSV file and adds edges to the Realworld graph.
 * The CSV file should contain edge information in the format: source_node, destination_node, weight.
 * The decision parameter determines which CSV file to read based on the specified options.
 *
 * @param decision The decision parameter to choose the CSV file.
 * @param hashnodes An instance of HashNodes class.
 * @param realworld An instance of Realworld class.
 *
 * @note The CSV files should be properly formatted and exist in the specified paths.
 */
    void Graph_ReadLines(int decision, HashNodes hashnodes, Realworld realworld);
    /**
 * @brief Checks if there exists an edge between two nodes in the Realworld graph.
 *
 * This function checks if there exists an edge between two nodes with given IDs
 * in the Realworld graph. It iterates through the adjacency list of the first node
 * and returns true if it finds an edge leading to the second node, otherwise returns false.
 *
 * @param id1 The ID of the first node.
 * @param id2 The ID of the second node.
 * @param hashNodes An instance of HashNodes class.
 * @param realworld An instance of Realworld class.
 * @return True if there exists an edge between the two nodes, false otherwise.
 *
 * @note Both nodes should exist in the Realworld graph before calling this function.
 */
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
