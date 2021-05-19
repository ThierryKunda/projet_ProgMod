#include <iostream>     // pour cout
#include <iomanip>      // pour setfill, setw
#include <sstream>      // pour ostringstream
#include <fstream>      // pour ofstream
#include <string>
#include "coord.hpp"
#include "fourmi.hpp"
#include "place.hpp"
#include "grille.hpp"
using namespace std;

// Création de l'animation

// variable globale permettant de creer des noms de fichiers differents
int compteurFichier = 0;
// action dessinant un damier
void dessinerDamier(){
  int i,j;
  int r,g,b;
  ostringstream filename;
  // creation d'un nouveau nom de fichier de la forme img347.ppm
  filename << "img" << setfill('0') << setw(3) << compteurFichier << ".ppm";
  compteurFichier++;
  cout << "Ecriture dans le fichier : " << filename.str() << endl;
  // ouverture du fichier
  ofstream fic(filename.str(), ios::out | ios::trunc);
  // ecriture de l'entete
  fic << "P3" << endl
      << 4 << " " << 4 << " " << endl
      << 255 << " " << endl;
  // ecriture des pixels
  for (i = 0; i < 4; i++){
      for (j = 0; j < 4; j++){
        // calcul de la couleur
        if (i == j) { r = 255; g = 0; b = 0; }
        else { r = 0; g = 255; b = 0; }
        // ecriture de la couleur dans le fichier
        fic << r << " " << g << " " << b << "    ";
      }
    // fin de ligne dans l'image
    fic << endl;
  }
  // fermeture du fichier
  fic.close();
}
int main (){
  /* Algorithme principal */

  Grille simulation;
  vector<Place> places_init;
  vector<Fourmi> fourmis_init = {Fourmi{Coord{0,1}, 0}, Fourmi{Coord{1,2}, 1}, Fourmi{Coord{5,6}, 2}};
  EnsCoord positions_sucre = {vector<Coord>{Coord{2,3}, Coord{1,1}, Coord{2,2}}};
  EnsCoord positions_nid = {vector<Coord>{Coord{TAILLEGRILLE/2, TAILLEGRILLE/2},
                                          Coord{TAILLEGRILLE/2 + 1, TAILLEGRILLE/2},
                                          Coord{TAILLEGRILLE/2 + 1, TAILLEGRILLE/2 + 1},
                                          Coord{TAILLEGRILLE/2, TAILLEGRILLE/2 + 1}}};
initialiseGrille(fourmis_init, positions_sucre, positions_nid, simulation);

  return 0;
}
