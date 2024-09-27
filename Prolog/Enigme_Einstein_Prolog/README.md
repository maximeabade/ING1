# Énigme d'Einstein

## Énoncé de l'énigme
Cinq maisons consécutives, de couleurs différentes, sont habitées par des hommes de différentes nationalités. Ils possèdent tous un animal différent, ont chacun une boisson préférée différente et fument des cigarettes différentes. Qui boit de l'eau et qui possède un zèbre sachant que :

- Le norvégien habite la première maison,
- La maison à  coté de celle du norvégien est bleue,
- L'habitant de la troisième maison boit du lait,
- L'anglais habite la maison rouge,
- L'habitant de la maison verte boit du café,
- L'habitant de la maison jaune fume des kool
- La maison blanche se trouve juste après la verte,
- L'espagnol a un chien,
- L'ukrainien boit du thé,
- Le japonais fume des craven
- Le fumeur de old gold a un escargot,
- Le fumeur de gitane boit du vin,
- Un voisin du fumeur de chesterfield a un renard,
- Un voisin du fumeur de kool a un cheval.

## Lancer la résolution

Ouvrir un terminal à la racine du projet et taper la commande suivante :
```
prolog
```

Charger le fichier `einstein.prolog` avec la commande suivante :
```
['einstein.prolog'].
```

Visualiser la solution de l'énigme avec la commande suivante :
```
einstein(S),maplist(writeln,S).
```

Visualiser la maison où on boit de l'eau, avec la commande suivante :
```
einstein(S),member(X,S),nth1(4,X,eau).
```

Visualiser la maison où on possède un zèbre, avec la commande suivante :
```
einstein(S),member(X,S),nth1(3,X,zebre).
```