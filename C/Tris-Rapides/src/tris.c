/*!
 * \file tris.c
 *
 * \autor Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 17 mars 2020
 *
 * \brief fonctions et procéedures relatives aux tris
 *
 *
 */

//Inclusion des entêtes de librairies
#include "tris.h"

// Code des fonctions et procédures

void  echanger(int* tab, int indice1, int indice2){
  int tmp; //variablepour effectuer un échange
  tmp=tab[indice1];
  tab[indice1]=tab[indice2];
  tab[indice2]=tmp;
}


/*Question 5*/

void triSelection(int* tab, int n, FILE* fichier){
  int* tab2; //une copie du tableau
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int min; //indice de la case minimum
  clock_t t1; //temps début d'execution
  clock_t t2; //temps fin d'execution
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  t1=clock();
  for(i=0; i<n-1; i++){
    min=i;
    for(j=i+1; j<n; j++){
      if(tab2[j]<tab2[min]){
        min=j;
      }
    }
    if(min!=j){
      echanger(tab2, min, i);
    }
  }
  t2=clock();
  printf("\n\nTri par sélection :\n");
  afficherTab(tab2, n);
  printf("temps d'execution : %f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  fprintf(fichier, "Tri par sélection;%f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  free(tab2);
}

void triBulle(int* tab, int n, FILE* fichier){
  int* tab2; //une copie du tableau
  int i; //iterrateur de boucle
  int estTrie; //variable booléeene qui indique si un tableau est trié ou non
  clock_t t1; //temps début d'execution
  clock_t t2; //temps fin d'execution
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  estTrie=0;
  t1=clock();
  while(!estTrie){
    estTrie=1;
    for(i=0; i<n-1; i++){
      if(tab2[i]>tab2[i+1]){
        estTrie=0;
        echanger(tab2, i, i+1);
      }
    }
  }
  t2=clock();
  printf("\n\nTri à bulle :\n");
  afficherTab(tab2, n);
  printf("temps d'execution : %f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
fprintf(fichier, "Tri par sélection;%f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  free(tab2);
}

void triInsertion(int* tab, int n, FILE* fichier){
  int* tab2; //une copie du tableau
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int tmp; //variable pour effectuer un échange
  clock_t t1; //temps début d'execution
  clock_t t2; //temps fin d'execution
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  t1=clock();
  for(i=0; i<n; i++){
    tmp=tab2[i];
    j=i;
    while(j>0 && tab2[j-1]>tmp){
      tab2[j]=tab2[j-1];
      j--;
    }
    tab2[j]=tmp;
  }
  t2=clock();
  printf("\n\nTri par insertion :\n");
  afficherTab(tab2, n);
  printf("temps d'execution : %f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
fprintf(fichier, "Tri par sélection;%f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  free(tab2);
}

void triRapide(int* tab, int n, FILE* fichier){
  int* tab2; //une copie du tableau
  clock_t t1; //temps début d'execution
  clock_t t2; //temps fin d'execution
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  t1=clock();
  quickSort(tab2, 0, n-1);
  t2=clock();
  printf("\n\nTri rapide :\n");
  afficherTab(tab2, n);
  printf("temps d'execution : %f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
fprintf(fichier, "Tri par sélection;%f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  free(tab2);
}

void quickSort(int* tab, int debut, int fin){
  int indice_pivot; //indice du pivot
  if(debut<fin){
    indice_pivot=partitionner(tab, debut, fin);
    quickSort(tab, debut, indice_pivot-1);
    quickSort(tab, indice_pivot+1, fin);
  }
}

int partitionner(int* tab, int debut, int fin){
  int pivot; //le pivot autour du quel on déplace les cases du tableau
  int cpt; //compteur pour savoir l'indice du pivot à la fin
  int i; //iterrateur de boucle
  pivot=tab[debut];
  cpt=debut;
  for(i=debut; i<=fin; i++){
    if(tab[i]<pivot){
      cpt++;
      echanger(tab, cpt, i);
    }
  }
  echanger(tab, cpt, debut);
  return(cpt);
}

void triFusion(int* tab, int n, FILE* fichier){
  int* tab2; //une copie du tableau
  clock_t t1; //temps début d'execution
  clock_t t2; //temps fin d'execution
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  t1=clock();
  mergeSort(tab2, n);
  t2=clock();
  printf("\n\nTri fusion :\n");
  afficherTab(tab2, n);
  printf("temps d'execution : %f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
fprintf(fichier, "Tri par sélection;%f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  free(tab2);
}

void mergeSort(int* tab, int n){
  if(n>1){
    int *tab1; //le tableau de gauche
    int *tab2; //le tableau de droite
    int m; //la case du milieu (debut du tab2)

    m = n/2;
    tab1 = copierSousTableau(tab, 0, m-1);
    tab2 = copierSousTableau(tab, m, n-1);

    mergeSort(tab1, m);
    mergeSort(tab2, n-m);

    fusionner(tab, tab1, m, tab2, n-m);

    free(tab1);
    free(tab2);
  }
}

void fusionner(int* tab, int* tab1, int n1, int* tab2, int n2){
  int i; //parcours les indices du premier tableau
  int j; //parcours les indices du deuxieme tableau
  int k; //parcours les indices du tableau final7

  i = 0;
  j = 0;
  k = 0;

  while(i<n1 && j<n2){
    if(tab1[i] < tab2[j]){
      tab[k] = tab1[i];
      i++;
    }
    else{
      tab[k] = tab2[j];
      j++;
    }
    k++;
  }

  while(i<n1){
    tab[k] = tab1[i];
    i++;
    k++;
  }
  while(j<n2){
    tab[k] = tab2[j];
    j++;
    k++;
  }
}

void trisShell(int* tab, int n, FILE* fichier){
  int intervalle;
  int i; //parcours le tab2leau
  int j;
  int valeur; //la valeur à inserer
  int* tab2; //une copie du tableau
  clock_t t1; //temps début d'execution
  clock_t t2; //temps fin d'execution
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  t1=clock();

  intervalle = 1;
  while(intervalle < n/3){
    intervalle = intervalle * 3 + 1;
  }
  while(intervalle > 0){
    for(i = intervalle; i < n; i ++){
      valeur = tab2[i];
      j = i;
      while(j>intervalle -1 && tab2[j-intervalle]>=valeur){
        tab2[j] = tab2[j-intervalle];
        j = j - intervalle;
      }
      tab2[j] = valeur;
    }
    intervalle = (intervalle-1) / 3;
  }

  t2=clock();
  printf("\n\nTri shell :\n");
  afficherTab(tab2, n);
  printf("temps d'execution : %f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
fprintf(fichier, "Tri par sélection;%f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  free(tab2);
}
