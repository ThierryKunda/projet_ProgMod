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
	vector<Coord> get_coords() const;
	bool contient(const Coord c);
    void ajoute(Coord c);
    bool estVide() const;
    int taille() const;
    Coord ieme(int n);
	Coord choixHasard() const;
};

ostream &operator<<(ostream& out, EnsCoord &e);

// Procédures et fonctions

EnsCoord voisines(EnsCoord &ens, Coord c);

#endif
