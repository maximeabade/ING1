/*!
\file fichier.h
\autor Jalbert Sylvain
\version 1
\date 07 janvier 2020
\brief le fichier qui contient les déclarations de toutes les méthodes relatives aux manipulations de fichiers
*/

#ifndef __FICHIER_H_
#define __FICHIER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "tableau.h"

/*! \def ERREUR_SYS
 *  Constante pour définir une terminaison par erreur
 *  système
 */
#define ERREUR_SYS -1

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
FILE *chargerFichier(char *tchar_nomFichier, char *droits);

#endif
