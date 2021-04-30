#ifndef FOURMI_HPP
#define FOURMI_HPP

#include <iostream>
#include <vector>
#include "coord.hpp"

class Fourmi {
    // Attributs
    Coord coords;
    int num;
    bool sucre;

    public:

    // Constructeur
    Fourmi(Coord crds, int indice);

    // Méthodes
    Coord get_coords() const {return coords;};
    void deplace(Coord c) {coords = c;};
    void deplace(int lig, int col) {coords = {lig, col};};
    int get_num() const {return num;};
    bool porteSucre() const {return sucre;};
    void prendSucre() {sucre = true;};
    void poseSucre() {sucre = false;};
    

};

#endif // FOURMI_HPP