/*! \file compression.h
 *
 *  \author Amandine Legrand et Justine Ribas
 *  \version 0.1
 *  \date 06 Janvier 2020
 *
 *  \brief  contient toutes les déclarations de fonctions et commentaires relatifs à la compression de fichier
 *
 *
 */


#ifndef __HUFFMAN_H_
#define __HUFFMAN_H_

// Inclusion des entêtes de librairies
#include "tableau.h"
#include "fichier.h"
#include <time.h>


// Déclaration des fonctions

/**
 * \fn void compresser(char* tchar_nomFichierNormal, char* tchar_nomFichierCompresse)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 12 janvier 2020
 *
 * \brief Procedure pour compresser un fichier
 *
 * \param tchar_nomFichierNormal le nom du fichier à compresser
 * \param tchar_nomFichierCompresse le nom du fichier compressé
 *
 */
void compresser(char* tchar_nomFichierNormal, char* tchar_nomFichierCompresse);

/**
 * \fn s_codeCar* creerTableHuffman(s_freqCar* tabFreq, int* taille)
 *
 * \author Legrand Amandine <legrandama@eisti.eu>
 * \version 0.1
 * \date 08 janvier 2020
 *
 *\brief fonction qui crée et calcul la table de Huffman
 *
 *
 * \param tabFreq le tableau de frequences
 * \param taille la taille du tableau de frequences
 * \return le pointeur vers la premiere case de la table de code
 *
 */
s_codeCar* creerTableHuffman(s_freqCar* tabFreq, int* taille);

/**
 * \fn void decompresser(char* tchar_nomFichierCompresse, char* tchar_nomFichierNormal)
 *
 * \author Ribas Justine <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 12 Janvier 2020
 *
 * \brief Procedure pour décompresser un fichier
 *
 * \param tchar_nomFichierCompresse le nom du fichier compressé
 * \param tchar_nomFichierNormalb le nom du fichier décompressé
 *
 */
void decompresser(char* tchar_nomFichierCompresse, char* tchar_nomFichierNormal);

#endif
