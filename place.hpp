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
    
    Place(Coords crds);
    
    // Methodes
    
    Coords get_coords() const {return coord;};
    int get_pheroSucre() const {return pheroSucre;};
    double get_pheroNid() const {return pheroNid;};
    int get_numeroFourmi() const {return numeroFourmi;};
    
    void set_sucre(bool b) {sucre = b;};
    void set_pheroNid(double x) {pheroNid = x;};
    void set_pheroSucre(int i) {pheroSucre = i;};
    void set_numeroFourmi(int i) {numeroFourmi = i;}
    
    bool contientSucre() const {return sucre;};
    bool contientNid() const {return get_pheroNid == 1;};
    bool estSurUnePiste() const {return get_pheroSucre > 0};
    void poseSucre() {set_sucre(true);};
    void enleveSucre() {set_sucre(false);};
    void poseNid() {set_pheroNid(1);};
    void poseFourmi(Fourmi &f) {set_numeroFourmi(f.get_num());};
    void enleveFourmi(Fourmi &f) {set_numeroFourmi(-1);};
    void posePheroNid(double intensite) {set_pheroNid(intensite);};
    void posePheroSucre() {set_pheroSucre(255);};
    void diminuePheroSucre() {set_pheroSucre(get_pheroSucre()-5);};
};

// Fonctions 

void deplaceFourmi(Fourmi &f, Place &p1, Place &p2);


#endif