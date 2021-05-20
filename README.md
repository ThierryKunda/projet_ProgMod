# Programme

## Affichage : fichier `.ppm`

### Structure
Le fichier contient :
- son type : "PN", où N est un nombre (ici, 3)
- ses dimensions : "l h", où l est la largeur et h la hauteur
- la valeur maximum des couleurs : max
- le corps de l'image : un pixel est représenté par des valeurs RVB, ils sont séparés d'au moins 2 espaces (ici 4)

### Contenu

```
PN
l L
max
RVB RVB ... RVB
... ... ... ...
RVB ... ... RVB
```

### Commandes

Le fichier qui crée les images est ecrfich.
Il faut donc le compiler, avec `make` ou `make ecrfich`.
L'executable créera un ensemble d'images `.ppm` à animer.

Il faudra ainsi les réunir en un gif avec : 

```
convert -scale 300 -delay 10 img*.ppm nom_animation.gif
```