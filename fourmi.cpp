#include <iostream>
#include <vector>
#include "fourmi.hpp"
#include "doctest.h"
using namespace std;

// Constructeur
Fourmi::Fourmi(Coord crds, int indice) : coords{crds}, num{indice}, sucre{false}{
    if (num < 0) {throw("Indice négatif : non valide.");}
}

// Constructeurs
Colonie::Colonie() : fourmis{{}}, indices{{}} {}

Colonie::Colonie(vector<Fourmi> col) : fourmis{col}, indices{{}} {
    for (Fourmi f: col) {indices.push_back(f.get_num());}
}