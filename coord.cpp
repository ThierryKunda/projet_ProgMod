#include <iostream>
#include "coord.hpp"

using namespace std;

Coord::Coord(int lig, int col) : li{lig}, co{col} {
	if (li > TAILLEGRILLE or co > TAILLEGRILLE)
		throw invalid_argument("Coordonnées invalides");
}

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
