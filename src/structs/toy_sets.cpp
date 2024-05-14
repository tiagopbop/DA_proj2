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
            toy_set.addEdge(stoi(origem),stoi(destino),stod(distancia));
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
            toy_set.addEdge(stoi(origem),stoi(destino),stod(distancia));
        }
    }
}



void Toyset::backtrack_tsp(vector<int>& current_path, unordered_set<int>& visited, vector<int>& best_path, double& best_cost, int current) {
    if (visited.size() > toy_set.getVertexSet().size()-1) {
        int current_cost = 0;
        for (int i = 0; i < toy_set.getNumVertex() - 1; ++i) {
            int u = current_path[i];
            int v = current_path[i + 1];
            for (auto vertex : toy_set.getVertexSet())
                for (auto& edge : vertex->getAdj()) {
                    if ((edge->getOrig()->getInfo() == u && edge->getDest()->getInfo() == v) || (edge->getOrig()->getInfo() == v && edge->getDest()->getInfo() == u)) {
                        current_cost += edge->getWeight();
                        break;
                    }
                }
        }

        // Calculate cost for the last edge
        int u = current_path[toy_set.getNumVertex() - 1];
        int v = 0; // Starting vertex
        for (auto ed : toy_set.getVertexSet().front()->getAdj()) {
            if ((ed->getOrig()->getInfo() == u && ed->getDest()->getInfo() == v) || (ed->getOrig()->getInfo() == v && ed->getDest()->getInfo() == u)) {
                current_cost += ed->getWeight();
                break;
            }
        }

        if (current_cost < best_cost) {
            best_cost = current_cost;
            best_path = current_path;
        }
        return;
    }

    for (auto& vertex : toy_set.getVertexSet()) {
        for (auto& edge : vertex->getAdj())
            if (edge->getOrig()->getInfo() == current && visited.find(edge->getDest()->getInfo()) == visited.end()) {
                current_path.push_back(edge->getDest()->getInfo());
                visited.insert(edge->getDest()->getInfo());
                backtrack_tsp(current_path, visited, best_path, best_cost, edge->getDest()->getInfo());

                current_path.pop_back();
                visited.erase(edge->getDest()->getInfo());
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

    backtrack_tsp(current_path, visited, best_path, best_cost, 0);

    // Output the best path and its cost
    cout << "Best Path: ";
    for (int node : best_path) {
        cout << node << " ";
    }
    cout << "0" << endl; // Return to the starting node
    cout << "Cost: " << best_cost << endl;
}

