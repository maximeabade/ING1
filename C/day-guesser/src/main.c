/*!
\file main.c
\autor Jalbert Sylvain
\version 1
\date 16 mars 2020
\brief fichier principal du programme qui permet à l'utilisateur de faire le tour de magie
*/

#include <math.h>
#include "tableau.h"
#include "saisie.h"
#define NBRGRILLE 5

/*!
\fn int main ( int argc, char∗∗ argv )
\author Jalbert Sylvain
\version 0.1 Premier jet
\date 16 mars 2020
\brief la fonction principale qui permet à l'utilisateur de faire le tour de magie
\param argc nombre d’arguments en entree
\param argv valeur des arguments en entree
\return 0 si tout c'est bien passé
*/
int main (int argc, char** argv){
  //DECLARATION DES VARIABLES
  int int_resultat; //le nombre qui sera trouvé
  int int_reponse; //la reponse aux questions
  int int_puissance;
  int int_i; //va parcourir chaques grilles
  int int_j; //va servir au calcul de puissance
  int ttint_grille[NBRGRILLE][N][N] = {{{3,7,23,19},{17,9,11,31},{5,27,21,13},{1,25,29,15}},
                                      {{14,26,10,27},{3,30,15,18},{31,6,19,23},{2,7,11,22}},
                                      {{6,5,20,14},{28,23,15,13},{31,29,21,22},{4,30,7,12}},
                                      {{14,10,15,31},{11,27,29,13},{26,28,9,12},{8,30,25,24}},
                                      {{17,23,29,25},{27,30,29,18},{22,21,26,24},{16,28,31,20}}};

  //INITIALISATION DES VARIABLES
  int_resultat = 0;

  //DEROULEMENT DU TOUR
  for(int_i = 0 ; int_i<NBRGRILLE ; int_i++){
    system("clear");
    //afficher la grille courante
    affichage(ttint_grille[int_i]);
    //demander si le nombre est dans la grille
    printf("Votre numéro se trouve-t-il dans cette grille ? (0-non, 1-oui)  :  ");
    //recuperer la saisie
    int_reponse = saisirEntier();
    while(int_reponse != 1 && int_reponse != 0){
      printf("Veuillez saisir 0 pour \"non\" ou 1 pour \"oui\"  :  ");
      int_reponse = saisirEntier();
    }
    if(int_reponse == 1){
      //calcul de 2 puissance int_i
      int_puissance = 1;
      for (int_j = 0; int_j < int_i; int_j++) {
        int_puissance = int_puissance * 2;
      }
      //maj du résultat
      int_resultat += int_puissance;
    }
  }

  //AFFICHER LE RESULTAT
  system("clear");
  printf("Résultat trouvé !\nVous pensez au nombre %d.\n", int_resultat);


  //Fin du programme, Il se termine normalement, et donc retourne 0
  return(0);
}
