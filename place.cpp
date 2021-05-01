#include <iostream>
#include <vector>
#include "coord.hpp"
#include "fourmi.hpp"
#include "place.hpp"
#include "doctest.h"

using namespace std;

// Fonctions

void deplaceFourmi(Fourmi &f, Place &p1, Place &p2) {
    p1.enleveFourmi();
    f.deplace(p2.get_coord());
    p2.poseFourmi(f);
}

bool estVide(const Place p) {
   return not (p.contientSucre() or p.contientNid() or p.get_numeroFourmi()!=-1);
}

bool estPlusProcheNid(const Place p1, const Place p2) {
    return (p1.get_pheroNid() >= p2.get_pheroNid());
}

