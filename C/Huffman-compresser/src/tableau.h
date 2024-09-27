/*! \file tableau.h
 *
 * \autor Ribas Justine et Legrand Amandine
 * \version 0.1
 * \date 07 janvier 2020
 *
 * \brief le fichier qui contient les déclarations de toutes les méthodes relatives aux manipulations de tableau
 *
 *
 */

#ifndef __TABLEAU_H_
#define __TABLEAU_H_

// Inclusion des entêtes de librairies
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "fichier.h"


// Déclaration des constantes
/*! \def ERREUR_SYS
 *  Constante pour définir une terminaison par erreur
 *  d'allocation
 */
#define ERREUR_ALLOCATION 1


// Déclaration des structures

/*! \struct s_min
 * Structure qui défini les deux indices des minimum du tableau de frequences
 */
typedef struct {
	int min1; /*!< le premier minimum du tableau de frequences */
	int min2; /*!< le second minimum du tableau de frequences */
} s_min;

/*! \struct s_codeCar
 * Structure qui défini un code pour un caracrère et la taille de ce code
 */
typedef struct {
	int* code; /*!< le code associé au caractère */
	int tailleCode; /*!< la taille du nombre qui correspond au code */
} s_codeCar;

/*! \struct s_codeCar
 * Structure qui défini un code pour un caracrère et la taille de ce code
 */
typedef struct {
	int* listeCar; /*!< le tableau de codes ASCII du caractère */
	int tailleListe; /*!< la taille du tableau de caracrères */
	int frequence; /*!< la frequence total des caracrères du tableau */
} s_freqCar;


// Déclaration des fonctions et procédures

/**
 * \fn int *creerTableauEntier ( int int_taille )
 *
 * \author Ribas Justine <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 07 janvier 2020
 *
 * \brief une fonction qui creer un tableau d'entier
 *
 *
 * \param int_taille la taille du tableau à creer
 * \return le pointeur de la premiere case du tableau d'entier
 *
 */
int *creerTableauEntier(int int_taille);

/**
 * \fn int *creerTableauCodeEntier(int int_taille)
 *
 * \author Ribas Justine <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 07 janvier 2020
 *
 * \brief fonction qui creer un tableau de de code huffman mais sous forme de tableau d'entier
 *
 *
 * \param int_taille la taille du tableau à creer
 * \return le pointeur de la premiere case du tableau d'entier
 *
 */
int *creerTableauCodeEntier(int int_taille);

/**
 * \fn s_freqCar *creerTableauFreqCar(int int_taille)
 *
 * \author Ribas Justine <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 07 janvier 2020
 *
 * \brief une fonction qui creer un tableau de frequence de caracrère
 *
 *
 * \param int_taille la taille du tableau à creer
 * \return le pointeur de la premiere case du tableau
 *
 */
s_freqCar *creerTableauFreqCar(int int_taille);

/**
 * \fn s_freqCar* initTableauFrequences(char* tchar_nomFichier, int* taille)
 *
 * \author Ribas Justine <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 07 janvier 2020
 *
 * \brief une fonction pour initialiser le tableau des fréquences des caractères présent dans le texte
 *
 *
 * \param tchar_nomFichier le nom du fichier à traiter
 * \param taille le pointeur vers la taille du tableau de fréquences
 * \return le pointeur vers la premiere case du tableau de frequences
 *
 */
s_freqCar* initTableauFrequences(char* tchar_nomFichier, int* taille);

/**
 * \fn s_min plusFaiblesFrequences(s_freqCar* tabFreq, int taille)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 06 janvier 2020
 *
 * \brief fonction qui calcule les deux indices correspondant aux valeurs minimum du tableau de frequence
 *
 *
 * \param tabFreq le pointeur vers la premiere case du tableau de frequences
 * \param taille la taille du tableau de frequences
 * \return les deux indices correspondant aux valeurs minimum du tableau de frequence
 *
 */
s_min plusFaiblesFrequences(s_freqCar* tabFreq, int taille);

/**
 * \fn s_freqCar* modifierTableauFrequence(s_freqCar* tabFreq, int taille, int min1, int min2)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 07 janvier 2020
 *
 * \brief la fonction qui modifie le tableau de fréquence en fonction des deux minimums
 *
 *
 * \param tabFreq le pointeur vers la premiere case du tableau de frequences
 * \param min1 le premier minimum
 * \param min1 le second minimum
 * \return le nouveau tableu de frequence
 *
 */
s_freqCar* modifierTableauFrequence(s_freqCar* tabFreq, int taille, int min1, int min2);

/**
 * \fn s_freqCar* supprimerCase(s_freqCar* tabFreq, int indice, int taille)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 10 janvier 2020
 *
 * \brief la fonction qui supprime une case d'un tableau de frequences
 *
 *
 * \param tabFreq le pointeur vers la premiere case du tableau de frequences
 * \param indice l'indice de la case à supprimer
 * \param taille la taille du tableau de frequences
 * \return le nouveau tableau de frequence
 *
 */
