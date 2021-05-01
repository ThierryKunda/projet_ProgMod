#ifndef PLACE_HPP
#define PLACE_HPP

#include <iostream>
#include <vector>
#include "fourmi.hpp"
#include "coord.hpp"

using namespace std;

class Place{
    // Attriubuts
    
    Coords coord;
    bool sucre;
    double pheroNid;
    int pheroSucre, numeroFourmi;
    
    public:
    
    // Constructeurs
    
    Place(Coords crds) : coord{crds}, sucre{false}, pheroNid{0}, pheroSucre{0}, numeroFourmi{-1};
    
    // Methodes
    
    int get_coord() {return coord;};
    int get_numeroFourmi() {return numeroFourmi;};
    double get_pheroNid() {return pheroNid;};
    
    bool contientSucre() const {return sucre;};
    bool contientNid() const {return pheroNid == 1;};
    bool estSurUnePiste() const {return pheroSucre > 0};
    void poseSucre() {sucre = true;};
    void enleveSucre() {sucre = false;};
    void poseNid() {pheroNid = 1;};
    void poseFourmi(Fourmi &f) {numeroFourmi = f.get_num();};
    void enleveFourmi(Fourmi &f) {numeroFourmi = -1;};
    void posePheroNid(double intensite) {pheroNid = intensite;};
    void posePheroSucre() {pheroSucre = 255;};
    void diminuePheroSucre() {pheroSucre -=5;};
};

// Fonctions 

void deplaceFourmi(Fourmi &f, Place &p1, Place &p2);
bool estVide(const Place p);
bool estPlusProcheNid(const Place p1, const Place p2);

#endif