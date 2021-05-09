#include <iostream>
#include <vector>
#include "coord.hpp"
#include "fourmi.hpp"
#include "place.hpp"
#include "doctest.h"

using namespace std;

// Fonctions

/* Déplace une fourmi d'une place à une autre
 * @param fourmi à déplacer
 * @param Place de départ 
 * @param Place d'arrivée
 */
void deplaceFourmi(Fourmi &f, Place &p1, Place &p2) {
    p1.enleveFourmi();
    f.deplace(p2.get_coord());
    p2.poseFourmi(f);
}

/* Vérifie qu'une place est vide
 * @param Place à vérifier
 * @return bool
*/
bool estVide(const Place p) {
   return not (p.contientSucre() or p.contientNid() or p.get_numeroFourmi()!=-1);
}

/* Vérifie qu'une place est plus proche du nid qu'un autre
 * @param Place (à vérifier)
 * @param Place
 * @return bool
*/
bool estPlusProcheNid(const Place p1, const Place p2) {
    return (p1.get_pheroNid() >= p2.get_pheroNid());
}

// TESTS

TEST_CASE("Getter des coordonnées") {
	Place p = {Coord{2,3}};
	CHECK(p.get_coord() == Coord{2,3});
}

TEST_CASE("Méthode contientSucre") {
	Place p = {Coord{2,3}};
	CHECK(!(p.contientSucre()));
	p.poseSucre();
	CHECK(p.contientSucre());
}

TEST_CASE("Méthode contientFourmi (optionnel)") {
	Place p = {Coord{2,3}};
	CHECK(!(p.contientFourmi()));
	Fourmi fourmi = {Coord{1,1}, 3};
	p.poseFourmi(fourmi);
	CHECK(p.contientFourmi());
	p.enleveFourmi();
	CHECK(!(p.contientFourmi()));
}

TEST_CASE("Méthode posePheroNid/Sucre") {
	Place p = {Coord{2,3}};
	p.posePheroNid(0.2);
	p.posePheroSucre();
	CHECK(p.get_pheroNid() == 0.2);
	CHECK(p.estSurUnePiste());
	p.diminuePheroSucre();
	CHECK(p.get_pheroSucre() == 250);
}