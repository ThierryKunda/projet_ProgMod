#include <iostream>
#include <vector>
#include "doctest.h"
#include "place.hpp"
#include "grille.hpp"
using namespace std;

/* Constructeur vide de Grille */
Grille::Grille() : places{{}} {}

/* Constructeur : à partir d'un vecteur de Place */
Grille::Grille(vector<Place> plcs) : places{plcs} {}


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

EnsCoord Grille::placesVides() {
	EnsCoord ens;
	Coord c = {0,0};
	for (Place p: get_places()) {
		if (estVide(p)) {
			c = p.get_coord();
			ens.ajoute(c);
		}
	}
	return ens;
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

/* Fonction équivalente à rangePlace pour un vecteur de places
 * @param vector<Place>
 */
void Grille::rangeEnsPlace(vector<Place> places) {
	for (Place p: places) {
		rangePlace(p);
	}
}

/* Renvoie l'ensemble des coords des voisines de la place en paramètre
 * @param Place
 * @return EnsCoord
 */
EnsCoord Grille::CoordsPlacesVoisines(Place place) {
	return voisines(place.get_coord());
}

/* Calcule l'intensité maximale de phéromone de nid entre plusieurs places
 * @param vector<Place>
 * @return double
 */
double maxIntensitePheroNid(vector<Place> places) {
	double max_intensite;
	for (int i = 1; i < places.size(); i++) {
		max_intensite = max(places[i].get_pheroNid(), places[i-1].get_pheroNid());
	}
	return max_intensite;
}

void Grille::linearisePheroNid() {
	// On copie les places de la grille
	vector<Place> places = get_places();
	double m = 1;
	// On initialise l'intensité à pour toutes les places
	for (Place pl: places) {
		pl.posePheroNid(1);
	}
	// On linéarise
	for (Place pl: places) {
		vector<Place> places_voisines = chargEnsPlace(CoordsPlacesVoisines(pl));
		m = maxIntensitePheroNid(places_voisines);
		if (pl.get_pheroNid() < 1) pl.posePheroNid(max(m - 1/TAILLEGRILLE, 0));
	}
	// On enregistre ces modifications en rangeant les places
	rangeEnsPlace(places);
}

/* Procédure placeNid
 * @param grille : grille a modifier, 
 * ens : ensemble de coordonnees concernees
 */
void placeNid(Grille &grille, EnsCoord ens) {
	// Place un element de nid sur toutes les cases de la grille contenues dans l'ensemble ens
	vector<Place> places  = grille.chargEnsPlace(ens);
	for (Place p: places) {
		p.poseNid();
	}
	grille.rangeEnsPlace(places);
}

/* Procédure placeSucre
 * @param grille : grille a modifier, 
 * ens : ensemble de coordonnees concernees
 */
void placeSucre(Grille &grille, EnsCoord ens) {
	// Place du sucre sur toutes les cases de la grille contenues dans l'ensemble ens
	vector<Place> places  = grille.chargEnsPlace(ens);
	for (Place p: places) {
		p.poseSucre();
	}
	grille.rangeEnsPlace(places);
}


void placeFourmis(Grille &grille, vector<Fourmi> fourmis) {
	EnsCoord ens = grille.placesVides();
	Place p = {Coord{0,0}};
	for (int i=0; i<fourmis.size(); i++) {
		p = grille.chargePlace(ens.ieme(i));
		p.poseFourmi(fourmis[i]);
		grille.rangePlace(p);	
	}
}



// TESTS

TEST_CASE("Méthode chargeEnsPlace") {
	vector<Place> places_init = {
		Coord{0,0},
		Coord{1,0},
		Coord{2,0},
		Coord{3,0},
		Coord{4,0}
	};
	Grille grille = {places_init};
	vector<Place> places_modifs = {Place{Coord{0,0}}, Place{Coord{2,0}}};
	places_modifs[0].poseSucre();
	places_modifs[1].poseNid();
	grille.rangeEnsPlace(places_modifs);
	vector<Place> modifs = grille.chargEnsPlace(EnsCoord{{Coord{0,0}, Coord{2,0}}});
	CHECK(modifs[0].contientSucre());
	CHECK(modifs[1].get_pheroNid() == 1);
}