//
// Created by loading on 12-05-2024.
//

#include <fstream>
#include <sstream>
#include <string>
#include "Realworld.h"
#include <math.h>
#include <time.h>


const double R = 6371.0;

double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}
bool HashNodes:: check_if(int id1, int id2, HashNodes hashNodes,Realworld realworld)
{
    const auto *it1 = realworld.realworld.findVertex(id1) ;
    const auto *it2 = realworld.realworld.findVertex(id2) ;
    for(auto a:it1->getAdj())
    {
        if(a->getDest()->getInfo()==it2->getInfo()) return true;
    }


    return false;
}
void HashNodes::Graph_ReadLines(int decision, HashNodes hashNodes, Realworld realworld) {

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

        realworld.realworld.addBidirectionalEdge(stoi(origem),stoi(destino),stof(distancia));
    }

    for (const auto& a : realworld.realworld.getVertexSet()) {

        for (const auto& b : realworld.realworld.getVertexSet()) {
            if (a->getInfo() != b->getInfo()) {

                int id1 = a->getInfo();
                int id2 = b->getInfo();

                bool edgeExists = check_if(id1,id2, hashNodes,realworld);

                if (!edgeExists) {

                    const Nodes* nodeA = hashNodes.findNode(id1);
                    const Nodes* nodeB = hashNodes.findNode(id2);

                    if (nodeA && nodeB) {

                        double distance = haversine(nodeA->get_lat(), nodeA->get_lon(), nodeB->get_lat(), nodeB->get_lon());
                        realworld.realworld.addBidirectionalEdge(id1, id2, distance);
                    }
                }
            }
        }
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



