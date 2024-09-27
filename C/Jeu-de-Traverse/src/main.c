/*!
 * \file main.c
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief fonction princpale
 *
 *
 */

// Inclusion des librairies
#include "tableau.h"
#include "jeu.h"

//Code de la fonction

int main(void) {
  int choix; //choix de l'utilisateur
  printf("Que voulez-vous faire ?\n1-Faire une partie Joueur contre Joueur\n2-Faire une partie Joueur contre Ordi\n3-Lancer le jeu test\n");
  choix = saisirEntier();
  switch (choix) {
    case 1 :
      //pour lancer une partie "Joueur-Joueur"
      partieJJ();
      break;
    case 2 :
      //pour lancer une partie "Joueur-Ordinateur"
      partieJO();
      break;
    case 3 :
      //pour lancer une partie "Ordinateur-Ordinateur"
      partieOO();
      break;
    default :
      printf("Erreur\n");
      break;
  }
  return 0;
}
