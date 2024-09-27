/*! \file fichier.c
 *
 * \autor Ribas Justine et Legrand Amandine
 * \version 0.1
 * \date 07 janvier 2020
 *
 *\brief le fichier qui contient les définitions de toutes les méthodes relatives aux manipulations de fichiers
 *
 *
 */

// Inclusion des entêtes de librairies
#include "fichier.h"

// Fonction qui ouvre un fichier avec les bon droits
FILE *chargerFichier(char *tchar_nomFichier, char *droits)
{
  FILE *fichier; //le fichier qui sera ouvert

  fichier = NULL;

  //ouverture de l'image avec les bon droits
  fichier = fopen(tchar_nomFichier, droits);
  if (fichier == NULL) {
		// Si pb alors on affiche un message
		printf("Problème d'ouverture du fichier (%s) : %s\n", tchar_nomFichier, strerror(errno));
		// et on quitte
		exit(ERREUR_SYS);
	}

  //retourner l'image chargé
  return(fichier);
}

// Procedure qui ferme un fichier
void fermerFichier(FILE *fichier)
{
  //DECLARATION DES VARIABLES
  int int_retour;
  //FERMER LE FICHIER
  int_retour = fclose(fichier);
  //GERER LE CAS D'ERREUR
  if (int_retour == EOF) {
    fprintf (stderr, "Problème de fermeture du fichier : %s\n", strerror (errno));
    exit(-1);
  }
}

//procedure qui écrit un entier dans un fichier
void ecrireEntier(int entier, FILE* fichier)
{
  int i; //parcours les puissances

  for(i = 7 ; i >= 0 ; i--){
    if((int)pow(2.00, (double)i) <= entier){
      entier -= (int)pow(2.00, (double)i);
      fputc('1', fichier);
    }
    else fputc('0', fichier);
  }
}

//fonction qui lit un entier dans un fichier
int lireEntier(FILE* fichier)
{
  int i; //parcours les puissances
  int entier; //l'entier qui sera lu

  entier = 0;

  for(i = 7 ; i >= 0 ; i--){
    if(fgetc(fichier) == '1'){
      entier += (int)pow(2.00, (double)i);
    }
  }

  return(entier);
}
