#include <iostream>
#include "coord.hpp"
#include "doctest.h"

using namespace std;

Coord::Coord(int lig, int col) : li{lig}, co{col} {
	if (li > TAILLEGRILLE or li < 0 or co > TAILLEGRILLE or co < 0)
		throw invalid_argument("Coordonnées invalides");
}

ostream &operator<<(ostream &out, Coord c) {
	out << "(" << c.get_li() << "," << c.get_co() << ")";
	return out;
}

bool operator==(Coord c1, Coord c2) {
	return (c1.get_li() == c2.get_li() and c1.get_co() == c2.get_co());
}

TEST_CASE("opérateur égalité pour la classe Coord") {
	CHECK ( Coord{0,5} == Coord{0,5} );
	CHECK ( Coord{18,4} == Coord{18,4} );
	
	CHECK_FALSE ( Coord{3,7} == Coord{11,14} );
	CHECK_FALSE ( Coord{1,8} == Coord{8,1} );
}

bool operator!=(Coord c1, Coord c2) {
	return not (c1==c2);
}

TEST_CASE("opérateur différence pour la classe Coord") {
	CHECK ( Coord{13,5} != Coord{0,5} );
	CHECK ( Coord{1,8} != Coord{8,1} );
	
	CHECK_FALSE ( Coord{0,5} != Coord{0,5} );
	CHECK_FALSE ( Coord{18,4} != Coord{18,4} );
}
