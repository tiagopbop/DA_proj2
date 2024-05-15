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



void Toyset::backtrack_tsp(vector<int>& current_path,double current_cost, unordered_set<int>& visited, vector<int>& best_path, double& best_cost, int current) {

    if (visited.size() == toy_set.getNumVertex()) {
        bool possible = false;
        for (auto& edge : toy_set.getVertexSet().front()->getAdj()) {
            if (edge->getDest()->getInfo() == current_path.back()) {
                current_cost += edge->getWeight();
                possible = true;
                break;
            }
        }

        if (current_cost < best_cost && possible) {
            best_cost = current_cost;
            best_path= current_path;
        }
        return;
    }

    for (auto& vertex : toy_set.getVertexSet()) {
        for (auto& edge : vertex->getAdj())
            if (edge->getOrig()->getInfo() == current && visited.find(edge->getDest()->getInfo()) == visited.end()) {
                current_path.push_back(edge->getDest()->getInfo());
                visited.insert(edge->getDest()->getInfo());

                backtrack_tsp(current_path,current_cost+edge->getWeight(), visited, best_path, best_cost, edge->getDest()->getInfo());

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
    double current_cost = 0;
    backtrack_tsp(current_path,current_cost, visited, best_path, best_cost, 0);

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