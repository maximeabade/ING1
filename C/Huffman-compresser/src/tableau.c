/*! \file tableau.c
 *
 * \autor Ribas Justine et Legrand Amandine
 * \version 0.1
 * \date 07 janvier 2020
 *
 * \brief le fichier qui contient les définitions de toutes les méthodes relatives aux manipulations de tableau
 *
 *
 */


// Inclusion des entêtes de librairies
#include "tableau.h"


//fonction qui creer un tableau d'entier
int *creerTableauEntier(int int_taille)
{
  //DECLARATION DES VARIABLES
  int *tint_tab; //le poiteur vers la premiere case du tableau

  //ALLOCATION DE LA MEMOIRE
  tint_tab = malloc(int_taille * sizeof(int));
  //Si l'allocation c'est fini en echec
  if(tint_tab == NULL){
    //Avertir l'utilisateur
    printf("Erreur d'allocation mémoire !\n");
    //Quitter le programme avec un message d'erreur
    exit(ERREUR_ALLOCATION);
  }

  //retourner l'addresse de la premiere case du tableau, soit : tint_tab
  return(tint_tab);
}

//fonction qui creer un tableau de de code huffman mais sous forme de tableau d'entier
int *creerTableauCodeEntier(int int_taille)
{
  //DECLARATION DES VARIABLES
  int *tint_tab; //le poiteur vers la premiere case du tableau
  int i; //parcour tout le tableau

  //ALLOCATION DE LA MEMOIRE
  tint_tab = malloc(int_taille * sizeof(int));
  //Si l'allocation c'est fini en echec
  if(tint_tab == NULL){
    //Avertir l'utilisateur
    printf("Erreur d'allocation mémoire !\n");
    //Quitter le programme avec un message d'erreur
    exit(ERREUR_ALLOCATION);
  }
  for(i = 0 ; i<int_taille ; i++){
    tint_tab[i] = 256;
  }

  //retourner l'addresse de la premiere case du tableau, soit : tint_tab
  return(tint_tab);
}

//fonction qui creer un tableau de frequence de caracrère
s_freqCar *creerTableauFreqCar(int int_taille)
{
  //DECLARATION DES VARIABLES
  s_freqCar *tfreq_tab; //le poiteur vers la premiere case du tableau

  //ALLOCATION DE LA MEMOIRE
  tfreq_tab = malloc(int_taille * sizeof(s_freqCar));
  //Si l'allocation c'est fini en echec
  if(tfreq_tab == NULL){
    //Avertir l'utilisateur
    printf("Erreur d'allocation mémoire !\n");
    //Quitter le programme avec un message d'erreur
    exit(ERREUR_ALLOCATION);
  }

  //retourner l'addresse de la premiere case du tableau, soit : tint_tab
  return(tfreq_tab);
}

