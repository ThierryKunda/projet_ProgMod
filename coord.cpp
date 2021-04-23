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
	return not (c1==c2);
}

// Méthodes de la classe EnsCoord

int EnsCoord::position(const Coord c) {
	vector<Coord> tab = get_coords();
	for (int i=0; i < int(tab.size()); i++) {
		if (tab[i] == c) return i;
	}
	return -1;
}

void EnsCoord::ajoute(const Coord c) {
	coords.push_back(c);
}

// Surcharges pour la classe EnsCoord
	
ostream &operator<<(ostream& out, EnsCoord &e) {
	for (Coord c: e.get_coords()) {
		out << c << endl;
	}
	return out;
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

TEST_CASE("Méthode ajoute") {
	EnsCoord crds = EnsCoord{{Coord{1,2}, Coord{3,4}}};
	crds.ajoute(Coord{5,6});
	CHECK (crds.get_coords() == vector<Coord>{Coord{1,2}, Coord{3,4}, Coord{5,6}});
}
