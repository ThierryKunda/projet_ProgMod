#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <iostream>
#include <vector>
#include "place.hpp"
using namespace std;

class Grille {
	// Attributs
	vector<Place> places;

	public:

	// Constructeurs
	Grille();

	// Méthodes
	Place chargePlace(Coord crds) const;
	void rangePlace(Place p);
	void linearisePheroNid();
	void diminuePheroSucre();

};

#endif // GRILLE_HPP