
%graphe%
origine_destination_cout(a,b,2).
origine_destination_cout(a,g,6).
origine_destination_cout(b,e,2).
origine_destination_cout(b,c,7).
origine_destination_cout(g,e,1).
origine_destination_cout(g,h,4).
origine_destination_cout(e,f,2).
origine_destination_cout(f,c,3).
origine_destination_cout(f,h,2).
origine_destination_cout(c,d,3).
origine_destination_cout(h,d,2).



chemin(X,Y,Chemin) :- 
    origine_destination_cout(X,Y,_),
    Chemin = sol(X,Y).

chemin(X,Y,Chemin) :-
    origine_destination_cout(X,Z,_),
    chemin(Z,Y,Chemin2),
    Chemin = sol(X,Chemin2).


istree(t(_,_,nil)).
istree(t(_,nil,_)).
istree(t(_,TL,TR)) :- 
    istree(TL),
    istree(TR).


sym(nil).
sym(t(_,nil,nil)).
sym(t(_,t(_,TL1,TR1),t(_,TL2,TR2))) :- 
    sym((t(_,TL,TL2))),
    sym((t(_,TR,TR2))).

use_module(library(clpfd)).


chemin_liste(X,Y,Chemin) :-
    origine_destination_cout(X,Y,_),
    Chemin=[X,Y].

chemin_liste(X,Y,Chemin) :-
    origine_destination_cout(X,Z,Chemin2),
    Chemin=[X|Chemin2].


createListe(L,Nblist,NbElt):-
    length(L,NbList),
    createListe(R,NbElt).

createListe([],_).


createListe([L1|R],NbElt):-
    length(L1,NbElt),
    createListe(R,NbElt).



/*
Enigme d'Einstein
*/

einstein(Struct):-
    createListe(Struct,5,5),
    /*Règle1*/
    nth1(1,Struct,M1),%[_,norvegien,_,_,_]),
    %ou alors
    nth1(2,M1,norvegien),


    /*Règle2*/
 
    nth1(2,Struct,M2),
    nth1(1,M2,bleue),



    /*Règle3*/

    nth1(3,Struct,M3),
    nth1(4,M3,Lait),

    /*Règle4*/
    member(MA,Struct),
    nth1(2,MA,anglais),
    nth1(1,MA,rouge),


    /*Règle5*/
    member(MV,Struct),
    n,th1(4,MV,cafe),

    /*Règle6*/
    member(MJ,Struct),
    nth1(5,MJ,kool),

    /*Règle7*/
    member(MB,Struct),
    Suivant(MB,MV,Struct),

    /*Règle8*/
    member([_,espagnol,chien,_,_],Struct),

    /*Règle9*/
    member([_,ukrainien,_,the,_],Struct),

    /*Règle10*/
    member([_,japonais,_,_,craven],Struct),

    /*Règle11*/
    member([_,_,escargot,_,oldgold]),
 
    /*Règle12*/
    member([_,_,_,vin,gitane]),

    /*Règle13*/
    voisin(V1,V2),
    nth1(5,V1,chesterfield),
    nth1(3,V2,renard)

    /*Règle14*/
    voisin(V3,V4),
    nth1(5,V3,kool),
    nth1(3,V4,cheval),


    /*Règle0 Qui boit de l'eau   et qui a un zèbre*/
    member([_,_,_,eau,_],S),
    member([_,_,zebre,_,_],S),

. 




voisin(MI,MJ,Struct):-
    suivant(MJ,MI,Struct).

suivant(MI,MJ,Struct):-
    nth1(I,Struct,MI),
    nth1(J,Struct,MJ),
    I #= J+1.



/*POUR TROUVER LE DERNIER ELEMENT D UNE LISTE*/
/*avec des fonctions predefinies*/

my_last(X,L):-
    length(L,N),
    nth1(N,L,X).


/*recursivite*/
/*cas d'arret : il n'y a qu'un seul élément dans la liste*/

my_last_recursi(X,[X]).
my_last_recursi(X,[_|L]):- /*le [_|L] appelle le reste de la liste avec un élément de moins que la liste de base*/
    my_last_recursi(X,L).




/*POUR TROUVER L AVANT DERNIER ELEMENT D UNE LISTE*/


my_last_but_one(X,L):-
    length(L,N),
    NM1 #= N-1,
    nth1(NM1,L,X).

my_last_but_one_recursi(X,[X,_]).
my_last_but_one_recursi(X,[_|L]):-
    my_last_but_one_recursi(X,L).




/*POUR REVERSE UNE LISTE*/

/*je pense a prendre deux listes*/
/*et a chque fois appeler les fonctions deja definies pour appeler les restes de liste*/


my_reverse([],[]). /*cas d arret, une liste vide renverra une autre liste vide*/
my_reverse([H|Q],L):-   /*le H c est la tete de la liste, le Q c est le reste (QUEUE)*/
    my_reverse(Q,RQ),
    add_last(H,RQ,L).

add_last(H,[],[H]).
add_last(H,[X|L],[X|RL]):-
    add_last(H,L,RL).



my_reverse_v2(L,R):-
    length(L,N),
    length(R,N),
    my_rev_rec(N,N,L,R).


my_rev_rec(0,_,_,_).
my_rev_rec(I,N,L,R):-
    nth1(I,L,X),
    NMI #= N-I+1,
    nth1(NMI,R,X),
    IM1 #= I-1,
    my_rev_rec(IM1,N,L,R).


my_reverse_v3([],[]).
my_reverse_v3([H|Q],L):-
    my_reverse(Q,RQ),
    append(RQ,[H],L).


my_reverse_v4(L,R):-
    my_reverse_accumulateur(L,R,[]).

my_reverse_accumulateur([],R,Acc):-
    R = Acc.

my_reverse_accumulateur([H|Q],R,Acc]):-
    my_reverse_accumulateur(Q,R,[H|Acc]).


palindrome(L) :- reverse(L,L).   /*palindrome definit une liste qui se lit dans les deux sens, genre 121 */










/*RUN LENGTH ENCODING*/


compress([],[]).
compress([X],[X]).              /*les cas d arret, c est des listes qui vont etre inchangees*/


compress([X,X|L],R):-
    compress([X|L],R).          /*si c est egal, on fait un appel recursif sur X|L */

compress([X,Y|L],[X|R]):-
    X \= Y,
    compress([Y|L],R).


