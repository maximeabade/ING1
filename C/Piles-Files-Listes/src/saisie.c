/*!
 * \file saisie.h
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 13 décembre 2019
 *
 * \brief définition des méthodes de saisie
 *
 *
 */

 // Inclusion des entêtes de librairies
#include "saisie.h"


// Codes des fonctions

int saisirEntier(void)
{
  int int_nbrSaisi; //le nombre qui sera saisie
  printf("Veuillez saisir un entier : ");
  while (!scanf("%d", &int_nbrSaisi)) {
    //on vide le buffer pour eviter une boucle infini
    viderBuffer();
    printf("Erreur lors de la saisie ! Veuillez entrer un entier :");
  }
  return(int_nbrSaisi);
}

void viderBuffer(void)
{
  char char_saisie; //le caracère courant dans le buffer
  scanf("%c", &char_saisie);
  while (char_saisie!='\n') {
    scanf("%c", &char_saisie);
  }
}