s_freqCar* supprimerCase(s_freqCar* tabFreq, int indice, int taille);

/**
 * \fn void copierCaseTabFreq(s_freqCar* tabFreqCopie, s_freqCar* tabFreqDest, int indiceCopie, int indiceDest)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 10 janvier 2020
 *
 * \brief la procedure qui copie une case du tableau de frequences dans une autre
 *
 *
 * \param tabFreqCopie le pointeur vers la premiere case du tableau de frequences a copier
 * \param tabFreqDest le pointeur vers la premiere case du tableau de frequences a coller
 * \param indiceCopie l'indice de la case à copier
 * \param indiceDest l'indice de la case à coller
 *
 */
void copierCaseTabFreq(s_freqCar* tabFreqCopie, s_freqCar* tabFreqDest, int indiceCopie, int indiceDest);

/**
 * \fn s_codeCar* creerTableauCode()
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 08 janvier 2020
 *
 * \brief fonction qui creer et initialise la table de code
 *
 *
 * \return le pointeur vers la premiere case de la table de code
 *
 */
s_codeCar* creerTableauCode();

/**
 * \fn int* ajouterValeurGauche(int nbCase, int* tab, int valeur)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 07 janvier 2020
 *
 * \brief la fonction qui ajoute la valeur au début du tableau
 *
 *
 * \param nbCase le nombre de case du tableau (=la taille)
 * \param tab le tableau auquel on veut ajouter la valeur au début
 * \param valeur la valeur à ajouter
 * \return le nouveau tableau
*/
int* ajouterValeurGauche(int nbCase, int* tab, int valeur);

/**
 * \fn int* ajouterValeurDroit(int nbCase, int* tab, int valeur)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1 g
 * \date 07 janvier 2020
 *
 * \brief la fonction qui ajoute la valeur à la fin du tableau
 *
 *
 * \param nbCase le nombre de case du tableau (=la taille)
 * \param tab le tableau auquel on veut ajouter la valeur au début
 * \param valeur la valeur à ajouter
 * \return le nouveau tableau
 *
 */
int* ajouterValeurDroit(int nbCase, int* tab, int valeur);

/**
 * \fn char convertirTabEntierChar(int* tab, int taille)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 12 janvier 2020
 *
 * \brief la fonction qui converti un tableau d'entier de 8 cases contenant des 0 et des 1 en caractère
 *
 *
 * \param tab le tableau qui contient le code binaire
 * \param taille la taille du tableau (taille <= 8)
 * \return le caractere converti
 *
 */
char convertirTabEntierChar(int* tab, int taille);

/**
 * \fn int* convertirCharTabEntier(char c)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 16 janvier 2020
 *
 * \brief la fonction qui converti un caractère en un tableau d'entier de 8 cases contenant des 0 et des 1
 *
 *
 * \param c le caractère à convertir
 * \return tableau de 8 case correspondant au code binaire du caractère
 *
 */
int* convertirCharTabEntier(char c);

/**
 * \fn void ajouterTabCodeHuffman(s_codeCar* tabCode, FILE* fichier)
 *
 * \author Ribas Justine <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 15 janvier 2020
 *
 * \brief procedure qui écrit le code huffman dans le fichier
 *
 *
 * \param tabCode le tableau de code de huffman de taille 256 (une case par caractère de la table ASCII)
 * \param fichier le fichier où le code sera saisie
 *
 */
void ajouterTabCodeHuffman(s_codeCar* tabCode, FILE* fichier);

/**
 * \fn s_codeCar* lireTabCodeHuffman(FILE* fichier)
 *
 * \author Ribas Justine <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 15 janvier 2020
 *
 * \brief fonction qui recupere la table de code huffman au debut du fichier
 *
 *
 * \param fichier le fichier où est inscrit la table de code d'huffman
 * \return le tableau de code de huffman de taille 256 (une case par caractère de la table ASCII)
 *
 */
s_codeCar* lireTabCodeHuffman(FILE* fichier);

/**
 * \fn int rechercheTabCode(s_codeCar* tabCode, int* tabBinaire, int taille)
 *
 * \author Ribas Justine <ribasjusti@eisti.eu>
 * \version 0.1 Premier jet
 * \date 17 janvier 2020
 *
 * \brief fonction qui recherche un code dans le tableau de code de huffman
 *
 *
 * \param tabCode le tableau de codes d'huffman
 * \param tabBinaire le tableau binaire à rechercher parmis les codes huffman
 * \param taille la taille du tableau binaire
 * \return l'indice trouvé (256 si pas trouvé)
 *
 */
int rechercheTabCode(s_codeCar* tabCode, int* tabBinaire, int taille);

#endif
