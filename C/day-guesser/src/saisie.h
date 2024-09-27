/*!
\file saisie.h
\autor Jalbert Sylvain
\version 1
\date 16 mars 2020
\brief le fichier qui contient les déclarations de toutes les méthodes relatives à la saisie
*/

#ifndef __SAISIE_H_
#define __SAISIE_H_

//on utilise la librairie utile pour les interactions avec l'utilisateur
#include <stdio.h>

/*!
\fn void viderBuffer ( void )
\author Jalbert Sylvain
\version 0.1 Premier jet
\date 16 mars 2020
\brief une procedure qui va vider le buffer
*/
void viderBuffer(void);

/*!
\fn int saisirEntier ( void )
\author Jalbert Sylvain
\version 0.1 Premier jet
\date 16 mars 2020
\brief une fonction qui renvoie un entier saisie par l'utilisateur
\return l'entier saisie par l'utilisateur
*/
int saisirEntier();

#endif
