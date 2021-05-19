#include <iostream>
#include <vector>
#include <exception>
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

/* Renvoie l'EnsCoord des cases vides
 * @return EnsCoord
 */
EnsCoord Grille::placesVides() {
	EnsCoord ens;
	Coord c = {0,0};
	for (Place p: get_places()) {
		if (p.estVide()) {
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
void Grille::	rangePlace(Place p) {
	vector<Place> places_avant = get_places(); 
	for (Place &pl: places_avant) {
		if (p.get_coord() == pl.get_coord()) pl	 = p;
	}
	places = places_avant;
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
	for (unsigned int i = 1; i < places.size(); i++) {
		max_intensite = max(places[i].get_pheroNid(), places[i-1].get_pheroNid());
	}
	return max_intensite;
}

void Grille::linearisePheroNid() {
    bool stable = false; // stable <- Faux
    
    Place p = Place(Coord{0,0}); // initialiastion des variables nécessaires 
    Place pLin = Place(Coord{0,0});
    
    Coord c = Coord(0,0);
    Coord d = Coord(0,0);
    
    EnsCoord lin = EnsCoord({{0,0},{0,1}});
    vector<Coord> lin2;
    
    float maxPheroNid = 0;
    
    while(stable == false) { //tant que pas stable
    stable = true; //stable <- vrai
        
        for(int i = 0; i < TAILLEGRILLE; i++) { // pour toutes les coordonnées c de la grille
            for(int j = 0; j < TAILLEGRILLE; j++) {
                c = Coord(i,j);
                p = Grille::chargePlace(c); // p <- chargerPlace(c)
                
                if(p.get_pheroNid() <  1.) { // si p.pheroNid() < 1 faire
                    lin = voisines(c); // coordVois(ici ,lin) <- voisins(c)
                    maxPheroNid = 0; //  maxPheroNid <- 0
                    lin2 = lin.get_coords(); 
                    
                    for(unsigned int k = 0; k < lin2.size(); k++) { // pour d dans coordVois(lin) faire
                        d = lin.ieme(k);
                        pLin = Grille::chargePlace(d); // voisin <- chargerPlace(v)
                        maxPheroNid = max(maxPheroNid, pLin.get_pheroNid()); //  maxPhero <- max(maxPhero, voisin.pheroNid())
                    } // finpour k
                    maxPheroNid = maxPheroNid - 1. / TAILLEGRILLE; //  maxPhero <- maxPhero - 1. / TAILLE
                    
                    if(maxPheroNid > p.get_pheroNid()) { // si maxPhero > p.pheroNid() faire
                        p.posePheroNid(maxPheroNid); // p.posePheroNid(maxPhero)
                        rangePlace(p); // rangePlace(p)   // Ne pas oublier de mettre à jour la grille
                        stable = false; // stable <- faux
                    } // finsi
                    
                    
                }  // finsi
            } // finpour i
        } // finpour j
    } // fintantque   
}


/* Procédure placeNid
 * @param grille : grille a modifier, 
 * ens : ensemble de coordonnees concernees
 */
void placeNid(Grille &grille, EnsCoord ens) {
	// Place un element de nid sur toutes les cases de la grille contenues dans l'ensemble ens
	vector<Place> places  = grille.chargEnsPlace(ens);
	for (Place &p: places) {
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
	for (Place &p: places) {
		p.poseSucre();
	}
	grille.rangeEnsPlace(places);
}


void placeFourmis(Grille &grille, vector<Fourmi> fourmis) {
	EnsCoord ens = grille.placesVides();
	Place p = {Coord{0,0}};
	for (unsigned int i=0; i<fourmis.size(); i++) {
		p = grille.chargePlace(ens.ieme(i));
		p.poseFourmi(fourmis[i]);
		grille.rangePlace(p);	
	}
}

void initialiseGrille(vector<Fourmi> &fourmis, EnsCoord &ens_sucre, EnsCoord &ens_nid, Grille &grille) {
	Grille g;
	// On définit la grille de taille TAILLEGRILLE x TAILLEGRILLE
	vector<Place> places_init;
	for (int i = 0; i < TAILLEGRILLE; i++) {
		for (int j = 0; i < TAILLEGRILLE; i++) {
			places_init.push_back(Place{Coord{i,j}});
		}
	}
	g = {places_init};
	// On pose les fourmis à leurs places respectives
	placeFourmis(grille, fourmis);
	placeSucre(grille, ens_sucre);
	placeNid(grille, ens_nid);
}

void lineariserPheroNid(Grille &grille) {
	grille.linearisePheroNid();
}

void dessineGrille(Grille grille) {
	vector<Place> places = grille.get_places();
	for (int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++) {
		if (places[i].contientFourmi()) {
			cout << " F ";
		} else if (places[i].contientSucre()) {
			cout << " S ";
		} else if (places[i].contientNid()) {
			cout << " N ";
		} else {
			cout << " x ";
		}
		if (i % TAILLEGRILLE == 0) cout << endl;
	}
	cout << endl;
}

void dessineGrille(Grille grille, string contenu) {
	vector<Place> places = grille.get_places();
	for (int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++) {
		if (contenu == "pheroSucre") {
			cout << " " << places[i].get_pheroSucre() << " ";
		} else if (contenu == "pheroNid") {
			cout << " " << places[i].get_pheroNid() << " ";
		} else {throw("Non valide");}
		if (i % TAILLEGRILLE == 0) cout << endl;
	}
	cout << endl;
}



// TESTS

TEST_CASE("Méthode rangePlace") {
	Place place = {Coord{2,3}};
	place.poseNid();
	Grille grille = {{
		Place{Coord{0,0}},
		Place{Coord{1,2}},
		Place{Coord{2,3}}
	}};
	grille.rangePlace(place);
	Place p_modif = grille.chargePlace(place.get_coord());
	CHECK(p_modif.get_pheroNid() == 1);
}

TEST_CASE("Méthode rangeEnsPlace") {
	vector<Place> plusieurs_places = {{Coord{0,0}}, Coord{1,2}};
	for (Place &p: plusieurs_places)
		p.poseNid();
	Grille grille = {{
		Place{Coord{0,0}},
		Place{Coord{1,2}},
		Place{Coord{2,3}}
	}};
	grille.rangeEnsPlace(plusieurs_places);
	vector<Place> p_modifs;
	for (Place p_modif: p_modifs) CHECK(p_modif.contientNid());
}

TEST_CASE("Méthode placesVides") {
	Grille grille = {{
		Place{Coord{0,0}},
		Place{Coord{1,2}},
		Place{Coord{2,3}}
	}};
	vector<Place> modifs = {Place{Coord{0,0}}, Place{Coord{2,3}}};
	modifs[0].poseSucre(); modifs[1].poseSucre();
	grille.rangeEnsPlace(modifs);
	EnsCoord vides = grille.placesVides();
	for (Coord c: vides.get_coords()) {
		CHECK(c == grille.get_places()[1].get_coord());
	}
}

TEST_CASE("Affichage : texte") {
	vector<Place> places_init;
	for (int i = 0; i < TAILLEGRILLE; i++) {
		for (int j = 0; j < TAILLEGRILLE; j++) {
			places_init.push_back(Place{Coord{j,i}});
		}
	}
	places_init[TAILLEGRILLE * (TAILLEGRILLE/2-1) + TAILLEGRILLE/2].poseNid();
	Grille g = {places_init};
	g.linearisePheroNid();
	dessineGrille(g, "pheroNid");
}