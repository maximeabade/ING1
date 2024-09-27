/*!
\file tableau.h
\brief header des fonctions pour créer des tableaux
\author Justine Ribas <ribasjusti@eisti.eu>
\version 0.1
\date 13 décembre 2019
*/

#ifndef __TABLEAU_H__
#define __TABLEAU_H__

 // Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "saisie.h"

/**
 *\fn int* creerTabEntier1D(int n)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 13 décembre 2019
 *
 *\brief permet de créer un tableau à une dimension
 *
 *
 *\param n la taille du tableau
 *\return tab l'adresse de la première case du tableau crée
 *
 */
int* creerTabEntier1D(int n);

/**
 *\fn void afficherTab(int* tab, int n)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 19 février 2020
 *
 *\brief permet d'afficher un tableau à une dimension
 *
 *
 *\param tab le tableau à afficher
 *\param n la taille du tableau
 *
 */
void afficherTab(int* tab, int n);


/**
 *\fn void InitTab(int* tab, int n)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 17 mars 2020
 *
 *\brief permet d'initialiser un tableau avec des valeurs aléatoires
 *
 *
 *\param tab le tableau à initialiser
 *\param n la taille du tableau
 *
 */
void InitTab(int* tab, int n);

/**
 *\fn void CopierTab(int* tab1, int* tab2, int n)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 17 mars 2020
 *
 *\brief permet de copier un tableau
 *
 *
 *\param tab1 le tableau à copier
 *\param tab2 la copie
 *\param n la taille du tableau
 *
 */
void CopierTab(int* tab1, int* tab2, int n);

int* copierSousTableau(int* tab, int debut, int fin);




#endif
