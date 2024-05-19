#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_set>
#include "Realworld.h"

const double R = 6371.0;
/**
 * @brief Calculates the great-circle distance between two points using the Haversine formula.
 *
 * The Haversine formula determines the shortest distance over the earth's surface
 * between two points given their latitudes and longitudes. This function takes the
 * latitude and longitude of two points in degrees and returns the distance between
 * them in the same unit as the radius (R) used.
 *
 * @param lat1 Latitude of the first point in degrees.
 * @param lon1 Longitude of the first point in degrees.
 * @param lat2 Latitude of the second point in degrees.
 * @param lon2 Longitude of the second point in degrees.
 * @return The distance between the two points in the same unit as the radius (R).
 *
 * @note The Earth's radius (R) should be defined before calling this function.
 * @see https://en.wikipedia.org/wiki/Haversine_formula
 */
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
 * @see https://en.wikipedia.org/wiki/Prim%27s_algorithm
 */
std::vector<std::pair<int, int>> Realworld::primMST(const Realworld& realworld, int start) {
    int n = realworld.realworld.getNumVertex();
    std::vector<bool> visited(n, false);
    std::vector<std::pair<int, int>> mst;
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;

    pq.push(std::make_pair(0.0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (auto neighbor : realworld.realworld.findVertex(u)->getAdj()) {
            int v = neighbor->getDest()->getInfo();
            double weight = neighbor->getWeight();

            if (!visited[v])
                pq.push(std::make_pair(weight, v));
            else
                mst.emplace_back(u, v);
        }
    }

    return mst;
}

bool HashNodes::check_if(int id1, int id2, HashNodes hashNodes, Realworld realworld) {
    const auto* it1 = realworld.realworld.findVertex(id1);
    const auto* it2 = realworld.realworld.findVertex(id2);
    for (auto a : it1->getAdj()) {
        if (a->getDest()->getInfo() == id2)
            return true;
    }
    return false;
}

void HashNodes::Graph_ReadLines(int decision, HashNodes hashnodes, Realworld realworld) {
    std::string input;
    switch (decision) {
        case 1:
            input = "../data/realworld/graph1/edges.csv";
            break;
        case 2:
            input = "../data/realworld/graph2/edges.csv";
            break;
        case 3:
            input = "../data/extra/graph3/edges.csv";
            break;
        case 4:
            input = "../data/extra/Extra_Fully_Connected_Graphs/edges_25.csv";
            break;
        case 5:
            input = "../data/extra/Extra_Fully_Connected_Graphs/edges_400.csv";
            break;
        case 6:
            input = "../data/extra/Extra_Fully_Connected_Graphs/edges_900.csv";
            break;
        default:
            return;
    }
    std::ifstream MyReadFile(input);
    std::string line;
    getline(MyReadFile, line);

    while (std::getline(MyReadFile, line)) {
        std::stringstream ss(line);
        std::string origem, destino, distancia;
        getline(ss, origem, ',');
        getline(ss, destino, ',');
        getline(ss, distancia, ',');
        realworld.realworld.addBidirectionalEdge(stoi(origem), stoi(destino), stof(distancia));
    }
}

void HashNodes::Nodes_ReadLines(Realworld &realworld, int decision) {
    std::string input;
    switch (decision) {
        case 1:
            input = "../data/realworld/graph1/nodes.csv";
            break;
        case 2:
            input = "../data/realworld/graph2/nodes.csv";
            break;
        case 3:
            input = "../data/realworld/graph3/nodes.csv";
            break;
        case 4:
            input = "../data/extra/Extra_Fully_Connected_Graphs/nodes.csv";
            break;
        case 5:
            input = "../data/extra/Extra_Fully_Connected_Graphs/nodes.csv";
            break;
        case 6:
            input = "../data/extra/Extra_Fully_Connected_Graphs/nodes.csv";
            break;
        default:
            return;
    }
    std::ifstream MyReadFile(input);
    std::string line;
    getline(MyReadFile, line);

    while (std::getline(MyReadFile, line)) {
        std::stringstream ss(line);
        std::string id, lon, lat;
        getline(ss, id, ',');
        getline(ss, lon, ',');
        getline(ss, lat, ',');
        Nodes nodes = Nodes(stoi(id), stof(lon), stof(lat));
        realworld.realworld.addVertex(stoi(id));
    }
}

Nodes::Nodes(int id, float lon, float lat) {
    this->id = id;
    this->lon = lon;
    this->lat = lat;
}

int Nodes::get_id() const {
    return this->id;
}

float Nodes::get_lon() const {
    return this->lon;
}

float Nodes::get_lat() const {
    return this->lat;
}