#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "principal.hpp"
using namespace std;

// Fonctions et méthodes de l'algorithme principale

bool condition_1(Fourmi f, Place p1, Place p2) {
    // On initialise à partir des attributs de f
    Fourmi fourmi_adj = {p1.get_coord(), f.get_num(), f.get_colonie()};
    for (Fourmi f_adj: fourmis_init) {
        if (f_adj.get_num() == p2.get_numeroFourmi()) {fourmi_adj = f_adj;}
    }
    return f.estVivante() && p2.contientFourmi() && (f.get_colonie()  == fourmi_adj.get_colonie());
}

bool condition_2(Fourmi f, Place p1, Place p2) {
    return !f.porteSucre() && p2.contientSucre();
}

bool condition_3(Fourmi f, Place p1, Place p2) {
    return f.porteSucre() && p2.contientNid();
}

bool condition_4(Fourmi f, Place p1, Place p2) {
    return f.porteSucre() && p2.estVide() && estPlusProcheNid(p1, p2);
}

bool condition_5(Fourmi f, Place p1, Place p2) {
    return !f.porteSucre() && p1.estSurUnePiste() && p2.estVide() && !estPlusProcheNid(p1,p2) && p2.estSurUnePiste();
}

bool condition_6(Fourmi f, Place p1, Place p2) {
    return !f.porteSucre() && p2.estSurUnePiste() && p2.estVide();
}

bool condition_7(Fourmi f, Place p1, Place p2) {
    return !f.porteSucre() && p2.estVide();
}

bool condition_n(int x, Fourmi f, Place p1, Place p2) {
    switch (x)
    {
    case 1 : return condition_1(f, p1, p2); break;
    case 2 : return condition_2(f, p1, p2); break;
    case 3: return condition_3(f, p1, p2); break;
    case 4 : return condition_4(f, p1, p2); break;
    case 5 : return condition_5(f, p1, p2); break;
    case 6 : return condition_6(f, p1, p2); break;
    case 7 : return condition_7(f, p1, p2); break;
    default: return false;break;
    }
}

void action_1(Fourmi &f, Place &p1, Place &p2) {
    p2.enleveFourmi();
}

void action_2(Fourmi &f, Place &p1, Place p2) {
    f.porteSucre();
    p1.posePheroSucre();
}

void action_3(Fourmi &f, Place &p1, Place p2) {
    p1.poseSucre();
}

void action_4(Fourmi &f, Place &p1, Place p2) {
    deplaceFourmi(f, p1, p2);
    p2.posePheroSucre();
}

void action_5(Fourmi &f, Place &p1, Place p2) {
    deplaceFourmi(f, p1, p2);
}

void action_6(Fourmi &f, Place &p1, Place p2) {
    deplaceFourmi(f, p1, p2);
}

void action_7(Fourmi &f, Place &p1, Place p2) {
    deplaceFourmi(f, p1, p2);
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