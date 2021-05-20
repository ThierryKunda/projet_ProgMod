#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "principal.hpp"
using namespace std;

// Fonctions et méthodes de l'algorithme principale

bool condition_1(int x, Fourmi f, Place p1, Place p2) {
    // On initialise à partir des attributs de f
    Fourmi fourmi_adj = {p1.get_coord(), f.get_num(), f.get_colonie()};
    for (Fourmi f_adj: fourmis_init) {
        if (f_adj.get_num() == p2.get_numeroFourmi()) {fourmi_adj = f_adj;}
    }
    return f.estVivante() && p2.contientFourmi() && (f.get_colonie()  == fourmi_adj.get_colonie());
}

bool condition_2(int x, Fourmi f, Place p1, Place p2) {
    return !f.porteSucre() && p2.contientSucre();
}

bool condition_3(int x, Fourmi f, Place p1, Place p2) {
    return f.porteSucre() && p2.contientNid();
}

bool condition_4(int x, Fourmi f, Place p1, Place p2) {
    return f.porteSucre() && p2.estVide() && estPlusProcheNid(p1, p2);
}

bool condition_5(int x, Fourmi f, Place p1, Place p2) {
    return !f.porteSucre() && p2.estSurUnePiste() && p2.estVide() && !estPlusProcheNid(p1,p2);
}

bool condition_6(int x, Fourmi f, Place p1, Place p2) {
    return !f.porteSucre() && p2.estSurUnePiste() && p2.estVide();
}

bool condition_7(int x, Fourmi f, Place p1, Place p2) {
    return !f.porteSucre() && p2.estVide();
}

int main() {
    /* Algorithme principal */

    // 4 fourmis 
    fourmis_init.push_back(Fourmi{Coord{0,0}, 0, "colonie1"});
    fourmis_init.push_back(Fourmi{Coord{TAILLEGRILLE-1,0}, 1, "colonie2"});
    fourmis_init.push_back(Fourmi{Coord{0, TAILLEGRILLE-1}, 2,"colonie3"});
    fourmis_init.push_back(Fourmi{Coord{TAILLEGRILLE-1, TAILLEGRILLE-1}, 3, "colonie4"});
    // 4 éléments de sucre
    positions_sucre.ajoute(Coord{2,8});
    positions_sucre.ajoute(Coord{3,7});
    positions_sucre.ajoute(Coord{3,5});
    positions_sucre.ajoute(Coord{4,2});
    // 4 éléments de nid au centre
    positions_nid.ajoute(Coord{TAILLEGRILLE/2 - 1, TAILLEGRILLE/2 - 1});
    positions_nid.ajoute(Coord{TAILLEGRILLE/2, TAILLEGRILLE/2 - 1});
    positions_nid.ajoute(Coord{TAILLEGRILLE/2 - 1, TAILLEGRILLE/2});
    positions_nid.ajoute(Coord{TAILLEGRILLE/2, TAILLEGRILLE/2});
    initialiseGrille(fourmis_init, positions_sucre, positions_nid, simulation);
    lineariserPheroNid(simulation);
    // dessineGrille(simulation);
    return 0;
}