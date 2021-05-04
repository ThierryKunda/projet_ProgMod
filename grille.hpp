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

void placeNid(Grille &grille, EnsCoord ens);
void placeSucre(Grille &grille, EnsCoord ens);
void placeFourmis(Grille &grille, vector<Fourmi> fourmis);
void initialiseGrille(vector<Fourmi> &fourmis, EnsCoord &ens_sucre, EnsCoord &ens_nid);
void lineariserPheroNid(Grille &grille);

#endif // GRILLE_HPP