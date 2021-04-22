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

ostream &operator<<(ostream &out, Coord c);
bool operator==(Coord c1, Coord c2);
bool operator!=(Coord c1, Coord c2);

class EnsCoord {
	// Attributs
	vector<Coord> coords;
	
	public:
	
	// Constructeurs
	
	EnsCoord(vector<Coord> c) : coords{c} {};
	
	// Méthodes 
	
	int position(const Coord objet);
	vector<Coord> get_coords() const {return coords;};
	bool contient(const Coord c) {return position(c) != -1;};

	void ajoute(Coord c);
};

ostream &operator<<(ostream& out, EnsCoord &e);

#endif
