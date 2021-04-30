#include <iostream>
#include <vector>
#include "fourmi.hpp"
#include "doctest.h"
using namespace std;

// Constructeur
Fourmi::Fourmi(Coord crds, int indice) : coords{crds}, num{indice}, sucre{false}{
    if (num < 0) {throw("Indice négatif : non valide.");}
}
