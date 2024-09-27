/*!
\file tableau.c
\autor Jalbert Sylvain
\version 1
\date 16 mars 2020
\brief le fichier qui contient les définitions de toutes les méthodes relatives aux manipulations de tableau
*/

#include "tableau.h"

/*!
\fn void affichage ( int ttint_plateau[N][N] )
\author Jalbert Sylvain
\version 0.1 Premier jet
\date 16 mars 2020
\brief une procedure qui affiche la grille passé en paramettre
\param ttint_plateau[N][N] tableau de tableau d'entier
*/
void affichage(int ttint_plateau[N][N]){
  //DECLARATION DES VARIABLES
  int int_i; //variables qui va parcourir les indice des lignes du tableau
  int int_j; //variables qui va parcourir les indice des colonnes du tableau

  //AFFICHAGE DE LA GRILLE
  //parcour de chaque lignes
  for(int_i = 0 ; int_i < N ; int_i++){
    //affichage du séparateur
    //affichage du décalage du séparateur
    printf(" ");
    //affichage du séparateur de longeur N
    for(int_j = 0 ; int_j < N ; int_j++){
      printf("+----");
    }
    //affichage du dernier caractère du séparateur + retour ligne
    printf("+\n ");
    //parcour de chaque case de la ligne
    for(int_j = 0 ; int_j < N ; int_j++){
      //afficher un séparateur et la valeur de la case
      if(ttint_plateau[int_i][int_j]>=10){
        printf("| %d ", ttint_plateau[int_i][int_j]);
      }
      else{
        printf("|  %d ", ttint_plateau[int_i][int_j]);
      }
    }
    //afficher le dernier separateur de colonne + fin de la ligne
    printf("|\n");
  }
  //afficher le dernier separateur de ligne
  //affichage du décalage du séparateur
  printf(" ");
  //affichage du séparateur de longeur N
  for(int_j = 0 ; int_j < N ; int_j++){
    printf("+----");
  }
  //affichage du dernier caractère du séparateur + retour ligne
  printf("+\n ");
}
