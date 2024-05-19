//
// Created by loading on 12-05-2024.
//

#include "toy_sets.h"
//
// Created by loading on 12-05-2024.
//



#include <fstream>
#include <sstream>
#include <string>
#include "toy_sets.h"
#include <vector>
#include <unordered_set>


using namespace std;
void Toyset::ReadLines(int decision) {

    string input;
    switch(decision)
    {
        case 1:
            input = "../data/toygraphs/shipping.csv";
            break;
        case 2:
            input = "../data/toygraphs/stadiums.csv";
            break;

        case 3:
            input = "../data/toygraphs/tourism.csv";
            break;

        default: return;
    }


    ifstream MyReadFile(input);

    string line;

    getline(MyReadFile, line);

    if(decision == 3){

        while (std::getline(MyReadFile, line)) {
            stringstream ss(line);

            string origem;
            string destino;
            string distancia;
            string origem_nome;
            string destino_nome;
            getline(ss, origem, ',');
            getline(ss, destino, ',');
            getline(ss, distancia, ',');
            getline(ss, origem_nome, ',');
            getline(ss, destino_nome, ',');

            toy_set.addVertex(stoi(origem));
            toy_set.addVertex(stoi(destino));
            toy_set.addBidirectionalEdge(stoi(origem),stoi(destino),stod(distancia));
        }
    }
    else{
        while (std::getline(MyReadFile, line)) {
            stringstream ss(line);

            string origem;
            string destino;
            string distancia;

            getline(ss, origem, ',');
            getline(ss, destino, ',');
            getline(ss, distancia, ',');



            toy_set.addVertex(stoi(origem));
            toy_set.addVertex(stoi(destino));
            toy_set.addBidirectionalEdge(stoi(origem),stoi(destino),stod(distancia));
        }
    }
}

vector<vector<double>> Toyset::computeEdgeWeights(const Graph<int>& graph) {
    int n = graph.getNumVertex();
    vector<vector<double>> edge_weights(n, vector<double>(n, INF));

    for (auto& vertex : graph.getVertexSet()) {
        int u = vertex->getInfo();
        for (auto& edge : vertex->getAdj()) {
            int v = edge->getDest()->getInfo();
            edge_weights[u][v] = edge->getWeight();
        }
    }

    return edge_weights;
}

void Toyset::backtrack_tsp(vector<int>& current_path, double current_cost, unordered_set<int>& visited, vector<int>& best_path, double& best_cost, int current, const vector<vector<double>>& edge_weights) {
    if (visited.size() == toy_set.getNumVertex()) {
        if (edge_weights[current][0] < INF) {
            current_cost += edge_weights[current][0]; // Add cost to return to start
            if (current_cost < best_cost) {
                best_cost = current_cost;
                best_path = current_path;
            }
        }
        return;
    }

    for (int next = 0; next < toy_set.getNumVertex(); ++next) {
        if (visited.find(next) == visited.end() && edge_weights[current][next] < INF) {
            visited.insert(next);
            current_path.push_back(next);

            // Pruning: Skip further exploration if current cost exceeds best cost
            if (current_cost + edge_weights[current][next] < best_cost) {
                backtrack_tsp(current_path, current_cost + edge_weights[current][next], visited, best_path, best_cost, next, edge_weights);
            }

            current_path.pop_back();
            visited.erase(next);
        }
    }
}

// Function to solve TSP using backtracking algorithm
void Toyset::backtrack(Graph<int>& graph) {
    vector<int> current_path;
    vector<int> best_path;
    double best_cost = INF;

    current_path.push_back(0); // Start from node 0

    unordered_set<int> visited;
    visited.insert(0);
    double current_cost = 0;

    // Precompute edge weights
    vector<vector<double>> edge_weights = computeEdgeWeights(graph);

    backtrack_tsp(current_path, current_cost, visited, best_path, best_cost, 0, edge_weights);

    // Output the best path and its cost
    cout << "Best Path: ";
    for (int node : best_path) {
        cout << node << " ";
    }
    cout << "0" << endl; // Return to the starting node
    cout << "Cost: " << best_cost << endl;
}


pair<vector<int>, double> Toyset::triangularApproximation(Graph<int>& graph) {
    pair<vector<int>, double> tour;
    vector<Vertex<int>*> visit_order = toy_set.prim();
    tour.first.push_back(visit_order[0]->getInfo());
    for(auto i = 1; i < visit_order.size(); i++){
        tour.first.push_back(visit_order[i]->getInfo());
        for(auto e : visit_order[i]->getAdj()){
            if(e->getDest()->getInfo() == visit_order[i - 1]->getInfo()){
                tour.second = tour.second + e->getWeight();
            }
        }
    }
    for(auto e : visit_order[0]->getAdj()){
        if(e->getDest()->getInfo() == tour.first.back()){
            tour.second = tour.second + e->getWeight();
        }
    }
    tour.first.push_back(visit_order[0]->getInfo());


    return tour;
}


pair<vector<int>, double> Toyset::nearestNeighborTSP(Graph<int>& graph, int start) {
    vector<int> tour;
    double totalDistance = 0;
    int current = start;
    Vertex<int>* current_vertex = graph.findVertex(current);
    current_vertex->setVisited(true);
    tour.push_back(current);

    while (tour.size() < graph.getNumVertex()) {
        Vertex<int>* currentVertex = graph.findVertex(current);
        double minDistance = numeric_limits<double>::infinity();
        int nextCity = -1;

        for (auto edge : currentVertex->getAdj()) {
            Vertex<int>* neighbor = graph.findVertex(edge->getDest()->getInfo());
            if (!neighbor->isVisited() && edge->getWeight() < minDistance) {
                minDistance = edge->getWeight();
                nextCity = edge->getDest()->getInfo();
            }
        }

        if (nextCity == -1) break; // No unvisited neighbor found (shouldn't happen in a fully connected graph)

        tour.push_back(nextCity);
        totalDistance += minDistance;
        Vertex<int>* nextcity_vertex = graph.findVertex(nextCity);
        nextcity_vertex->setVisited(true);
        current = nextCity;
    }

    // Return to the starting point to complete the tour
    Vertex<int>* lastVertex = graph.findVertex(current);
    for (auto edge : lastVertex->getAdj()) {
        if (edge->getDest()->getInfo() == start) {
            totalDistance += edge->getWeight();
            tour.push_back(start);
            break;
        }
    }

    return make_pair(tour, totalDistance);
}


