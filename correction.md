# Correction

## Encapsulation

Pour chaque méthode d'une même classe, on DOIT accéder directement aux attributs.
Dans le cas où on appelle des __procédures__, __fonctions__ ou __méthodes d'autres__ classes, on DOIT utiliser les __getter__ et les __setters__.

## Astuces (utiles)

Pour un vecteur, on peut modifier un élément en particulier en bouclant par référence.

```C++
// Affectation
vector<Element> elements = {Element{...}, ...};
// Modification selon les conditions
for (Element &el: elements) {
    if (...) {
        ...;
        el = ...;
    }
}
```