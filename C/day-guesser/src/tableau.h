/*!
\file tableau.h
\autor Jalbert Sylvain
\version 1
\date 16 mars 2020
\brief le fichier qui contient les déclarations de toutes les méthodes relatives aux manipulations de tableau
*/

#ifndef __TABLEAU_H_
#define __TABLEAU_H_

//onutilise la librairie utile ici pour la gestion de la mémoire et des "exit"
#include <stdlib.h>
//on utilise la librairie utile pour les interactions avec l'utilisateur
#include <stdio.h>


#define ERREUR_ALLOCATION 1
#define N 4

/*!
\fn void affichage ( int ttint_plateau[N][N] )
\author Jalbert Sylvain
\version 0.1 Premier jet
\date 16 mars 2020
\brief une procedure qui affiche la grille passé en paramettre
\param ttint_plateau[N][N] tableau de tableau d'entier
*/
void affichage(int ttint_plateau[N][N]);

#endif
