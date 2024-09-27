/*!
 * \file tableau.c
 *
 * \author Justine Ribas <ribasjusti@cy-tech.fr>
 * \version 0.1
 * \date 09 décembre 2021
 *
 * \brief fonctions pour créer des tableau
 *
 *
 */

//Inclusion des entêtes de librairies
#include"tableau.h"


// Codes des fonctions

// Fonction qui créer un tableau de cases à deux dimensions
struct_case** creerPlateau(int int_n)
{
  // Déclaration des variables
  struct_case** ppcase_plateau; //tableau d'entiers
  int int_i; //iterrateur de boucle

  // On alloue la mémoire pour le tableau
  ppcase_plateau = malloc(int_n*sizeof(struct_case*));
  if(ppcase_plateau==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
  }

  // On alloue la mémoire pour chaque case du tableau
  for(int_i = 0; int_i < int_n; int_i ++){
    ppcase_plateau[int_i] = malloc(int_n*sizeof(struct_case));
    if(ppcase_plateau==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
    }
  }

  return(ppcase_plateau);
}

// Fonction qui libère l'espace mémoire alloué pour un tableau de cases à deux dimensions
void freeTab2D(struct_case** ppcase_plateau, int int_n)
{
  // Déclaration des variables
  int int_i; //iterrateur de boucle

  // On libère la mémoire allouée pour chaque sous tableau
  for(int_i = 0; int_i < int_n; int_i ++){
    free(ppcase_plateau[int_i]);
  }
  free(ppcase_plateau);
}

