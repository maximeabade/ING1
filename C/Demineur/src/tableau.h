/*!
 * \file tableau.h
 *
 * \author Justine Ribas <ribasjusti@cy-tech.fr>
 * \version 0.1
 * \date 09 décembre 2021
 *
 * \brief header des fonctions pour créer des tableaux
 *
 *
 */

#ifndef __TABLEAU_H__
#define __TABLEAU_H__

 // Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Déclaration des structures */

typedef struct {
    // l'état déffinit si la case est cachée, découverte ou marquée
    int int_etat;
    // la nature définit si la case est vide ou si il y a une mine
    int int_nature;
}struct_case;


/* Déclaration des fonctions */

/**
 * \fn struct_case** creerPlateau(int int_n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 09 décembre 2021
 *
 * \brief permet de créer un tableau de cases à deux dimensions
 *
 * \param int_n la taille du tableau
 * 
 * \return tab l'adresse de la première case du tableau crée
 *
 */
struct_case** creerPlateau(int int_n);


/**
 * \fn void freeTab2D(struct_case** ppcase_plateau, int int_n, int int_nbMines)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 06 décembre 2021
 *
 * \brief permet de libérer l'espace mémoire des tableaux à deux dimenssions
 *
 *
 * \param ppcase_plateau le tableau à supprimer
 * \param int_n la taille du tableau
 * \param int_nbMines le nombre de mines
 */
void freeTab2D(struct_case** ppint_tab, int int_n);


#endif
