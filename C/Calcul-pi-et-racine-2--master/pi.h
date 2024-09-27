/*!
\file pi.h
\brief l'en-tête des fonctions permettant de calculer la valeur de pi
\author Justine Ribas <ribasjusti@cy-tech.fr>
\version 0.1
\date 22 novembre 2021
*/

#ifndef PI_H
#define PI_H

/*inclusion des entêtes de librairie*/
#include <time.h>

#include "saisie.h"


/*Déclaration des fonctions*/

/**
* \fn float methodeAire(int int_n)
* \brief permet de calculer une approximation de pi avec la méthode de l'aire d'un cercle
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 22 novembre 2021
*
* \param int_n le niveau de précision
*
* \return la valeur de pi
*/
float methodeAire(int int_n);


/**
* \fn float methodeMadhava(int int_n)
* \brief permet de calculer une approximation de pi avec la méthode de Madhava de Sangamagrama
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 22 novembre 2021
*
* \param int_n le niveau de précision
*
* \return la valeur de pi
*/
float methodeMadhava(int int_n);


/**
* \fn float methodeWallis(int int_n)
* \brief permet de calculer une approximation de pi avec la méthode de John Wallis
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 22 novembre 2021
*
* \param int_n le niveau de précision
*
* \return la valeur de pi
*/
float methodeWallis(int int_n);


/**
* \fn void menuPi(void)
* \brief permet d'afficher le menu et d'appeler les fonctions pour calculer une approximation de pi
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 22 novembre 2021
*/
void menuPi(void);

#endif