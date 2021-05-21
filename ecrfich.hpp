#ifndef ECRFICH_HPP
#define ECRFICH_HPP

#include <iostream>     // pour cout
#include <iomanip>      // pour setfill, setw
#include <sstream>      // pour ostringstream
#include <fstream>      // pour ofstream
#include <string>
#include "grille.hpp"

using namespace std;

// type énuméré pour différentes couleurs
enum class Couleur {blanc, noir, rouge, vert, bleu, magenta, jaune, cyan};

void ecriCouleur(ostream &fichier, int R, int V, int B);
void ecriCouleur(ostream &fichier, Couleur couleur);
void creerFrame(string nom_animation, Grille grille);
void creationAnimation(string echelle_image, string retard, string nom_animation);

#endif