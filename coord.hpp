#ifndef COORD_HPP
#define COORD_HPP

#include <iostream>
#include <vector>
using namespace std;

const int TAILLEGRILLE = 20;

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
	
	public:
<<<<<<< HEAD
	
	// Constructeurs
	
	EnsCoord(vector<Coord> c) : coords{c} {};
	
	// Méthodes 
	
	int position(const Coord objet);
=======

	// Méthodes

	vector<Coord> get_coords() const {return coords;};
>>>>>>> 323d6fbec21d14e589d89dbfd3c7aa4d09e7c485
};

#endif