// Fonction pour créer le tableau des fréquences des caractères présent dans le texte
s_freqCar* initTableauFrequences(char* tchar_nomFichier, int* taille)
{
  //DECLARATION DES VARIABLES
  FILE* fichier;  // Descripteur de fichier
  int* tab; //tableau de fréquences
  int caractere; //caractère stocké sous forme d'entier pour se reporter à la table d'ASCII
  s_freqCar* tabFreq; //le tableau de frequence qui sera créer, initialisé et retourné
  int i; //sert pour les parcours
  int j; //sert pour les parcours
  //INITIALISATION DES VARIABLES
  *taille = 0;
  //on creer le tableau des fréquences
	tab=creerTableauEntier(256);
  //initialisation du tableau de fréquence
  for(i=0; i<256; i++){
    tab[i]=0;
  }
  // FAIRE LE TABLEAU DE FREQUENCE
  //on ouvre le fichier en lecture
  fichier = chargerFichier(tchar_nomFichier, "r");
  //lecture du premier caractère du fichier
  caractere=(int)fgetc(fichier);
	//on parcours le fichier et on incrémente la fréquence du caractère lu
  while(caractere != EOF){
    tab[caractere]++;
    caractere=(int)fgetc(fichier);
  }
  //on ferme le fichier
  fermerFichier(fichier);
  // FAIRE LE TABLEAU DE FREQUENCE SANS LES VALEURS NULLES
  //compter le nombre de case non nulles du pécédent tableau de frequence
  for(i = 0 ; i < 256 ; i++){
    if(tab[i] != 0){
      *taille = *taille + 1;
    }
  }
	//on initialise le nouveau tableau
  tabFreq=creerTableauFreqCar(*taille);
  //initialisation de chaques cases du nouveau tableau
  j=0;
  for(i = 0 ; i < 256 ; i++){
    if(tab[i] != 0){
      tabFreq[j].listeCar=creerTableauEntier(1);
			tabFreq[j].listeCar[0]=i;
			tabFreq[j].tailleListe=1;
      tabFreq[j].frequence=tab[i];
      j++;
    }
  }
	free(tab);
  //RETOURNER LA TAILLE
  return(tabFreq);
}

//fonction qui retourne les deux indices correspondant aux valeurs minimum du tableau de frequence
s_min plusFaiblesFrequences(s_freqCar* tabFreq, int taille)
{
  //DECLARATION DES VARIABLES
	int i; //va parcourir le tableau de frequences
	s_min res; //les deux indices correspondant aux valeurs minimum du tableau de frequence
  int tmp; //valeur temporaire

  //INITIALISATION DES VARIABLES
	res.min1 = 0;
	res.min2 = 1;

  //parcour du tableau des frequences
	for(i = 2 ; i < taille ; i++){
    //Verifier si la frequence courante n'est pas inferieur aux minimums
		if(tabFreq[i].frequence < tabFreq[res.min1].frequence){
			res.min1=i;
		} else {
			if(tabFreq[i].frequence < tabFreq[res.min2].frequence){
				res.min2=i;
			}
		}
	}
  if(res.min2 < res.min1){
    tmp = res.min2;
    res.min2 = res.min1;
    res.min1 = tmp;
  }

  //retourner les deux indices correspondant aux valeurs minimum du tableau de frequence
	return(res);
}

// Fonction qui initialise la table de code
s_codeCar* creerTableauCode()
{
  //DECLARATION DES VARIABLES
  s_codeCar* tab; //tableau à initialiser
  int i;

  //ALLOCATION MEMOIRE
  tab = malloc(256*sizeof(s_codeCar));
  if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
  }

  //INITIALISATION DU TABLEAU
	for(i=0; i<256; i++){
		tab[i].tailleCode=0;
    tab[i].code = creerTableauEntier(0);
	}

  //RETOURNER LE TABLEAU
  return(tab);
}

// Fonction qui supprime une case d'un tableau de frequences
s_freqCar* supprimerCase(s_freqCar* tabFreq, int indice, int taille)
{
  //DECLARATION DES VARIABLES
	s_freqCar* nouveauTab; //le nouveau tableau de taille taille-1
	int i; //parcour les indices du tableau tabFreq

  //INITIALISATION DES VARIABLES
	nouveauTab = creerTableauFreqCar(taille-1);

  //Copie de lancien tableau vers le nouveau sauf la case à supprimer
	for (i = 0 ; i < indice ; i++) {
		copierCaseTabFreq(tabFreq, nouveauTab, i , i);
	}
  for (i = indice+1 ; i < taille ; i++) {
		copierCaseTabFreq(tabFreq, nouveauTab, i , i-1);
	}

  //LIBERER ESPACE MEMOIRE
  for (i = 0 ; i < taille ; i++) {
		free(tabFreq[i].listeCar);
	}
  free(tabFreq);

  //retourner le nouveau tableau
	return(nouveauTab);
}

