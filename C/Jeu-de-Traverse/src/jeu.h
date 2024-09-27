/*!
 * \file jeu.h
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief header des fonctions relatives au déroulement d'une partie de jeu
 *
 *
 */

#ifndef __JEU_H__
#define __JEU_H__

// Inclusion des librairies
#include "tableau.h"
#include "saisie.h"
#include "deplacement.h"
#include <unistd.h>


/**
 * \fn void partieJJ(void)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 24 avril 2020
 *
 * \brief permet de dérouler une partie entre deux joueurs
 *
 *
 */
void partieJJ(void);


/**
 * \fn void partieJO(void)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 28 avril 2020
 *
 * \brief permet de dérouler une partie entre un joueur et un ordi
 *
 *
 */
void partieJO(void);


/**
 * \fn void partieOO(void)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 28 avril 2020
 *
 * \brief permet de dérouler une partie entre deux ordinateurs
 *
 */
void partieOO(void);


/**
 * \fn void joueurJoue(s_pion** tab, int joueur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief permet de faire jouer le joueur
 *
 *
 * \param tab le plateau de jeu
 * \param joueur le joueur qui joue
 *
 */
void joueurJoue(s_pion** tab, int joueur);


/**
 * \fn void ordiJoue(s_pion** tab, s_pion*** jeu, int tour, int joueur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief permet de faire jouer le joueur
 *
 *
 * \param tab le plateau de jeu
 * \param jeu l'état du jeu
 * \param tour le nombre de tour depuis le début de la partie
 * \param joueur le joueur qui joue
 *
 */
void ordiJoue(s_pion** tab, s_pion*** jeu, int tour, int joueur);


/**
 * \fn s_coord choixPion(s_pion** tab, int joueur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 avril 2020
 *
 * \brief permet de choisir le pion que l'on souhaite déplacer
 *
 *
 * \param tab le plateau de jeu
 * \param joueur le joueur qui choisi
 * \return les coordonées de la nouvelle case
 *
 */
s_coord choixPion(s_pion** tab, int joueur);


/**
 * \fn s_coord choixCase(s_pion** tab)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 avril 2020
 *
 * \brief permet de choisir une case dans laquelle déplacer son pion
 *
 *
 * \param tab le plateau de jeu
 * \return les coordonées de la nouvelle case
 *
 */
s_coord choixCase(s_pion** tab);


/**
 * \fn int tourJoueur(s_pion** tab, s_coord pion, int joueur)
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de gérer les déplacements possibles d'un pion
 *
 *
 * \param tab le plateau de jeu
 * \param pion les coordonnées de la case choisie
 * \param joueur le joueur qui joue
 * \return 1 si le déplacement est fait, 0 si il est impossible
 *
 */
int tourJoueur(s_pion** tab, s_coord pion, int joueur);


/**
 * \fn int aGagne(s_pion** tab, int tour)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 26 avril 2020
 *
 * \brief permet de vérifier si un joueur a gagné
 *
 *
 * \param tab le plateau de jeu
 * \param tour le numéro du tour en cours
 * \return 1 si un joueur a gagné, 0 sinon
 *
 */
int aGagne(s_pion **tab, int tour);


/**
 * \fn int matchNul(s_pion*** jeu, int tour)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 26 avril 2020
 *
 * \brief permet de vérifier si il y a match nul
 *
 *
 * \param jeu l'ensemble des plateaux de jeu depuis le début de la partie
 * \param tour le numéro du tour en cours
 * \return 1 si il y a match nul, 0 sinon
 *
 */
int matchNul(s_pion*** jeu, int tour);


/**
 * \fn int minMax(s_pion** plateau, s_pion*** jeu, int tour, int profondeur, s_coord* pionDeb, s_coord* pionFin, int joueur, int evalMax)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 29 avril 2020
 *
 * \brief permet à l'ordinateur de jouer le pion et le coup qui lui est la plus avantageux
 *
 *
 * \param plateau le plateau de jeu
 * \param jeu l'état du jeu
 * \param tour le nombre de tour depuis le début de la partie
 * \param profondeur la profondeur de cette IA
 * \param pionDeb le pion que l'ordi va déplacer
 * \param pionFin la case où sera déplacé le pion
 * \param joueur le joueur qui joue
 * \param evalMax bouléen qui indique si on cherche le minimum ou le maximum
 * \return le gain optimal
 *
 */
 int minMax(s_pion** plateau, s_pion*** jeu, int tour, int profondeur, s_coord* pionDeb, s_coord* pionFin, int joueur, int evalMax);


/**
 * \fn int evaluerGain(s_pion** plateau, s_pion*** jeu, int tour, int joueur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 29 avril 2020
 *
 * \brief permet d'évaluer le gain
 *
 *
 * \param plateau le plateau de jeu
 * \param jeu l'état du jeu
 * \param tour le nombre de tour depuis le début de la partie
 * \param joueur le joueur qui joue
 * \return le gain
 *
 */
int evaluerGain(s_pion** plateau, s_pion*** jeu, int tour, int joueur);


/**
 * \fn int calculGain(s_pion** plateau, int joueur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 29 avril 2020
 *
 * \brief permet de calculer le gain de cet état de jeu c'est à dire la somme des distances des pion depuis la ligne de départ
 *
 *
 * \param plateau le plateau de jeu
 * \param joueur le joueur qui joue
 * \return la somme
 *
 */
int calculGain(s_pion** plateau, int joueur);


#endif
