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
bool condition_1(Fourmi f, Place p1, Place p2);
bool condition_2(Fourmi f, Place p1, Place p2);
bool condition_3(Fourmi f, Place p1, Place p2);
bool condition_4(Fourmi f, Place p1, Place p2);
bool condition_5(Fourmi f, Place p1, Place p2);
bool condition_6(Fourmi f, Place p1, Place p2);
bool condition_7(Fourmi f, Place p1, Place p2);
bool condition_n(int x, Fourmi f, Place p1, Place p2);
void action_1(int x, Fourmi &f);
void action_2(int x, Fourmi &f);
void action_3(int x, Fourmi &f);
void action_4(int x, Fourmi &f);
void action_5(int x, Fourmi &f);
void action_6(int x, Fourmi &f);
void action_7(int x, Fourmi &f);
Coord voisinVideAleatoire(Grille g, Place p);

#endif