//procedure qui copie une case du tableau de frequences dans une autre
void copierCaseTabFreq(s_freqCar* tabFreqCopie, s_freqCar* tabFreqDest, int indiceCopie, int indiceDest)
{
  //DECLARATION DES VARIABLES
  int i; //parcour le tableau de caractère

  //COPIE
  tabFreqDest[indiceDest].frequence = tabFreqCopie[indiceCopie].frequence ;
  tabFreqDest[indiceDest].tailleListe = tabFreqCopie[indiceCopie].tailleListe ;
  tabFreqDest[indiceDest].listeCar = creerTableauEntier(tabFreqCopie[indiceCopie].tailleListe);
  for(i = 0 ; i < tabFreqCopie[indiceCopie].tailleListe ; i++){
    tabFreqDest[indiceDest].listeCar[i] = tabFreqCopie[indiceCopie].listeCar[i];
  }
}

//procedure qui ajoute la valeur au début du tableau
int* ajouterValeurGauche(int nbCase, int* tab, int valeur)
{
  //DECLARATION DES VARIABLES
	int* nouveauTab; //le nouveau tableau de taille nbCase+1
	int i; //parcour les indices du tableau tab

  //INITIALISATION DES VARIABLES
	nouveauTab = creerTableauEntier(nbCase+1);
	nouveauTab[0] = valeur;
	for (i = 0 ; i < nbCase ; i++) {
		nouveauTab[i+1] = tab[i];
	}
  free(tab);
	return(nouveauTab);
}

//procedure qui ajoute la valeur au début du tableau
int* ajouterValeurDroit(int nbCase, int* tab, int valeur)
{
  //DECLARATION DES VARIABLES
	int* nouveauTab; //le nouveau tableau de taille nbCase+1
	int i; //parcour les indices du tableau tab

  //INITIALISATION DES VARIABLES
	nouveauTab = creerTableauEntier(nbCase+1);
	for (i = 0 ; i < nbCase ; i++) {
		nouveauTab[i] = tab[i];
	}
  nouveauTab[nbCase] = valeur;
  free(tab);
	return(nouveauTab);
}

// Fonction qui modifie le tableau de fréquence en fonction des deux minimums
s_freqCar* modifierTableauFrequence(s_freqCar* tabFreq, int taille, int min1, int min2)
{
  //DECLARATION DES VARIABLES
  int i; //parcourl la liste de caractères de tabFreq -> indice : min2

  //on somme les fréquences dans la case de min1
  tabFreq[min1].frequence = tabFreq[min1].frequence + tabFreq[min2].frequence;

  //copier les caractères de la liste 2 vers la liste 1
  for(i = 0 ; i < tabFreq[min2].tailleListe ; i++){
    tabFreq[min1].listeCar = ajouterValeurGauche(tabFreq[min1].tailleListe, tabFreq[min1].listeCar, tabFreq[min2].listeCar[i]);
    tabFreq[min1].tailleListe++;
  }

  //on supprime la case du min 2
  return(supprimerCase(tabFreq, min2, taille));
}

// la fonction qui converti un tableau d'entier de 8 cases contenant des 0 et des 1 en caractère
char convertirTabEntierChar(int* tab, int taille)
{
  //DECLARATION DES VARIABLES
  char c; //le caractere qui contien la covertion
  int puissance; //la puissance courante
  //INITIALISATION
  c = 0;
  puissance = 0;

  for(taille = taille ; taille > 0 ; taille--){
    c = c + (int)tab[taille-1]*(int)pow(2.00, (double)puissance);
    puissance++;
  }
  return(c);
}

