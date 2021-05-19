#include <iostream>
#include <vector>
#include "fourmi.hpp"
#include "doctest.h"
using namespace std;

// Constructeur
Fourmi::Fourmi(Coord crds, int indice) : coords{crds}, num{indice}, sucre{false}, vivante{true} {
    if (num < 0) {throw("Indice négatif : non valide.");}
}

// Constructeurs
Colonie::Colonie() : fourmis{{}}, indices{{}} {}

Colonie::Colonie(vector<Fourmi> col) : fourmis{col}, indices{{}} {
    for (Fourmi f: col) {indices.push_back(f.get_num());}
}

/* Setter de fourmis 
@param vector<Fourmi> */
void Colonie::set_colonie(vector<Fourmi> col) {
    fourmis = col;
}

/* Ajoute une fourmi à la colonie à partir de sa copie
 * @param Fourmi
 */
void Colonie::ajouteFourmi(Fourmi &f) {
    fourmis.push_back(f);
    indices.push_back(f.get_num());
}

/* Ajoute une fourmi à la colonie à partir de son indice et d'un vecteur de Fourmi */
void Colonie::ajouteFourmi(vector<Fourmi> fs, int indice) {
    for (Fourmi f: fs) {
        if (f.get_num() == indice) {ajouteFourmi(f);}
    }
} 

/* Retire une fourmi de la colonie à partir de sa copie
 * @param Fourmi
 */
void Colonie::retireFourmi(Fourmi &f) {
    // On divise la colonie en deux parties
    vector<Fourmi> part_gauche;
    vector<Fourmi> part_droite;
    int i = 0;
    while (fourmis[i].get_num() != f.get_num()) {
        part_gauche.push_back(fourmis[i]);
        i++;
    }
    i++; // On inclut pas l'élément à retirer
    for (int k = i; k < fourmis.size(); k++) {
        part_droite.push_back(fourmis[k]);
    }
    // On fusionne les deux parties
    vector<Fourmi> part_entier;
    for (Fourmi f: part_gauche) part_entier.push_back(f);
    for (Fourmi f: part_droite) part_entier.push_back(f);
    set_colonie(part_entier);
}

void Colonie::retireFourmi(vector<Fourmi> col, int indice) {
    for (Fourmi f: col) {
        if (f.get_num() == indice) retireFourmi(f);
    }
}