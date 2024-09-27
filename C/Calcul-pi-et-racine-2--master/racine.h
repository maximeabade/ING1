/*!
\file racine.h
\brief l'en-tête des fonctions permettant de calculer la valeur de la racine carrée de 2
\author Justine Ribas <ribasjusti@cy-tech.fr>
\version 0.1
\date 22 novembre 2021
*/

#ifndef RACINE_H
#define RACINE_H

/*inclusion des entêtes de librairie*/
#include "saisie.h"


/*Déclaration des fonctions*/


/**
* \fn float methodeNewton(int int_n)
* \brief permet de calculer une approximation de la racine carrée de 2 avec la méthode d'Isaac Newton
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 22 novembre 2021
*
* \param int_n le niveau de précision
*
* \return la valeur de pi
*/
float methodeNewton(int int_n);


/**
* \fn float methodeHalley(int int_n)
* \brief permet de calculer une approximation de la racine carrée de 2 avec la méthode d'Edmund Halley
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 22 novembre 2021
*
* \param int_n le niveau de précision
*
* \return la valeur de pi
*/
float methodeHalley(int int_n);


/**
* \fn float methodeSmyrne(int int_n)
* \brief permet de calculer une approximation de la racine carrée de 2 avec la méthode de Théon de Smyrne
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 22 novembre 2021
*
* \param int_n le niveau de précision
*
* \return la valeur de pi
*/
float methodeSmyrne(int int_n);


/**
* \fn void menuRacine(void)
* \brief permet d'afficher le menu et d'appeler les fonctions pour calculer une approximation de la racine carrée de 2
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 22 novembre 2021
*/
void menuRacine(void);

#endif