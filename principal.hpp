#ifndef PRINCIPAL_HPP
#define PRINCIPAL_HPP

#include <iostream>
#include "ecrfich.hpp"
using namespace std;

using tabFourmi = vector<Fourmi>;

Grille simulation;
tabFourmi fourmis_init;
EnsCoord positions_sucre;
EnsCoord positions_nid;


void mettreAJourUneFourmi(Grille &grille, Fourmi &fourmi);
void mettreAJourEnsFourmis(Grille &grille, tabFourmi &tabFourmis);
bool condition_n(int x, Fourmi f, Place p1, Place p2);
void action_n(int x, Fourmi &f);
Coord voisinVideAleatoire(Grille g, Place p);

#endif