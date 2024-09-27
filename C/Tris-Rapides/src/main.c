/*!
 * \file main.c
 *
 * \autor Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 17 mars 2020
 *
 * \brief fonction principale
 *
 *
 */

 //Inclusion des entêtes de librairies
 #include "tris.h"
 #include "tableau.h"
 #include "saisie.h"
 #include "fichier.h"
 #include <stdio.h>
 #include <stdlib.h>

/*Question 6*/

int main(void){
  FILE* fichier;
  int* tab; //tableau d'entiers
  int n; //la taille des tableaux
  printf("Quelle est la taille du tableau ?\n");
  do {
    n=saisirEntier();
  } while (n<=1);
  tab=creerTabEntier1D(n);
  InitTab(tab, n);
  system("clear");
  printf("Voici votre tableau : \n");
  afficherTab(tab, n);

  fichier = chargerFichier("times.csv", "w");
  triSelection(tab, n, fichier);
  triBulle(tab, n, fichier);
  triInsertion(tab, n, fichier);
  triRapide(tab, n, fichier);
  triFusion(tab, n, fichier);
  trisShell(tab, n, fichier);
  fclose(fichier);
  free(tab);
  return(0);
}
