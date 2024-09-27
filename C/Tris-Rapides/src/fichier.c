/*!
\file fichier.c
\autor Jalbert Sylvain
\version 1
\date 07 janvier 2020
\brief le fichier qui contient les définitions de toutes les méthodes relatives aux manipulations de fichiers
*/
#include "fichier.h"

/*!
\fn FILE *chargerFichier(char *tchar_nomFichier, char *droits)
\author Jalbert Sylvain
\version 0.1 Premier jet
\date 07 janvier 2020
\brief la fonction qui charge un fichier avec les droits donné en parametre
\param tchar_nomFichier le nom du fichier à ouvrir
\param droits le ou les droits que l'on veut donner au programme sur le fichier
\return le pointeur vers le fichier ouvert
*/
FILE *chargerFichier(char *tchar_nomFichier, char *droits){
  FILE *file_image; //l'image qui sera ouverte

  file_image = NULL;

  //ouverture de l'image avec les bon droits
  file_image = fopen(tchar_nomFichier, droits);
  if (file_image == NULL) {
		// Si pb alors on affiche un message
		printf("Problème d'ouverture du fichier (%s) : %s\n", tchar_nomFichier, strerror(errno));
		// et on quitte
		exit(ERREUR_SYS);
	}

  //retourner l'image chargé
  return(file_image);
}
