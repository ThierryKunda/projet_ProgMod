#include "ecrfich.hpp"
#include "doctest.h"
using namespace std;

/* "Ecris un pixel de couleur définie"
@param ostream, fichier ppm
@param int R
@param int V
@param int B
 */
void ecriCouleur(ostream &fichier, int R, int V, int B) {
  fichier << R << " " << V << " " << B << " ";
}

/* Ecris un pixel à partir d'une couleur prédéfinie
 * @param Couleur
 */
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

void couleurUnie(ostream& fichier, int R, int V, int B) {
  for (int i = 0; i < TAILLEGRILLE; i++) {
    for (int j = 0; j < TAILLEGRILLE; j++) {
      ecriCouleur(fichier, R,V,B);
    }
    fichier << endl;
  }
}

void couleurUnie(ostream& fichier, Couleur couleur) {
  for (int i = 0; i < TAILLEGRILLE; i++) {
    for (int j = 0; j < TAILLEGRILLE; j++) {
      ecriCouleur(fichier, couleur);
    }
    fichier << endl;
  }
}

// Création de l'animation

// variable globale permettant de creer des noms de fichiers differents
int compteurFichier = 0;
// action dessinant un damier
void creerFrame(string nom_animation){
  ostringstream filename;
  // creation d'un nouveau nom de fichier de la forme img347.ppm
  filename << nom_animation << setfill('0') << setw(3) << compteurFichier << ".ppm";
  compteurFichier++;
  cout << "Ecriture dans le fichier : " << filename.str() << endl;
  // ouverture du fichier
  ofstream fic(filename.str(), ios::out | ios::trunc);
  // ecriture de l'entete
  fic << "P3" << endl
      << TAILLEGRILLE << " " << TAILLEGRILLE << " " << endl
      << 255 << " " << endl;
  // ecriture des pixels

  /* A compléter */
  
    // fin de ligne dans l'image
    fic << endl;
  // fermeture du fichier
  fic.close();
}