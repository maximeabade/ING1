/*! \file fichier.h
 *
 * \author Justine Ribas et Legrand Amandine
 * \version 0.1
 * \date 07 janvier 2020
 *
 * \brief header des fonctions pour gérer un fichier
 *
 *
*/

#ifndef __FICHIER_H__
#define __FICHIER_H__

// Inclusion des entêtes de librairie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

// Déclarartion des constantes

/*! \def ERREUR_SYS
 *  Constante pour définir une terminaison par erreur
 *  système
 */
#define ERREUR_SYS -1


// Déclarartion des fonctions et procédures

/**
 * \fn FILE* chargerFichier(char* tchar_nomFichier, char* droits)
 *
 * \author Ribas Justine <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 07/01/2020
 *
 * \brief Fonction pour ouvrir un fichier avec les droits donnés en paramètres
 *
 *
 * \param tchar_nomFichier le nom du fichier à ouvrir
 * \param droits le ou les droits que l'on veut donner au programme sur le fichier
 * \return le pointeur vers le fichier ouvert
 *
 */
FILE* chargerFichier(char* tchar_nomFichier, char* droits);

/**
 * \fn void fermerFichier(FILE *fichier)
 *
 * \author Ribas Justine <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 07 janvier 2020
 *
 * \brief la procedure qui ferme un fichier donné en parametre
 *
 * \param fichier le fichier à fermer
 *
 */
void fermerFichier(FILE *fichier);

/**
 * \fn void ecrireEntier(int entier, FILE* fichier)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 13 janvier 2020
 *
 * \brief la procedure qui écrit un entier dans un fichier
 *
 * \param entier l'entier à écrire
 * \param fichier le fichier dans lequel on écrit
 *
 */
void ecrireEntier(int entier, FILE* fichier);

/**
 * \fn int lireEntier(FILE* fichier)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 13 janvier 2020
 *
 * \brief la procedure qui lit un entier dans un fichier
 *
 * \param fichier le fichier dans lequel on lit
 * \return l'entier lu
 *
 */
 int lireEntier(FILE* fichier);

#endif
