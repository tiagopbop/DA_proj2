//
// Created by loading on 12-05-2024.
//

#include <fstream>
#include <sstream>
#include <string>
#include "Realworld.h"

void Realworld::Graph_ReadLines(int decision) {

    string input;
    switch(decision)
    {
        case 1:
            input = "../data/realworld/graph1/edges.csv";
            break;
        case 2:
            input = "../data/realworld/graph2/edges.csv";
            break;

        case 3:
            input = "../data/realworld/graph3/edges.csv";
            break;

        default: return;
    }
    ifstream MyReadFile(input);

    string line;

    getline(MyReadFile, line);

    while (std::getline(MyReadFile, line)) {
        stringstream ss(line);

        string origem;
        string destino;
        string distancia;

        getline(ss, origem, ',');
        getline(ss, destino, ',');
        getline(ss, distancia, ',');

        realworld.addEdge(stoi(origem),stoi(destino),stof(distancia));
    }



}

void HashNodes::Nodes_ReadLines(Realworld& realworld, int decision) {
    string input;
    switch(decision)
    {
        case 1:
            input = "../data/realworld/graph1/nodes.csv";
            break;
        case 2:
            input = "../data/realworld/graph2/nodes.csv";
            break;

        case 3:
            input = "../data/realworld/graph3/nodes.csv";
            break;

        default: return;
    }
    ifstream MyReadFile(input);

    string line;

    getline(MyReadFile, line);


    while (std::getline(MyReadFile, line)) {
        stringstream ss(line);

        string id;
        string lon;
        string lat;

        getline(ss, id, ',');
        getline(ss, lon, ',');
        getline(ss, lat, ',');

        Nodes nodes = Nodes(stoi(id),stof(lon),stof(lat));
        realworld.realworld.addVertex(stoi(id));
    }
}

Nodes:: Nodes(int id, float lon, float lat){
    this->id = id;
    this->lon=lon;
    this->lat=lat;
}


int Nodes::get_id() const {
    return this->id;
}


float Nodes::get_lon() const {
    return this->lon;
}


float Nodes::get_lat() const{
    return this->lat;
}