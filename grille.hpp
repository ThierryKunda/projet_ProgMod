#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <iostream>
#include <vector>
#include "place.hpp"
#include "fourmi.hpp"
#include "coord.hpp"
using namespace std;

class Grille {
	// Attributs
	vector<Place> places;

	public:

	// Constructeurs
	Grille();

	// Méthodes
	vector<Place> get_places() {return places;};
	
	Place chargePlace(Coord crds) const;
	void rangePlace(Place p);
	vector<Place> chargEnsPlace(EnsCoord crds);
	void rangeEnsPlace(vector<Place> places);
	void linearisePheroNid();
	void diminuePheroSucre();
	EnsCoord placesVides();

};

void placeNid(Grille &grille, EnsCoord ens);
void placeSucre(Grille &grille, EnsCoord ens);
void placeFourmis(Grille &grille, vector<Fourmi> fourmis);
void initialiseGrille(vector<Fourmi> &fourmis, EnsCoord &ens_sucre, EnsCoord &ens_nid); 
void lineariserPheroNid(Grille &grille);


#endif // GRILLE_HPP
