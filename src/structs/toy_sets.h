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
    void ReadLines(int decision);

    Graph<int> toy_set;

    void backtrack_tsp(vector<int>& current_path, unordered_set<int>& visited, vector<int>& best_path, double& best_cost, int current);
    void backtrack(Graph<int>& graph);

};



/*

class Tourisms{
    private:
        int origem;
        int destino;
        double distancia;
        string origem_nome;
        string destino_nome;

    public:
        Tourisms(int origem, int destino, double  distancia, string origem_nome, string destino_nome);
        int get_origem();
        int get_destino();
        double get_distancia();
        string get_origem_nome();
        string  get_destino_nome();
};

struct TourismHash{
    int operator() (const Tourisms& b) const {
        const string& code = b.getCode();
        unsigned  int hash = 5381;

        for(char c: b.getCode()){
            hash = 33*hash + static_cast<unsigned int>(c);
        }

        return hash % 3019;
    }

    bool operator()(const Tourisms &b1, const Tourisms &b2) const {
        return b1.getCode() == b2.getCode();
    }

};

typedef unordered_set<Tourisms, TourismHash,TourismHash> TourismTable;
class HashTourism{
    public:
    TourismTable tourismTable;
    void readLines(Tourisms &tourisms, int decision);




};
*/
#endif //DA_PROJ2_TOY_SETS_H
