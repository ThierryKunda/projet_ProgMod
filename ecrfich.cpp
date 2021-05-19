#include <iostream>     // pour cout
#include <iomanip>      // pour setfill, setw
#include <sstream>      // pour ostringstream
#include <fstream>      // pour ofstream
#include <string>
#include "doctest.h"
using namespace std;

// type énuméré pour différentes couleurs
enum class Couleur {blanc, noir, rouge, vert, bleu, magenta, jaune, cyan};


/* "Ecris un pixel de couleur définie"
@param ostream, fichier ppm
@param int, R
@param int, V
@param int, B
 */
void ecriCouleur(ostream &fichier, int R, int V, int B) {
  fichier << R << " " << V << " " << B << " ";
}

/* Ecris un pixel à partir d'une couleur prédéfinie */
void ecriCouleur(ostream &fichier, Couleur couleur) {
  switch (couleur) {
    case Couleur::blanc: fichier << 255 << " " << 255 << " " << 255 << " "; break;
    case Couleur::noir: fichier << 0 << " " << 0 << " " << 0 << " "; break;
    case Couleur::rouge: fichier << 255 << " " << 0 << " " << 0 << " "; break;
    case Couleur::vert: fichier << 0 << " " << 255 << " " << 0 << " "; break;
    case Couleur::bleu: fichier << 0 << " " << 0 << " " << 255 << " "; break;
    case Couleur::magenta: fichier << 255 << " " << 0 << " " << 255 << " "; break;
    case Couleur::jaune: fichier << 255 << " " << 255 << " " << 0 << " "; break;
    case Couleur::cyan: fichier << 0 << " " << 255 << " " << 255 << " "; break;
  }
}


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