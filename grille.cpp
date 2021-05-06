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

/* Setter (Place) */
void Grille::rangePlace(Place p) {
	for (Place pl: places) {
		if (p.get_coord() == pl.get_coord())
			pl = p;
	}
}

/* Procédure placeNid
 * @param grille : grille a modifier, 
 * ens : ensemble de coordonnees concernees
 */
void placeNid(Grille &grille, const EnsCoord ens) {
	// Place un element de nid sur toutes les cases de la grille contenues dans l'ensemble ens
	for (int i=0, i<ens.taille(); i++) {
		Place p = grille.chargePlace(ens.ieme(i))
		p.poseNid();
		grille.rangePlace(p);
	}
}

/* Procédure placeSucre
 * @param grille : grille a modifier, 
 * ens : ensemble de coordonnees concernees
 */
void placeSucre(Grille &grille, const EnsCoord ens) {
	// Place du sucre sur toutes les cases de la grille contenues dans l'ensemble ens
	for (int i=0, i<ens.taille(); i++) {
		Place p = grille.chargePlace(ens.ieme(i))
		p.poseSucre();
		grille.rangePlace(p);
	}
}

void placeFourmis(Grille &grille, vector<Fourmi> fourmis) {
	for (Fourmi f: fourmis) {
		
}
