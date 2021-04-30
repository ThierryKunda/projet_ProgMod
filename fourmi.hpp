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
    int get_num() const {return num;};
    void set_coords(Coord crds) {coords = crds;};
    void set_coords(int lig, int col) {coords = {lig, col};};
    bool porteSucre() const;
    void prendSucre();
    void deplace();
};

#endif // FOURMI_HPP