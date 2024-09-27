% on se rends compte qu'on a 25 variables donc on s'imagine une structure de 
% donnée sous forme de matrice => 5 listes de 5 variables

% on reprend ce qu'il y a sur la diapo 25 :
createListe(L,NbLst,NbElt):-length(L,NbLst), createListe(L,NbElt).
createListe([],_).
createListe([L1|R],NbElt):-length(L1,NbElt), createListe(R,NbElt).

einstein(S):- 
    createListe(S,5,5),
    %1
    nth1(1,S,M1),
    nth1(2,M1,norvegien),
    %2
    voisin(S,M1,M2),
    nth1(1,M2,bleue),
    %3
    nth1(3,S,M3),
    nth1(4,M3,lait),
    %4
    member(Manglais,S),
    nth1(1,Manglais,rouge),
    nth1(2,Manglais,anglais),
    %5
    member([verte,_,_,cafe,_],S),
    %6
    member([jaune,_,_,_,kool],S),
    %7
    suivant(S,[blanche,_,_,_,_],[verte,_,_,_,_]),
    %8
    member([_,espagnol,chien,_,_],S),
    %9
    member([_,ukrainien,_,the,_],S),
    %10
    member([_,japonais,_,_,craven],S),
    %11
    member([_,_,escargot,_,oldGold],S),
    %12
    member([_,_,_,vin,gitane],S),
    %13
    voisin(S,[_,_,_,_,chesterfield],[_,_,renard,_,_]),
    %14
    voisin(S,[_,_,_,_,kool],[_,_,cheval,_,_]),
    %pour la question :
    member([_,_,_,eau,_],S),
    member([_,_,zebre,_,_],S)
    .

:-use_module(library(clpfd)).
voisin(S,MI,MJ):-
    nth1(I,S,MI),
    nth1(J,S,MJ),
    I#=J+1.

voisin(S,MI,MJ):-
    nth1(I,S,MI),
    nth1(J,S,MJ),
    I#=J-1.

suivant(S,MI,MJ) :-
    nth1(I,S,MI),
    nth1(J,S,MJ),
    I#=J+1.
