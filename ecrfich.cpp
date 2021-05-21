#include "ecrfich.hpp"
#include "doctest.h"
using namespace std;

/* "Ecris un pixel de couleur définie"
@param ofstream, fichier ppm
@param int R
@param int V
@param int B
 */
void ecriCouleur(ofstream &fichier, int R, int V, int B) {
  fichier << R << " " << V << " " << B << " ";
}

/* Ecris un pixel à partir d'une couleur prédéfinie
 * @param Couleur
 */
void ecriCouleur(ofstream &fichier, Couleur couleur) {
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

void couleurUnie(ofstream& fichier, int R, int V, int B) {
  for (int i = 0; i < TAILLEGRILLE; i++) {
    for (int j = 0; j < TAILLEGRILLE; j++) {
      ecriCouleur(fichier, R,V,B);
    }
    fichier << endl;
  }
}

void couleurUnie(ofstream& fichier, Couleur couleur) {
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
void creerFrame(string nom_animation, Grille grille){
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

  // On récupère les cases de la grille
  vector<Place> cases_grille = grille.get_places();
  for (int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++) {
		if (i % TAILLEGRILLE == 0 && i != 0) fic << endl;
    if (cases_grille[i].contientFourmi()) {
			ecriCouleur(fic, Couleur::noir);
		} else if (cases_grille[i].contientSucre()) {
			ecriCouleur(fic, Couleur::magenta);
		} else if (cases_grille[i].contientNid()) {
			ecriCouleur(fic, Couleur::jaune);
		} else {
			ecriCouleur(fic, Couleur::blanc);
		}
  }
  
    // fin de ligne dans l'image
    fic << endl;
  // fermeture du fichier
  fic.close();
}

/* Crée une animation à partir d'image.ppm possédant le même préfixe */
void creationAnimation(string echelle_image, string retard, string nom_animation) {
  string ensFichiers = nom_animation + "*.ppm";
  string commande_chaine = "convert -scale "+echelle_image+" -delay "+retard+" "+ensFichiers+" "+nom_animation+".gif";
  const char *commande = commande_chaine.c_str();
  system(commande);
  // On supprime les frames utilisées pour la conversion
  string nettoyer = "rm -f " + ensFichiers;
  const char* commande2 = nettoyer.c_str();
  system(commande2);
  cout << "Fin de conversion" << endl;
}