// la fonction qui converti un caractère en un tableau d'entier de 8 cases contenant des 0 et des 1
int* convertirCharTabEntier(char c)
{
  //DECLARATION DES VARIABLES
  int* tab; //le tableau d'entier qui contien la covertion
  int puissance; //la puissance courante
  int puissanceDeDeux; //la puissance de 2 courante

  //INITIALISATION
  tab = creerTableauEntier(8);

  for(puissance = 7 ; puissance >= 0 ; puissance--){
    puissanceDeDeux = (int)pow(2.00, (double)puissance);
    if(c >= puissanceDeDeux){
      tab[7-puissance] = 1;
      c = c-puissanceDeDeux;
    }
    else{
      tab[7-puissance] = 0;
    }
  }
  return(tab);
}

//procedure qui écrit le code huffman dans le fichier
void ajouterTabCodeHuffman(s_codeCar* tabCode, FILE* fichier)
{
  //DECLARATION DES VARIABLES
  int i; //Parcour le tableau de code huffman
  int j; //Parcour le code d'un caractere
  int compteur; //le compteur

  //Calcul le nombre de caractère apparaitant dans le texte et l'ecrit
  compteur = 0;
  for(i = 0 ; i<256 ; i++){
    if(tabCode[i].tailleCode != 0){
      compteur++;
    }
  }
  ecrireEntier(compteur, fichier);

  //Ecrit le code huffman de chaque caractere existant dans le texte
  for(i = 0 ; i<256 ; i++){
    if(tabCode[i].tailleCode != 0){
      //ecrire le code ASCII
      ecrireEntier(i, fichier);
      //ecrire la taille du code de huffman
      ecrireEntier(tabCode[i].tailleCode, fichier);
      //ecrire le code de huffman
      for(j = 0 ; j < tabCode[i].tailleCode ; j++){
        fputc((tabCode[i].code[j] == 0 ? '0' : '1'), fichier);
      }
    }
  }
}

// procedure qui recupere la table de code huffman au debut du fichier
s_codeCar* lireTabCodeHuffman(FILE* fichier)
{
  //DECLARATION DES VARIABLES
  s_codeCar* tabCode; //le tableau de code d'huffman
  int nbrCarTable; //le nombre de caractère dans la table de code de huffman présente dans le fichier
  int i; //Parcour le tableau de code huffman du fichier
  int j; //Parcour le code de huffman courant
  char carLu; //caractere courant, lu
  int codeASCII; //le code du caractère courant, correspondant au code ASCII du caractère

  //INITIALISATION DES VARIABLES
  tabCode = creerTableauCode(256);

  //Lecture du nombre de caractère présent dans la table
  nbrCarTable = lireEntier(fichier);

  //rempli la table de code huffman
  for(i = 0 ; i<nbrCarTable ; i++){
    //lire le code ASCII
    codeASCII = lireEntier(fichier);
    //Lire la taille du code huffman
    tabCode[codeASCII].tailleCode = lireEntier(fichier);
    free(tabCode[codeASCII].code);
    tabCode[codeASCII].code = creerTableauEntier(tabCode[codeASCII].tailleCode);
    //Lire le code huffman
    for(j = 0 ; j < tabCode[codeASCII].tailleCode ; j++){
      carLu = fgetc(fichier);
      tabCode[codeASCII].code[j] = (carLu == '0' ? 0 : 1);
    }
  }
  return(tabCode);
}

//fonction qui recherche un code dans le tableau de code de huffman
int rechercheTabCode(s_codeCar* tabCode, int* tabBinaire, int taille)
{
  //DECLARATION DES VARIABLES
	int indice; //l'indice cherché par la recherche / correspond au code ASCII
  int trouve; //1 si le code est trouvé, 0 sinon
	int i; //parcour les indices du tableau tab

  //INITIALISATION DES VARIABLES
	indice = 0;
  trouve = 0;

  while(!trouve && indice < 256){
    if(tabCode[indice].tailleCode == taille){
      trouve = 1;
      for (i = 0; i < taille ; i++) {
        if(tabCode[indice].code[i] != tabBinaire[i]){
            trouve = 0;
        }
      }
    }
    indice++;
  }

	return(!trouve ? 256 : indice-1);
}
