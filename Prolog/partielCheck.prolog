:- use_module(library(clpfd)).


%PREDICATS OUTILS
liste_longueur([],0).
liste_longueur([T1|R1], N):-
    liste_longueur(R1, M),
    N #= M+1.



liste_liste_concatenation([], L , L).
liste_liste_concatenation(L, [], L).
liste_liste_concatenation([] , [] , []).
liste_liste_concatenation([T1|R1], L2, [T1|R3]):-
    liste_liste_concatenation(R1,L2,R3).

indice_factorielle(0, 1).
indice_factorielle(1, 1).
indice_factorielle(I, F) :-
    I #> 1,
    J is I - 1,
    indice_factorielle(J, F2),
    F #= I * F2.

indice_terme(0,1).
indice_terme(I,T):-
    J1 #= I * 2,
    J3 #= I + 1,
    indice_factorielle(J1, Num),
    indice_factorielle(I, Den1),
    indice_factorielle(J3,Den2),
    T #= Num // (Den1 * Den2).