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
    bool vivante;
    string colonie;

    public:

    // Constructeur
    Fourmi(Coord crds, int indice);
    Fourmi(Coord crds, int indice, string nom_col);

    // Méthodes
    Coord get_coords() const {return coords;};
    string get_colonie() const {return colonie;};
    void deplace(Coord c) {coords = c;};
    void deplace(int lig, int col) {coords = {lig, col};};
    int get_num() const {return num;};
    bool porteSucre() const {return sucre;};
    void prendSucre() {sucre = true;};
    void poseSucre() {sucre = false;};
    bool estVivante() {return vivante;};
    void meurt() {vivante = false;};

};

class Colonie {
    // Attributs
    string nom_colonie;
    vector<Fourmi> fourmis;
    vector<int> indices;

    public:

    // Constructeurs
    Colonie();
    Colonie(vector<Fourmi> col);
    Colonie(vector<Fourmi> col, string nom);

    // Méthodes
    vector<Fourmi> get_fourmis() const {return fourmis;};
    vector<int> get_indices() const {return indices;};
    void set_colonie(vector<Fourmi> col);
    void ajouteFourmi(Fourmi &f);
    void ajouteFourmi(vector<Fourmi> col, int indice);
    void retireFourmi(Fourmi &f);
    void retireFourmi(vector<Fourmi> col, int indice);
};

#endif // FOURMI_HPP