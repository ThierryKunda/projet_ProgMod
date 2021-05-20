#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "principal.hpp"
using namespace std;

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
    dessineGrille(simulation);
    return 0;
}