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
	if (crds.get_li() < 0 || crds.get_li() > 20 || crds.get_co() < 0 || crds.get_co() > 20)
		throw("Coordonnées invalides");
	for (Place p: places) {
		if (crds == p.get_coord())
			return p;
	}
	// On renvoie la place de coordonnées (0,0) par défaut
	return Place(Coord{0,0});
}

vector<Place> Grille::chargEnsPlace(EnsCoord ens_c) {
	vector<Place> ens_place;
	for (Coord c: ens_c.get_coords()) {
		ens_place.push_back(chargePlace(c));
	}
	return ens_place;
}

/* Setter (Place) */
void Grille::rangePlace(Place p) {
	for (Place pl: get_places()) {
		if (p.get_coord() == pl.get_coord())
			pl = p;
	}
}

void Grille::rangeEnsPlace(vector<Place> places) {
	for (Place p: places) {
		rangePlace(p);
	}
}

/* Renvoie l'ensemble des coords de la place en paramètre */
EnsCoord Grille::CoordsPlacesVoisines(Place place) {
	return voisines(place.get_coord());
}

/* Procédure placeNid
 * @param grille : grille a modifier, 
 * ens : ensemble de coordonnees concernees
 */
void placeNid(Grille &grille, EnsCoord ens) {
	// Place un element de nid sur toutes les cases de la grille contenues dans l'ensemble ens
	Place p;
	for (int i=0, i<ens.taille(); i++) {
		p = grille.chargePlace(ens.ieme(i))
		p.poseNid();
		grille.rangePlace(p);
	}
}

/* Procédure placeSucre
 * @param grille : grille a modifier, 
 * ens : ensemble de coordonnees concernees
 */
void placeSucre(Grille &grille, EnsCoord ens) {
	// Place du sucre sur toutes les cases de la grille contenues dans l'ensemble ens
	Place p;
	for (int i=0, i<ens.taille(); i++) {
		p = grille.chargePlace(ens.ieme(i))
		p.poseSucre();
		grille.rangePlace(p);
	}
}

EnsCoord Grille::placesVides() {
	EnsCoord ens;
	Coord c;
	for (Place p: get_places()) {
		if (p.estVide()) {
			c = p.get_coord():
			ens.ajoute(c);
		}
	}
	return ens;
}

void placeFourmis(Grille &grille, vector<Fourmi> fourmis) {
	EnsCoord ens = grille.placesVides();
	for (int i=0; i<fourmis.size(); i++) {
		p = grille.chargePlace(ens.ieme(i))
		p.poseFourmi(fourmis[i]);
		grille.rangePlace(p);	
	}
}
