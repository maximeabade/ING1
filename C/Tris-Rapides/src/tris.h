/*!
 * \file tris.h
 *
 * \autor Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 17 mars 2020
 *
 * \brief header des fonctions et procéedures relatives aux tris
 *
 *
 */

 #ifndef __TRIS_H__
 #define __TRIS_H__


 // Inclusion des entêtes de librairies
 #include "tableau.h"
 #include "fichier.h"

 /**
  *\fn void triSelection(int* tab, int n, FILE* fichier)
  *
  *\author Justine Ribas <ribasjusti@eisti.eu>
  *\version 0.1
  *\date 19 février 2020
  *
  *\brief permet de trier un tableau par sélection
  *
  *
  *\param tab le tableau à trier
  *\param n la taille du tableau
  *
  */
void triSelection(int* tab, int n, FILE* fichier);

/**
 *\fn void triBulle(int* tab, int n, FILE* fichier)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 19 février 2020
 *
 *\brief permet de trier un tableau à bulle
 *
 *
 *\param tab le tableau à trier
 *\param n la taille du tableau
 *
 */
 void triBulle(int* tab, int n, FILE* fichier);

/**
 *\fn void triInsertion(int* tab, int n, FILE* fichier)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 19 février 2020
 *
 *\brief permet de trier un tableau par insertion
 *
 *
 *\param tab le tableau  à trier
 *\param n la taille du tableau
 *
 */
void triInsertion(int* tab, int n, FILE* fichier);

/**
 *\fn void triRapide(int* tab, int n, FILE* fichier)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 18 mars 2020
 *
 *\brief permet de trier un tableau par tri rapide
 *
 *
 *\param tab le tableau à trier
 *\param n la taille du tableau
 *
 */
 void triRapide(int* tab, int n, FILE* fichier);

/**
 *\fn void quickSort(int* tab, int debut, int fin)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 22 mars 2020
 *
 *\brief fonction récursive du tri rapide
 *
 *
 *\param tab le tableau à trier
 *\param debut première case du tableau à trier
 *\param fin dernière case du tableau à trier
 *
 */
void quickSort(int* tab, int debut, int fin);

/**
 *\fn int partitionner(int* tab, int debut, int fin)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 22 mars 2020
 *
 *\brief permet de partitionner un tableau en deux, de part et d'autre du tableau
 *
 *
 *\param tab le tableau à partitionner
 *\param debut première case du tableau à partitionner
 *\param fin dernière case du tableau à partitionner
 *\return l'indce du pivot
 *
 */
int partitionner(int* tab, int debut, int fin);

/**
 *\fn void triFusion(int* tab, int n, FILE* fichier)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 22 mars 2020
 *
 *\brief permet de trier un tableau par fusion
 *
 *
 *\param tab le tableau à trier
 *\param n la taille du tableau
 *
 */
void triFusion(int* tab, int n, FILE* fichier);

/**
 *\fn void mergeSort(int* tab, int n)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 22 mars 2020
 *
 *\brief fonction récursive du tri fusion
 *
 *
 *\param tab le tableau à trier
 *\param n la taille du tableau
 *
 */
void mergeSort(int* tab, int n);

/**
 *\fn void fusionner(int* tab, int* tab1, int n1, int* tab2, int n2)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 22 mars 2020
 *
 *\brief permet de fusionner un tableau en deux, de part et d'autre du tableau
 *
 *
 */
void fusionner(int* tab, int* tab1, int n1, int* tab2, int n2);

/**
 *\fn void  echanger(int* tab, int indice1, int indice2)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 15 mars 2020
 *
 *\brief permet d'échanger deux cases dans un tableau
 *
 *
 *\param tab le tableau à modifier
 *\param indice1 l'indice de la première case à échanger
 *\param indice2 l'indice de la deuxième case à échanger
 *
 */
void  echanger(int* tab, int indice1, int indice2);


void trisShell(int* tab, int n, FILE* fichier);



#endif
