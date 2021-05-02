#include <iostream>
#include <vector>
#include "place.hpp"
#include "grille.hpp"
using namespace std;

/* Constructeur vide de Grille */
Grille::Grille() : places{{}} {}

/* Getter (Place)
@return Place */
Place Grille::chargePlace(Coord crds) const {
	for (Place p: places) {
		if (crds == p.get_coord())
			return p;
	}
}