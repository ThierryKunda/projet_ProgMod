#ifndef PLACE_HPP
#define PLACE_HPP

#include <iostream>
#include <vector>
#include "fourmi.hpp"
#include "coord.hpp"

using namespace std;

class Place{
    // Attriubuts
    
    Coord coord;
    bool sucre;
    double pheroNid;
    int pheroSucre, numeroFourmi;
    
    public:
    
    // Constructeurs
    
    Place(Coord crds) : coord{crds}, sucre{false}, pheroNid{0}, pheroSucre{0}, numeroFourmi{-1} {};
    
    // Methodes
    
    Coord get_coord() const {return coord;};
    int get_numeroFourmi() const {return numeroFourmi;};
    double get_pheroNid() const {return pheroNid;};
    
    bool contientSucre() const {return sucre;};
    bool contientNid() const {return pheroNid == 1;};
	bool contientFourmi() const {return numeroFourmi != -1;};
    bool estSurUnePiste() const {return pheroSucre > 0;};
    void poseSucre() {sucre = true;};
    void enleveSucre() {sucre = false;};
    void poseNid() {pheroNid = 1;};
    void poseFourmi(Fourmi &f) {numeroFourmi = f.get_num(); f.deplace(get_coord());};
    void enleveFourmi() {numeroFourmi = -1;};
    void posePheroNid(double intensite) {pheroNid = intensite;};
    void posePheroSucre() {pheroSucre = 255;};
    void diminuePheroSucre() {if(pheroSucre > 0) pheroSucre-=5;};
};

// Fonctions 

void deplaceFourmi(Fourmi &f, Place &p1, Place &p2);
bool estVide(const Place p);
bool estPlusProcheNid(const Place p1, const Place p2);

#endif
