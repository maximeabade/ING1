/*!
 * \file main.c
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 31 mars 2020
 *
 * \brief fonction principale
 *
 *
 */

// Inclusion des entêtes de librairies
#include "saisie.h"
#include "listes.h"

// Fonction principale
int main (void)
{
  s_liste* liste;
  int action; //action choisie par l'utilisateur
  int choix; //le choix parmi les différentes actions
  int nbr;
  int position;
  int taille;
  liste = initListe();
  taille = 0;
  do {
    printf("\nQue voulez-vous faire ?\n1-Ajouter un élément dans la liste\n2-Supprimer un élément de la liste\n3-Rechercher un élément de la liste\n4-Inverser la liste\n5-Rattacher la liste à elle-même\n6-Quitter le programme\n\n\n");
    action = saisirEntier();
    switch (action) {

      /*Ajout d'un élément*/
      case 1 : printf("\nQuel élément voulez-vous insérer ?\n");
      nbr = saisirEntier();
      printf("L'élément sera inséré :\n1-En tête de liste\n2-En fin de liste\n3-A une position donnée de la liste\n");
      choix = saisirEntier();
      switch (choix) {
        /*En tête*/
        case 1 : cons(liste, nbr);
        afficherListe(liste);
        taille++;
        break;
        /*A la fin*/
        case 2 : rcons(liste, nbr);
        afficherListe(liste);
        taille++;
        break;
        /*Position donnée*/
        case 3 : printf("\nA quelle position voulez vous ajouter cet élément ?\n");
        do {
          position = saisirEntier();
        } while (position < 0  &&  position > taille);
        ajouter(liste, nbr, position);
        afficherListe(liste);
        taille++;
        break;

        default : printf("erreur\n");
        break;
      }
      break;

      /*Suppression d'un élément*/
      case 2 : printf("\nOù voulez-vous supprimer un élément ?\n1-En tête de liste\n2-En fin de liste\n3-A une position donnée\n4-La première occurence d'une valeur\n5-Toutes les occurences d'une valeur\n6-Les doublons\n\n");
      choix = saisirEntier();
      switch (choix) {
        /*En tête*/
        case 1 : suppDeb(liste);
        afficherListe(liste);
        taille--;
        break;
        /*En fin*/
        case 2 : suppFin(liste);
        afficherListe(liste);
        taille--;
        break;
        /*A une position donnée*/
        case 3 : printf("\nA quelle position voulez vous supprimer élément ?\n\n");
        do {
          position = saisirEntier();
        } while (position < 0  &&  position > taille-1);
        supprimer(liste, position);
        afficherListe(liste);
        taille--;
        break;
        /*La première occurence d'une valeur*/
        case 4 : printf("Quelle valeur voulez-vous supprimer ?\n");
        nbr = saisirEntier();
        removeFirst(liste, nbr);
        afficherListe(liste);
        taille--;
        break;
        /*Toutes les occurences d'une valeur*/
        case 5 : printf("Quelle valeur voulez-vous supprimer ?\n");
        nbr = saisirEntier();
        taille = taille - removeAll(liste, nbr);
        afficherListe(liste);
        break;
        /*Les doublons*/
        case 6 : taille = taille - suppDoublon(liste);
        afficherListe(liste);
        break;

        default : printf("erreur\n");
        break;
      }
      break;

      /*Recherche d'un élément*/
      case 3 : printf("Quel élément recherchez-vous ?\n");
      nbr = saisirEntier();
      position = rechercher(liste, nbr);
      if (position == -1){
        printf("Ce nombre n'est pas dans votre liste...\n");
      } else {
        printf("Ce nombre se trouve à la position %d de la liste\n", position);
      }
      break;

      /*Inverser la liste*/
      case 4 : liste = mirror(liste);
      afficherListe(liste);
      break;

      /*Rattacher la liste à elle-même*/
      case 5 : rattacher(liste);
      afficherListe(liste);
      break;

      case 6 : printf("Fin du programme\n");

      
      default : printf("erreur\n");
      break;
    }
  } while (action != 6);
  free(liste);
  return(0);
}
