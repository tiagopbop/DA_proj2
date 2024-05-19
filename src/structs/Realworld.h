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

/**
 * @brief Finds a minimum weight perfect matching for the given set of odd degree vertices.
 *
 * This function computes the minimum weight perfect matching for a given set of odd degree vertices
 * using a greedy approach to select the minimum weight edges.
 *
 * @param realworld The input graph representing the cities and their distances.
 * @param oddVertices A vector of vertices with odd degree in the minimum spanning tree.
 * @return A vector of pairs representing the edges in the minimum weight perfect matching.
 *
 * @note The input graph should be properly initialized before calling this function.
 * @note Time Complexity: O(V^3)
 */
    vector<pair<int, int>> findMinimumMatching(const Realworld &realworld, const vector<int> &oddVertices);

/**
 * @brief Finds a Hamiltonian cycle using the minimum spanning tree and minimum weight perfect matching.
 *
 * This function constructs a Hamiltonian cycle by combining the minimum spanning tree (MST) and
 * the minimum weight perfect matching of the odd degree vertices in the MST.
 *
 * @param realworld The input graph representing the cities and their distances.
 * @param mst The minimum spanning tree of the graph.
 * @param matching The minimum weight perfect matching of the odd degree vertices in the MST.
 * @param start The starting vertex for the Hamiltonian cycle.
 * @return A vector representing the Hamiltonian cycle as a sequence of vertex indices.
 *
 * @note The input graph should be properly initialized before calling this function.
 * @note Time Complexity: O(V^2)
 */
    vector<int> findHamiltonianCycle(const Realworld &realworld, const vector<std::pair<int, int>> &mst,
                                     const vector<std::pair<int, int>> &matching, int start);

/**
 * @brief Solves the Traveling Salesman Problem (TSP) using the Christofides algorithm.
 *
 * This function solves the Traveling Salesman Problem (TSP) using the Christofides algorithm, which
 * involves constructing a minimum spanning tree (MST), finding a minimum weight perfect matching of
 * the odd degree vertices in the MST, and combining them to form a Hamiltonian cycle.
 *
 * @param realworld The input graph representing the cities and their distances.
 * @param start The starting vertex for the TSP tour.
 * @return A vector representing the TSP tour as a sequence of vertex indices.
 *
 * @note The input graph should be properly initialized before calling this function.
 * @note Time Complexity: O(V^3)
 */
    vector<int> solveTSP(const Realworld &realworld, int start);
/**
 * @brief Finds the minimum spanning tree (MST) of the Realworld graph using Prim's algorithm.
 *
 * Prim's algorithm is used to find the minimum spanning tree (MST) of a weighted graph.
 * This function takes a Realworld graph and a starting vertex and returns the edges
 * of the MST as a vector of pairs of vertex indices.
 *
 * @param realworld The Realworld graph.
 * @param start The index of the starting vertex for MST construction.
 * @return A vector of pairs representing the edges of the minimum spanning tree.
 *
 * @note The Realworld graph should be properly initialized before calling this function.
 * Time Complexity: O((V + E) log V)
 * @see https://en.wikipedia.org/wiki/Prim%27s_algorithm
 */
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
