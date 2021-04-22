#ifndef COORD_HPP
#define COORD_HPP

#include <iostream>
#include <vector>
using namespace std;

const int TAILLEGRILLE;

class Coord{
	// Attributs
	int li,co;
	
	public:
	
	// Constructeurs
	Coord(int lig, int col);
	
	// Méthodes
	
	int get_li() const {return li;};
	int get_co() const {return co;};
};

class EnsCoord {
	// Attributs
	vector<Coord> coords;
};

#endif
