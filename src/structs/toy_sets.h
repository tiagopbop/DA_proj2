//
// Created by loading on 12-05-2024.
//

#ifndef DA_PROJ2_TOY_SETS_H
#define DA_PROJ2_TOY_SETS_H


#include <unordered_set>
#include "Graph.h"
using namespace std;

class Toyset {
public:
    /**
 * @brief Reads edge data from a CSV file and adds edges to the Toyset graph.
 *
 * This function reads edge data from a CSV file and adds edges to the Toyset graph.
 * The CSV file should contain edge information in the format: source_node, destination_node, weight.
 * The decision parameter determines which CSV file to read based on the specified options.
 *
 * @param decision The decision parameter to choose the CSV file.
 *
 * @note The CSV files should be properly formatted and exist in the specified paths.
 */
    void ReadLines(int decision);

    Graph<int> toy_set;
/**
 * @brief Backtracking algorithm to solve the Traveling Salesman Problem (TSP).
 *
 * This function implements a backtracking algorithm to find the optimal path for the Traveling Salesman Problem (TSP).
 * Given a current partial path, it explores all possible extensions of the path to find the shortest tour that visits
 * all vertices exactly once and returns to the starting vertex.
 *
 * @param current_path The current partial path being explored.
 * @param current_cost The current cost of the partial path.
 * @param visited A set containing the indices of visited vertices.
 * @param best_path The best path found so far.
 * @param best_cost The cost of the best path found so far.
 * @param current The index of the current vertex in the partial path.
 * @param edge_weights A 2D vector representing the edge weights matrix.
 *
 * @note The function updates the best_path and best_cost parameters with the optimal path and its cost.
 *       The toy_set should be properly initialized before calling this function.
 */
    void backtrack_tsp(vector<int>& current_path, double current_cost, unordered_set<int>& visited, vector<int>& best_path, double& best_cost, int current, const vector<vector<double>>& edge_weights);
    /**
    * @brief Computes the edge weights matrix for a given graph.
    *
    * This function computes the edge weights matrix for a given graph.
    * The edge weights matrix contains the weights of the edges between vertices.
    * If there is no edge between two vertices, the weight is set to infinity.
    *
    * @param graph The input graph.
    * @return A 2D vector representing the edge weights matrix.
    *
    * @note The input graph should be properly initialized before calling this function.
    */
    vector<vector<double>> computeEdgeWeights(const Graph<int>& graph);
    /**
 * @brief Solves the Traveling Salesman Problem (TSP) using the backtracking algorithm.
 *
 * This function solves the Traveling Salesman Problem (TSP) using the backtracking algorithm.
 * It starts from node 0 and explores all possible paths to find the shortest tour that visits
 * all vertices exactly once and returns to the starting vertex.
 *
 * @param graph The input graph representing the cities and their distances.
 *
 * @note The toy_set should be properly initialized before calling this function.
 */
    void backtrack(Graph<int>& graph);
    /**
 * @brief Computes an approximate solution to the Traveling Salesman Problem (TSP) using the Triangular Approximation algorithm.
 *
 * This function computes an approximate solution to the Traveling Salesman Problem (TSP) using the Triangular Approximation algorithm.
 * It constructs a tour by selecting vertices in the order obtained from the Prim's algorithm and calculates the total cost of the tour.
 *
 * @param graph The input graph representing the cities and their distances.
 * @return A pair containing the approximate TSP tour represented as a vector of vertex indices and its total cost.
 *
 * @note The toy_set should be properly initialized before calling this function.
 */
    pair<vector<int>, double> triangularApproximation(Graph<int>& graph);
/**
 * @brief Computes an approximate solution to the Traveling Salesman Problem (TSP) using the Nearest Neighbor algorithm.
 *
 * This function computes an approximate solution to the Traveling Salesman Problem (TSP) using the Nearest Neighbor algorithm.
 * It starts from a specified starting vertex and iteratively selects the nearest unvisited neighbor until all vertices are visited,
 * then returns to the starting vertex to complete the tour.
 *
 * @param graph The input graph representing the cities and their distances.
 * @param start The index of the starting vertex for the TSP tour.
 * @return A pair containing the approximate TSP tour represented as a vector of vertex indices and its total distance.
 *
 * @note The toy_set should be properly initialized before calling this function.
 */
    pair<vector<int>, double> nearestNeighborTSP(Graph<int>& graph, int start);
    /**
 * @brief Performs backtracking after applying the 2-opt heuristic to improve the TSP tour.
 *
 * This function performs backtracking after applying the 2-opt heuristic to improve the TSP tour.
 * It iteratively reverses segments of the tour to find a better solution, updating the best path and cost accordingly.
 *
 * @param graph The input graph representing the cities and their distances.
 * @param tour A pair containing the TSP tour represented as a vector of vertex indices and its total distance.
 *
 * @note The toy_set should be properly initialized before calling this function.
 */
    void backtrackafterneareast(Graph<int>& graph, pair<vector<int>, double>& tour);
    /**
 * @brief Solves the Traveling Salesman Problem (TSP) using the Nearest Neighbor algorithm followed by backtracking with 2-opt heuristic.
 *
 * This function solves the Traveling Salesman Problem (TSP) using the Nearest Neighbor algorithm followed by backtracking with 2-opt heuristic.
 * It first computes an approximate solution using the Nearest Neighbor algorithm, then applies the 2-opt heuristic to improve the tour.
 *
 * @param graph The input graph representing the cities and their distances.
 * @return A pair containing the TSP tour represented as a vector of vertex indices and its total distance.
 *
 * @note The toy_set should be properly initialized before calling this function.
 */
    pair<vector<int>, double> TSP(Graph<int> &graph);
};

#endif //DA_PROJ2_TOY_SETS_H
