:- use_module(library(clpfd)).

%Exo1 - Liste

concat([],L,L).
concat(L,[],L).

concat([X|L],L2,R):- %ici X est la tete de L, L2, la 2nde liste et R la sortie
    concat(L,L2,RL), %on concatene L et L2 dans RL, 
    R #= [X|RL].    %puis on definit la sortie comme etant la liste ayant comme tete X et RL queue

concat_bis(L1,L2L3):- append(L1,L2,R).  %la fonction append concatene 2 listes dans une sortie

%Exo2 - Nombre de Lychrel
%On ne sait pas inverser des chiffres directement, mais on sait inverser les elt dune liste

to_list(0,[]).

to_list(N,R):- %on prend en entree un nombre et on le divise par puissance de 10, 
    N>0,        %l'affectant a chaque fois a une variable, on recup le reste dans M
    M #= N mod 10, %puis on recupere le quotient, et on le stock dans Q. 
    Q #= N div 10, %On rappelle ensuite to_list recursivement dans RR, 
    to_list(Q,RR), %et on renvoie en sortie la liste ayant comme tete les restes successifs 
    R = [M|RR]. %de N par 10, et comme queue la liste des quotients.

%Attention! ici la liste est dores et deja inversee!!

to_number([],0).

to_number(L,RR):-
    R #= RR*10+X.

ly(N,I):-
    I>=0,
    N #= to_list(N,L),
    reverse(L,L).

ly(N,I):-
    I>0,
    to_list(N,L1),
    reverse(L1,L2),
    to_number(L2,N2),
    S #= N+N2,
    IM1 #= I-1,
    ly(S,IM1).


%Exo4 - Nombre Pandigitaux

pandigital(N):-
    to_list(N,IL),
    reverse(IL,L),
    L ins 0..9,
    all_distinct(L),
    contrainte(2,L,2),
    contrainte(3,L,3),
    contrainte(4,L,5),
    contrainte(5,L,7),
    contrainte(6,L,11),
    contrainte(7,L,13),
    contrainte(8,L,17),


contrainte(I1,L,N):-
    nth1(I1,L,D2),
    I2 #= I1 + 1,
    nth1(I2,L,D3),
    I3 #= I2 + 1,
    nth1(I3,L,D4),
    to_number([D4,D3,D2],N1),
    N1 mod N #= 0





%Exam Rattrapage 2020-2021


%Modelisation

listeModelisation([[]]).

listeModelisation([[X|Q]]) :-
    listeModelisation([[Q|L]]),
    X = n ; X = b.
