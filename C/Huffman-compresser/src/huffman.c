/*! \file main.h
 *
 *  \author Amandine Legrand etJustine Ribas
 *  \version 0.1
 *  \date Mon Jan  6 16:41:15 2020
 *
 *  \brief  contient toutes les fonctions et procédures relatives à la compression de texte
 *
 *
 */


// Inclusion des entêtes de librairie
#include "huffman.h"

// Fonction de compression d'un fichier
void compresser(char* tchar_nomFichierNormal, char* tchar_nomFichierCompresse)
{
  //DECLARATION DES VARIABLES
  s_freqCar* tabFreq; //le tableau des fréquence
  int taille; //taille du tableau de fréquence
  s_codeCar* tabCode; //le tableau contenant le code de Huffman
  int i; //parcour le tableau de code d'un caractere
  int caractere; // code ASCII du caractere courant
  FILE* fichierNormal;
  FILE* fichierCompresse;
  int tailleFichierNormal; //la taille en octet du fichier normal
  int tailleFichierCompresse; //la taille en octet du fichier compressé
  int tempDepart; //le temp au début de la compression

  //INITIALISATION
  tempDepart = clock();
  printf("Debut de la compression...\n");
  tabFreq=initTableauFrequences(tchar_nomFichierNormal, &taille);
  tabCode=creerTableHuffman(tabFreq, &taille);

  //OUVRIR LES FICHIERS
  fichierNormal = chargerFichier(tchar_nomFichierNormal, "r");
  fichierCompresse = chargerFichier(tchar_nomFichierCompresse, "wb");

  //ECRIRE LA TABLE DE CODE DE HUFFMAN
  ajouterTabCodeHuffman(tabCode, fichierCompresse);

  //ECRIRE LA COMPRESSION
  caractere = fgetc(fichierNormal);
  while(caractere != EOF){
    //ecrire le code huffman corespondant au caractère
    for(i = 0 ; i < tabCode[caractere].tailleCode ; i++){
      fputc((tabCode[caractere].code[i] == 0 ? '0' : '1'), fichierCompresse);
    }
    caractere = fgetc(fichierNormal);
  }

  //Recuperer la taille des fichiers
  tailleFichierNormal = ftell(fichierNormal);
  tailleFichierCompresse = ftell(fichierCompresse);

  //FERMER LES FICHIERS
  fermerFichier(fichierNormal);
  fermerFichier(fichierCompresse);

  //LIBERER ESPACE MEMOIRE
  for (i = 0 ; i < taille ; i++) {
		free(tabFreq[i].listeCar);
	}
  free(tabFreq);
  for (i = 0 ; i < 256 ; i++) {
		free(tabCode[i].code);
	}
  free(tabCode);

  //Avertir que la compression est fini
  printf("Fichier compressé ! (%.2f ms)\n\nDétails :\n%d octets -> %d octets  (%d%s)\n\n", (double)((double)(clock() - tempDepart)*1000.00/CLOCKS_PER_SEC), tailleFichierNormal, tailleFichierCompresse, tailleFichierCompresse*100/tailleFichierNormal, "%");
}

// Fonction qui crée la table de Huffman
s_codeCar* creerTableHuffman(s_freqCar* tabFreq, int* taille)
{
  //DECLARATION DES VARIABLES
  s_codeCar* tabCode; //la table de Huffman
  s_min minimum; //les indices des fréquences minimum
  int i; //sert pour parcourir la liste de caractères
  int indice; //est l'indice courant du tableau de code

  //INITIALISATION DES VARIABLES
  tabCode = creerTableauCode();

  while (*taille!=1){
    minimum = plusFaiblesFrequences(tabFreq, *taille);
    //on modifie le code du min1 en ajoutant un 0
    for(i = 0 ; i < tabFreq[minimum.min1].tailleListe ; i++){
      indice = tabFreq[minimum.min1].listeCar[i];
      tabCode[indice].code = ajouterValeurGauche(tabCode[indice].tailleCode, tabCode[indice].code, 0);
      tabCode[indice].tailleCode++;
    }
    //on modifie le code du min2 en ajoutant un 1
    for(i = 0 ; i < tabFreq[minimum.min2].tailleListe ; i++){
      indice = tabFreq[minimum.min2].listeCar[i];
      tabCode[indice].code = ajouterValeurGauche(tabCode[indice].tailleCode, tabCode[indice].code, 1);
      tabCode[indice].tailleCode++;
    }
    //modifier le tableau de frequence
    tabFreq = modifierTableauFrequence(tabFreq, *taille, minimum.min1, minimum.min2);
    *taille = *taille - 1;
  }
  return(tabCode);
}

// Fonction de decompression d'un fichier
void decompresser(char* tchar_nomFichierCompresse, char* tchar_nomFichierNormal)
{
  //DECLARATION DES VARIABLES
  s_codeCar* tabCode; //le tableau contenant le code de Huffman
  FILE* fichierNormal;
  FILE* fichierCompresse;
  char carLu; //le caractere courant
  int* codeLu; //le tableau qui contien le code binaire lu
  int tailleCodeLu; // la taille du tableau qui contien le code binaire lu
  int codeASCII; //le code ASCII coresspondant à la lecture
  int tempDepart; //le temp au début de la compression

  //INITIALISATION
  tempDepart = clock();
  printf("Debut de la décompression...\n");

  //OUVRIR LES FICHIERS
  fichierNormal = chargerFichier(tchar_nomFichierNormal, "w+");
  fichierCompresse = chargerFichier(tchar_nomFichierCompresse, "r");

  //LIRE LA TABLE DE CODE DE HUFFMAN
  tabCode = lireTabCodeHuffman(fichierCompresse);

  //DECOMPRESSER LE FICHIER
  carLu = fgetc(fichierCompresse);
  while(carLu != EOF){
    tailleCodeLu=0;
    codeLu = creerTableauEntier(tailleCodeLu);
    codeASCII = 256;
    while(codeASCII == 256 && carLu != EOF){
      codeLu = ajouterValeurDroit(tailleCodeLu, codeLu, (carLu == '0' ? 0 : 1));
      tailleCodeLu++;
      codeASCII = rechercheTabCode(tabCode, codeLu, tailleCodeLu);
      carLu = fgetc(fichierCompresse);
    }
    //ecrire le code ASCII trouvé
    fputc(codeASCII, fichierNormal);
    free(codeLu);
  }

  //FERMER LES FICHIERS
  fermerFichier(fichierNormal);
  fermerFichier(fichierCompresse);

  free(tabCode);

  //Avertir que la compression est fini
  printf("Fichier décompressé ! (%.2f ms)\n\n", (double)((double)(clock() - tempDepart)*1000.00/CLOCKS_PER_SEC));
}
