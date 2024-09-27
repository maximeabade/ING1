/*!
* \file jeu.h
*
* \brief le header des fonction relavtives au jeu
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* 
* \date 09 décembre 2021
*/

#ifndef JEU_H
#define JEU_H

/*inclusion des entêtes de librairie*/
#include "saisie.h"
#include "tableau.h"

/* Déclarations des fonctions*/


/**
 * \fn void initPlateau(struct_case** ppcase_plateau, int int_n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 09 décembre 2021
 *
 * \brief permet d'initialiser un plateau de cases à deux dimensions'
 *
 * \param ppcase_plateau le plateau de jeu
 * \param int_n la taille du tableau
 * 
 */
void initPlateau(struct_case** ppcase_plateau, int int_n, int int_nbMines);


/**
 * \fn void chiffrerCases(struct_case** ppcase_plateau, int int_n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 09 décembre 2021
 *
 * \brief permet d'attribuer à chaque case, le nombre de mines qui l'entourrent
 *
 * \param ppcase_plateau le tableau de cases
 * \param int_n la taille du tableau
 * 
 */
void chiffrerCases(struct_case** ppcase_plateau, int int_n);


/**
 * \fn void afficherPlateau(struct_case** ppcase_plateau, int int_n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 09 décembre 2021
 *
 * \brief permet d'afficher un tableau de cases à deux dimensions
 *
 *
 * \param ppcase_plateau le tableau à afficher
 * \param int_n la taille du tableau
 *
 */
void afficherPlateau(struct_case** ppcase_plateau, int int_n);


/**
 * \fn void afficherCaseDecouverte(int int_valeur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 09 décembre 2021
 *
 * \brief permet d'afficher une case découverte avec la bonne couleur
 *
 * \param int_valeur la valeur de la case à afficher
 *
 */
void afficherCaseDecouverte(int int_valeur);


/*! \fn void afficheDelimitation(int int_n)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 09 décembre 2021
 *
 *  \brief permet d'afficher les délimitations du plateau de jeu
 * 
 *  \param int_n la taille du plateau
 * 
 *  \remarks 
 */
void afficheDelimitation(int int_n);


/*! \fn void deroulePartie(struct_case** ppcase_plateau, int int_n, int int_nbMines)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 09 décembre 2021
 *
 *  \brief permet de dérouler une partie de jeu
 * 
 *  \param ppcase_plateau le tableau de cases
 *  \param int_n la taille du plateau
 *  \param int_nbMines le nombre de mines
 * 
 *  \remarks 
 */
void deroulePartie(struct_case** ppcase_plateau, int int_n, int int_nbMines);


/**
 * \fn int jouer(struct_case** ppcase_plateau, int int_n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 09 décembre 2021
 *
 * \brief permet au joueur de dévoiler ou marquer une case
 *
 *
 * \param ppcase_plateau le tableau à afficher
 * \param int_n la taille du tableau
 *
 * \return 0 si la partie continue, -1 si le joueur a trouvé une mine et a donc perdu
 */
int jouer(struct_case** ppcase_plateau, int int_n);


/**
 * \fn int verifaGagne(struct_case** ppcase_plateau, int int_n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 09 décembre 2021
 *
 * \brief permet de savoir si le joueur a gagné
 *
 *
 * \param ppcase_plateau le tableau à afficher
 * \param int_n la taille du tableau
 *
 * \return 0 si la partie continue, 1 si le joueur a trouvé toutes les mines et a donc gagné
 */
int verifaGagne(struct_case** ppcase_plateau, int int_n);


/**
 * \fn int compteMines(struct_case** ppcase_plateau, int int_n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 15 décembre 2021
 *
 * \brief permet de savoir le nombre de mines non découvertes restantes
 *
 *
 * \param ppcase_plateau le plateau de jeu
 * \param int_n la taille du tableau
 *
 * \return le nombre de mines restantes
 */
int compteMines(struct_case** ppcase_plateau, int int_n);


/**
 * \fn void revelePlateau(struct_case** ppcase_plateau, int int_n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 15 décembre 2021
 *
 * \brief permet de révéler toutes les cases du plateau
 *
 *
 * \param ppcase_plateau le plateau de jeu
 * \param int_n la taille du tableau
 *
 */
void revelePlateau(struct_case** ppcase_plateau, int int_n);


/**
 * \fn void reveleZoneLibre(struct_case** ppcase_plateau, int int_n, int int_ligne, int int_colonne)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 15 décembre 2021
 *
 * \brief permet de réver les case autour de la case sans mine tant qu'on ne trouve pas de mine autours
 *
 *
 * \param ppcase_plateau le plateau de jeu
 * \param int_n la taille du tableau
 * \param int_ligne la ligne de la case
 * \param int_colonne la colonne de la case
 *
 */
void reveleZoneLibre(struct_case** ppcase_plateau, int int_n, int int_ligne, int int_colonne);


#endif