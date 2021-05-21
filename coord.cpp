#include <iostream>
#include "coord.hpp"
#include "doctest.h"

using namespace std;

// Constructeurs de la classe Coord

Coord::Coord(int lig, int col) : li{lig}, co{col} {
	if (li > TAILLEGRILLE or li < 0 or co > TAILLEGRILLE or co < 0)
		throw invalid_argument("Coordonnées invalides");
}

// Surcharges pour la classe Coord

ostream &operator<<(ostream &out, Coord c) {
	out << "(" << c.get_li() << "," << c.get_co() << ")";
	return out;
}

bool operator==(Coord c1, Coord c2) {
	return (c1.get_li() == c2.get_li() and c1.get_co() == c2.get_co());
}

bool operator!=(Coord c1, Coord c2) {
	return !(c1==c2);
}

// Constructeurs de la classe EnsCoord

EnsCoord::EnsCoord(){}

// Méthodes de la classe EnsCoord

/* Renvoie la position de l'argument dans l'ensemble des coordonnées
@param Coord à chercher dans l'ensemble
@return indice de position

*/
int EnsCoord::position(const Coord c) {
	for (int i=0; i < int(coords.size()); i++) {
		if (coords[i] == c) return i;
	}
	return -1;
}

/* Getter 
@return vector<Coord>
*/
vector<Coord> EnsCoord::get_coords() const {return coords;};

/* Vérifie que l'ensemble contient l'argument 
@param Coord à chercher dans l'ensemble
@return bool
*/
bool EnsCoord::contient(const Coord c) {return position(c) != -1;};

/* Vérifie que l'ensemble est vide
@return bool */
bool EnsCoord::estVide() const {return coords.size()==0;};

/* Renvoie la taille de l'ensemble
@return int */
int EnsCoord::taille() const {return coords.size();};

/* Renvoie le n-ième élément de l'ensemble
@param n indice
@return Coord */
Coord EnsCoord::ieme(int n) {return coords[n];};

/* Ajoute un élément à l'ensemble
@param Coord à ajouter */
void EnsCoord::ajoute(const Coord c) {
	coords.push_back(c);
}

Coord EnsCoord::choixHasard() const {
	int ind_aleat = rand() % taille();
	return coords[ind_aleat];
}

// Surcharges pour la classe EnsCoord
	
ostream &operator<<(ostream& out, EnsCoord &e) {
	for (Coord c: e.get_coords()) {
		out << c << endl;
	}
	return out;
}

// Procédures et Fonctions

int min(const int a, const int b) {
    if (a<=b) return a;
    return b;
}

int max(const int a, const int b) {
    if (a>=b) return a;
    return b;
}

EnsCoord voisines(const Coord c) {
    EnsCoord result;
    int lig = c.get_li();
    int col = c.get_co();
    int imin = max(lig - 1, 0);
    int imax = min(lig + 1, TAILLEGRILLE -1);
    int jmin = max(col - 1, 0);
    int jmax = min(col + 1, TAILLEGRILLE -1);
    for (int i=imin; i<=imax; i++) {
        for (int j=jmin; j<=jmax; j++) {
            if (Coord{i,j} != c) result.ajoute(Coord{i,j});
        }
    }
    return result;
}

// TESTS

TEST_CASE("opérateur égalité pour la classe Coord") {
	CHECK ( Coord{0,5} == Coord{0,5} );
	CHECK ( Coord{18,4} == Coord{18,4} );
	
	CHECK_FALSE ( Coord{3,7} == Coord{11,14} );
	CHECK_FALSE ( Coord{1,8} == Coord{8,1} );
}

TEST_CASE("opérateur différence pour la classe Coord") {
	CHECK ( Coord{13,5} != Coord{0,5} );
	CHECK ( Coord{1,8} != Coord{8,1} );
	
	CHECK_FALSE ( Coord{0,5} != Coord{0,5} );
	CHECK_FALSE ( Coord{18,4} != Coord{18,4} );
}

TEST_CASE("Méthode position") {
	EnsCoord c = EnsCoord{{Coord{1,2}, Coord{3,4}, Coord{5,6}}};
	
	CHECK ( c.position(Coord{1,2}) == 0);
	CHECK ( c.position(Coord{3,4}) == 1);
	CHECK ( c.position(Coord{1,3}) == -1);
}

TEST_CASE("Méthode estVide") {
    EnsCoord c = EnsCoord{ {Coord{1,2}} };
    EnsCoord cvide = EnsCoord{{}};
    
    CHECK ( cvide.estVide() );
    CHECK_FALSE ( c.estVide() );
}

TEST_CASE("Méthode taille") {
    EnsCoord c1 = EnsCoord{ { Coord{1,2}, Coord{3,4}, Coord{5,6} } };
    EnsCoord c2 = EnsCoord{{Coord{0,0}}};
    EnsCoord c3 = EnsCoord{ { Coord{3,4}, Coord{5,6} } };
    
    CHECK ( c1.taille()==3 );
    CHECK ( c2.taille()==1 );
    CHECK_FALSE ( c3.taille()==3 );
}

TEST_CASE("Méthode ieme") {
    EnsCoord c1 = EnsCoord{ { Coord{1,2}, Coord{3,4}, Coord{5,6} } };
    EnsCoord c2 = EnsCoord{{Coord{0,0}}};
    EnsCoord c3 = EnsCoord{ { Coord{3,4}, Coord{5,6} } };
    
    CHECK ( c1.ieme(2) == Coord{5,6} );
    CHECK ( c2.ieme(0) == Coord{0,0} );
    CHECK_FALSE ( c3.ieme(1) == Coord{1,1} );
}

TEST_CASE("Méthode ajoute") {
	EnsCoord crds = EnsCoord{{Coord{1,2}, Coord{3,4}}};
	crds.ajoute(Coord{5,6});
	CHECK (crds.get_coords() == vector<Coord>{Coord{1,2}, Coord{3,4}, Coord{5,6}});
}

TEST_CASE("Fonction voisines") {
	vector<Coord> cs;
	for (int i = 0; i < TAILLEGRILLE; i++) {
		for (int j = 0; j < TAILLEGRILLE; j++) {
			cs.push_back(Coord{i,j});
		}
	}
	int milieu = TAILLEGRILLE/2-1;

	// Coin supérieur gauche (=premier élément)
	EnsCoord vois_haut_gauche = voisines(Coord{0,0});
	EnsCoord vois_milieu = voisines(Coord{milieu,milieu}); // (9,9)
	EnsCoord vois_milieu_droit = voisines(Coord{TAILLEGRILLE-1, milieu}); // (19,9)

	// Tests
	for (Coord co: vector<Coord>{{0,1}, {1,0}, {1,1}}) {
		CHECK(vois_haut_gauche.contient(co));
	}
	
	for (Coord co: vector<Coord>{{18, 8}, {18, 9}, {18, 10}, {19, 8}, {19, 10}}) {
		CHECK(vois_milieu_droit.contient(co));
	}
	
	for (Coord co: vector<Coord>{{8,9}, {10,9}, {9,10}, {9,8}, {8,8}, {10,10}, {10, 8}, {8,10}}) {
		CHECK(vois_milieu.contient(co));
	}

}

TEST_CASE("Méthode choixHasard") {
	EnsCoord ens = {vector<Coord>{{1,2}, {3,4}, {5,6}}};
	Coord choix_coord = ens.choixHasard();
	CHECK(ens.contient(choix_coord));
	cout << "Coordonnées aléatoires : " << choix_coord << ens.choixHasard() << ens.choixHasard() << endl;
}

