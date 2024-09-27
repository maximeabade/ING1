/*!
\file tableau.c
\brief fonctions pour créer des tableau
\author Justine Ribas <ribasjusti@eisti.eu>
\version 0.1
\date 13 décembre 2019
*/

#include"tableau.h"

/*Question 1*/
int* creerTabEntier1D(int n)
{
  int* tab; //tableau d'entiers
  tab = malloc(n*sizeof(int));
  if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
  }
  return(tab);
}

/*Question 2*/
void InitTab(int* tab, int n){
  int i; //iterrateur de boucle
  srand(time(NULL));
  for(i=0; i<n; i++){
    tab[i]= rand()%100;
  }
}

/*Question 3*/
void afficherTab(int* tab, int n){
  int i; //iterrateur de boucle
  for(i=0; i<n; i++){
    printf("%d ", tab[i]);
  }
  printf("\n");
}

/*Question 4*/
void CopierTab(int* tab1, int* tab2, int n){
  int i; //iterrateur de boucle
  for(i=0; i<n; i++){
    tab2[i]=tab1[i];
  }
}

int* copierSousTableau(int* tab, int debut, int fin){
  int *tabCopie; //tableau qui contiendra la copie
  int i; //parcours de l'indice debut à l'indice fin

  tabCopie = creerTabEntier1D(fin-debut+1);

  for(i = debut ; i <= fin ; i++){
    tabCopie[i-debut] = tab[i];
  }

  return(tabCopie);
}
