/*!
 * \file listes.h
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 31 mars 2020
 *
 * \brief définition des méthodes relatives aux listes
 *
 *
 */

 #ifndef __LISTES_H__
 #define __LISTES_H__

// Inclusion des entêtes de librairies
#include "saisie.h"
#include <stdio.h>
#include <stdlib.h>

// Déclaration des structures

/*! \struct s_element
 * Structure qui défini chaque élément de la liste associé au pointeur de l'élément suivant
 */
typedef struct s_element s_element;
struct s_element
{
	int valeur; /*!< la valeur l'élément de la liste */
	s_element* suivant; /*!< le pointeur vers l'élément suivant */
};

/*! \struct s_liste
 * Structure qui défini une liste avec les pointeurs des éléments
 */
typedef struct
{
	s_element* premier; /*!< le pointeur de l'élément de la liste */
} s_liste;


// Déclaration des méthodes

/**
 *\fn s_liste* initListe(void)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 31 mars 2020
 *
 *\brief permet d'initialiser la liste
 *
 *
 *\return la liste
 *
 */
s_liste* initListe(void);

/**
 *\fn void cons(s_liste* liste, int nbr)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 31 mars 2020
 *
 *\brief permet d'ajouter un élément en tête de liste
 *
 *
 *\param liste la liste dans laquelle on insère un nouvel élément
 *\param nbr la valeur du nouvel élément
 *
 */
void cons(s_liste* liste, int nbr);

/**
 *\fn void rcons(s_liste* liste, int nbr)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 31 mars 2020
 *
 *\brief permet d'ajouter un élément en fin de liste
 *
 *
 *\param liste la liste dans laquelle on insère un nouvel élément
 *\param nbr la valeur du nouvel élément
 *
 */
void rcons(s_liste* liste, int nbr);

/**
 *\fn void ajouter(s_liste* liste, int nbr, int position)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 02 avril 2020
 *
 *\brief permet d'ajouter un élément à une position donnée de la liste
 *
 *
 *\param liste la liste dans laquelle on insère un nouvel élément
 *\param nbr la valeur du nouvel élément
 *\param position position du nouvel élément
 *
 */
void ajouter(s_liste* liste, int nbr, int position);


/**
 *\fn void afficherListe(s_liste* liste)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 31 mars 2020
 *
 *\brief permet d'afficher la liste
 *
 *
 *\param liste la liste à afficher
 *
 */
void afficherListe(s_liste* liste);

/**
 *\fn int listSum(s_liste* liste)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 01 avril 2020
 *
 *\brief permet de calculer la somme des éléments de la liste
 *
 *
 *\param liste la liste
 *\return la somme des éléments
 *
 */
int listSum(s_liste* liste);

/**
 *\fn int listMin(s_liste* liste)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 01 avril 2020
 *
 *\brief permet de renvoyer le minimum d'une liste de, si la liste est vide, on renvoie 0.
 *
 *
 *\param liste la liste
 *\return le minimum de la liste
 *
 */
int listMin(s_liste* liste);

/**
 *\fn int isEqual(s_liste* liste1, int n1, s_liste* liste2, int n2)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 01 avril 2020
 *
 *\brief permet de vérifier si deux listes sont égales
 *
 *
 *\param liste1 la première liste à comparer
 *\param n1 la taille de la première liste
 *\param liste2 la deuxième liste à comparer
 *\param n2 la taille de la deuxième liste
 *\return 1 si les deux listes sont égales, 0 sinon
 *
 */
int isEqual(s_liste* liste1, int n1, s_liste* liste2, int n2);

/**
 *\fn void removeFirst(s_liste* liste, int nbr)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 02 avril 2020
 *
 *\brief permet de supprimer la première occurence du nombre dans la liste
 *
 *
 *\param liste la liste dans laquelle on supprime un élément
 *\param nbr la valeur de l'élément à supprimer
 *
 */
void removeFirst(s_liste* liste, int nbr);

/**
 *\fn s_liste* mirror(s_liste* liste)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 02 avril 2020
 *
 *\brief permet d'obtenir la liste inverse d'une liste
 *
 *
 *\param liste la liste de base
 *\return la liste inverse
 *
 */
s_liste* mirror(s_liste* liste);

/**
 *\fn void suppDeb(s_liste* liste)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 02 avril 2020
 *
 *\brief permet de supprimer l'élément en tête de liste
 *
 *
 *\param liste la liste dans laquelle on supprime un élément
 *
 */
void suppDeb(s_liste* liste);

/**
 *\fn void suppFin(s_liste* liste)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 02 avril 2020
 *
 *\brief permet de supprimer l'élément en fin de liste
 *
 *
 *\param liste la liste dans laquelle on supprime un élément
 *
 */
void suppFin(s_liste* liste);

/**
 *\fn void supprimer(s_liste* liste, int indice)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 04 avril 2020
 *
 *\brief permet de supprimer l'élément à une position donnée
 *
 *
 *\param liste la liste dans laquelle on supprime un élément
 *\param indice la position
 *
 */
void supprimer(s_liste* liste, int indice);

/**
 *\fn int rechercher(s_liste* liste, int nbr)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 04 avril 2020
 *
 *\brief permet de rechercher un élément et de retourner sa position
 *
 *
 *\param liste la liste dans laquelle on cherche un élément
 *\param nbr le nombre à rechercher
 *\return la position de l'élément ou -1 si l'élément n'est pas dans la liste
 *
 */
int rechercher(s_liste* liste, int nbr);

/**
 *\fn int removeAll(s_liste* liste, int nbr)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 04 avril 2020
 *
 *\brief permet de supprimer toutes les occurences d'une valeur
 *
 *
 *\param liste la liste dans laquelle on supprime des éléments
 *\param nbr la valeur à supprimer
 *\return le nombre d'éléments supprimés
 *
 */
int removeAll(s_liste* liste, int nbr);

/**
 *\fn int suppDoublon(s_liste* liste)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 04 avril 2020
 *
 *\brief permet de supprimer touts les doublons d'une liste
 *
 *
 *\param liste la liste dans laquelle on supprime tous les doublons
 *\return le nombre d'éléments supprimés
 *
 */
int suppDoublon(s_liste* liste);

/**
 *\fn void rattacher(s_liste* liste)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 04 avril 2020
 *
 *\brief permet de rattacher une liste à elle-même
 *
 *
 *\param liste la liste à modifier
 *
 */
void rattacher(s_liste* liste);


#endif
