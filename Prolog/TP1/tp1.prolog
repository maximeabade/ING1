homme(albert).
homme(jean).
homme(paul).
homme(bertrand).
homme(louis).
homme(benoit).


femme(germaine).
femme(christiane).
femme(simone).
femme(marie).
femme(sophie).


pere_enfant(albert,jean).   % nommer les prédicats arg1_arg2_..._argn donc NE PAS avoir un prédicat pere(arg1,arg2)
pere_enfant(jean,paul).
pere_enfant(paul,bertrand).
pere_enfant(paul,sophie).
pere_enfant(jean,simone).
pere_enfant(louis,benoit).



mere_enfant(germaine,jean).
mere_enfant(christiane,simone).
mere_enfant(christiane,paul).
mere_enfant(simone,benoit).
mere_enfant(marie,bertrand).
mere_enfant(marie,sophie).



parent_enfant(X,Y) :- pere_enfant(X,Y);mere_enfant(X,Y).
fils_parent(X,Y) :- homme(X),parent_enfant(Y,X).
fille_parent(X,Y) :- femme(X),parent_enfant(Y,X).
grandPere_petitEnfant(X,Y) :- homme(X),parent_enfant(X,Z),parent_enfant(Z,Y).
grandMere_petitEnfant(X,Y) :- femme(X),parent_enfant(X,Z),parent_enfant(Z,Y).
frere_frereOuSoeur(X,Y) :- homme(X),parent_enfant(Z,X),parent_enfant(Z,Y).
soeur_frereOuSoeur(X,Y) :- femme(X),parent_enfant(Z,X),parent_enfant(Z,Y).



aime(marie,vin). %on aurait pu mettre aime_estAime(marie,vin). pour être plus précis et respecter la nomenclature conseillée pour les prédicats%
%on aurait aussi pu ecrire un autre predicat a 0 parametre car seule marie aime le vin, elle ne fait qu'aimer le vin, et seul le vin est aimé, donc marie_aime_vin.%
aime(pierre,X) :- aime(X,vin). %ce que pierre aime, c'est ce qui aime le vin  (si predicat droite, alors predicat gauche)%  
estVoleur(pierre).
%si qqn est voleur et qu il aime qqchose, alors il vole ce qu'il aime%
vole(X,Y) :- estVoleur(X),aime(X,Y). %quand on lit, le "si" se met dans le prediact de droite(right hand), et le "alors" dans le predicat de gauche(left hand)%
estVole(X,Y) :- vole(X,Y).
%Pierre se retrouve à voler l'objet marie%
qui_vole_quoi :- 
    vole(X,Y),
    open(toto,append,Stream),
    write(Stream,X),write(Stream,' vole '),write(Stream,Y),nl,
    close(Stream).



%les arcs%
arc(a,b,2).
arc(a,g,6).
arc(b,e,2).
arc(b,c,7).
arc(g,e,1).
arc(g,h,4).
arc(e,f,2).
arc(f,c,3).
arc(f,h,2).
arc(c,d,3).
arc(h,d,2).
chemin(X,Y) :- arc(X,Y,_).
chemin(X,Y) :- arc(X,Z,_),chemin(Z,Y).
%les listes pour définir les chemins de X à Y%
chemin(X,Y,[X,Y]) :- arc(X,Y,_). %cas d arret%
chemin(X,Y,[X|L]) :- arc(X,Z,_),chemin(Z,Y,L).
length(C,_),chemin(X,Y,C).

%si on a un cycle ca pue car stack overflow%
%pour eviter ca on cree un iterateur sur la liste%