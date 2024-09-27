% prédicat principal pour résoudre le problème
trouver_somme(Resultat) :-
    findall(Nombre, propriete_pandigital(Nombre), Liste),
    somme_liste(Liste, Resultat).

% prédicat qui calcule la somme d'une liste de nombres
somme_liste([], 0).
somme_liste([Tete|Queue], Somme) :-
    somme_liste(Queue, Somme1),
    Somme is Somme1 + Tete.

% prédicat qui vérifie si un nombre est pandigital et vérifie la propriété
propriete_pandigital(Nombre) :-
    pandigital(Nombre),
    sous_chaine(Nombre, 2, 3, Sub1),
    sous_chaine(Nombre, 3, 3, Sub2),
    sous_chaine(Nombre, 4, 3, Sub3),
    sous_chaine(Nombre, 5, 3, Sub4),
    sous_chaine(Nombre, 6, 3, Sub5),
    sous_chaine(Nombre, 7, 3, Sub6),
    sous_chaine(Nombre, 8, 3, Sub7),
    sous_chaine(Nombre, 9, 3, Sub8),
    string_integer(Sub1, D2),
    string_integer(Sub2, D3),
    string_integer(Sub3, D4),
    string_integer(Sub4, D5),
    string_integer(Sub5, D6),
    string_integer(Sub6, D7),
    string_integer(Sub7, D8),
    string_integer(Sub8, D9),
    0 is mod(D2, 2),
    0 is mod(D3, 3),
    0 is mod(D4, 5),
    0 is mod(D5, 7),
    0 is mod(D6, 11),
    0 is mod(D7, 13),
    0 is mod(D8, 17).

% prédicat qui vérifie si un nombre est pandigital
pandigital(Nombre) :-
    atom_chars(Nombre, Chars),
    sort(Chars, [0,1,2,3,4,5,6,7,8,9]).
    
% prédicat qui extrait une sous-chaîne à partir d'une position donnée
sous_chaine(Chaine, Position, Taille, SousChaine) :-
    sub_atom(Chaine, Position, Taille, _, SousChaine).   %string, start, length, end, substring

% prédicat qui convertit une chaîne en un entier
string_integer(Chaine, Entier) :-
    atom_number(Chaine, Entier).

% prédicat qui affiche le résultat

