/*!
* \file pendu.h
*
* \brief le fichier en-tête des fonctions relatives au jeu du pendu
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* 
* \date 11 janvier 2022
*/

#ifndef PENDU_H
#define PENDU_H

/*inclusion des entêtes de librairie*/
#include "tableau.h"
#include "saisie.h"
#include <errno.h>
#include <string.h>


/*Déclaration des fonctions*/

/**
* \fn char* motAleatoire(char *nomFichier)
* \brief permet de tirer un mot au hasard dans un fichier texte
*
* \param nomFichier nom du fichier texte contenant les mots
*
* \return le mot tiré au hasard
* 
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 11 janvier 2022
*/
char* motAleatoire(char *nomFichier);

/**
* \fn void jouePendu(char *str_mot)
* \brief permet de lancer une partie de pendu
*
* \param str_mot le mot à faire deviner
* 
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 16 janvier 2022
*/
void jouePendu(char *str_mot);

/**
* \fn int joueLettre(char *str_mot, char* str_motTemp, char str_lettre)
* \brief permet de jouer une lettre
*
* \param str_mot le mot à faire deviner
* \param str_motTemp le mot à afficher
* \param str_lettre la lettre à tester
*
* \return le nombre d'occurences de la lettre dans le mot
* 
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 16 janvier 2022
*/
int joueLettre(char *str_mot, char* str_motTemp, char str_lettre);

/**
* \fn int aTrouve(char *str_mot, char* str_motTemp, int int_nbErreur)
* \brief permet de vérifier si l'utilisateur a gagné
*
* \param str_mot le mot à faire deviner
* \param str_motTemp le mot à afficher
* \param int_nbErreur le nombre d'erreurs faites
*
* \return 1 si l'utilisateur a gagné, -1 si il a perdu et 0 si il continue à jouer
* 
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 16 janvier 2022
*/
int aTrouve(char *str_mot, char* str_motTemp, int int_nbErreur);

/**
* \fn void score(int int_essaisRestants)
* \brief permet d'écrire le score dans un fichier texte
*
* \param int_essaisRestants le nombre d'essais restants
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 16 janvier 2022
*/
void score(int int_essaisRestants);

/**
* \fn int modifierScore(char *str_pseudo, int int_score, char** tab_score)
* \brief permet de modier les scores
*
* \param str_pseudo le pseudo à rechercher
* \param int_score le score de l'utilisateur
*
* \return le nombre de ligne dans le fichier texte
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 16 janvier 2022
*/
int modifierScore(char *str_pseudo, int int_score, char** tab_score);

/**
* \fn char ** lireScores(void)
* \brief permet de lire et stocker les lignes du fichier scores.txt
*
* \return le tableau contenant les lignes du fichier scores.txt
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 19 janvier 2022
*/
char ** lireScores(void);

/**
* \fn void ecrireScores(char** tab_scores, int int_nbLigne)
* \brief permet de d'écrire les scores dans un fichier texte
*
* \param tab_scores le tableau contenant les lignes du fichier scores.txt
* \param int_nbLigne le nombre de ligne dans le fichier scores.txt
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 19 janvier 2022
*/
void ecrireScores(char** tab_scores, int int_nbLigne);

/**
* \fn int nbLignesScores(void)
* \brief permet de lire le nombre de lignes du fichier scores.txt
*
* \return le nombre de lignes du fichier scores.txt
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 19 janvier 2022
*/
int nbLignesScores(void);

/**
* \fn void affichagePendu(int int_nbErreurs)
* \brief permet d'afficher le nombre d'erreurs graphiquement
*
* \param int_nbErreurs le nombre d'erreurs faites
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 16 janvier 2022
*/
void affichagePendu(int int_nbErreurs);

/**
* \fn void score2(int int_score)
* \brief permet de sauvegarder le score de l'utilisateur, sans le comparer à son meilleur score
*
* \param int_score le score de l'utilisateur
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* \date 21 janvier 2022
*/
void score2(int int_score);

#endif