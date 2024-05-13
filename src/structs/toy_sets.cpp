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

            toy_set.addVertex(origem);
            toy_set.addVertex(destino);
            toy_set.addEdge(origem,destino,stod(distancia));
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



            toy_set.addVertex(origem);
            toy_set.addVertex(destino);
            toy_set.addEdge(origem,destino,stod(distancia));
        }
    }
}
