#include <iostream>
#include "coord.hpp"

using namespace std;

Coord::Coord(int lig, int col) : li{lig}, co{col} {
	if (li > TAILLEGRILLE or co > TAILLEGRILLE)
		throw invalid_argument("Coordonnées invalides");
}
