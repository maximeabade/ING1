/*!
\file racine.c
\brief le code des fonctions permettant de calculer la valeur de la racine carrée de 2
\author Justine Ribas <ribasjusti@cy-tech.fr>
\version 0.1
\date 22 novembre 2021
*/

/*inclusion des entêtes de librairie*/
#include "racine.h"

/*code des fontions de calcul de racine(2)*/

// fonction qui calcule la racine carrée de 2 avec la methode de Newton
float methodeNewton(int int_n)
{
    //Déclaration des variables
    float flt_un; //la valeur de un
    
    //Initialisation des variables
    flt_un = 1;

    //Calcul du int_n ième terme de la suite 
    for (int int_i = 1; int_i <= int_n; int_i++){
        flt_un = (flt_un / 2) + (1 / flt_un);
    }

    //Retour de la valeur de la racine(2)
    return(flt_un);
}

// fonction qui calcule la racine carrée de 2 avec la methode d'Edmund Halley
float methodeHalley(int int_n)
{
    //Déclaration des variables
    float flt_un; //la valeur de un
    
    //Initialisation des variables
    flt_un = 1;

    //Calcul du int_n ième terme de la suite 
    for (int int_i = 1; int_i <= int_n; int_i++){
        flt_un = flt_un * ((pow(flt_un, 2) + 6) / (3 * pow(flt_un, 2) + 2));
    }

    //Retour de la valeur de la racine(2)
    return(flt_un);
}

// fonction qui calcule la racine carrée de 2 avec la methode de Théon de Smyrne
float methodeSmyrne(int int_n)
{
    //Déclaration des variables
    int int_pn; //la valeur de pn
    int int_qn; //la valeur de qn 
    int int_tmp; //la valeur temporaire pour stoquer pn
    
    //Initialisation des variables
    int_pn = 1;
    int_qn = 1;

    // comme la machine ne peut pas stocker des entiers trop grands, on se limite à int_n <= 15
    if(int_n >15){
        int_n = 15;
    }

    //Calcul du int_n ième terme des deux suites 
    for (int int_i = 1; int_i <= int_n; int_i++){   
        int_tmp = int_pn;
        int_pn = int_tmp + 2 * int_qn;
        int_qn = int_tmp + int_qn;
    }

    //Retour de la valeur de la racine(2)
    return((float) int_pn / int_qn);
}

// fonction qui affiche les différentes méthodes de calcul de la racine carrée de 2
void menuRacine(void)
{
    //Déclaration des variables
    int int_choix; //le choix de l'utilisateur dans le menu
    int int_n; //la précision de l'approximation, plus n est grand, plus l'approximation est précise
    float flt_racine; //la valeur de racine(2)

    // Saisie de int_n
    do {
        printf("Entrez la précision de l'approximation de pi. On a besoin d'un entier positif.(plus ce nombre sera grand, plus l'aproximation sera précise)\n");
        int_n = saisirEntier();
    } while(int_n < 0);
    

    // Affichage du menu
    printf("\nQuelle méthode voulez-vous utiliser pour calculer une approximation de pi ?\n\t1- la méthode d'Isaac Newton\n\t2- la méthode d'Edmund Halley\n\t3- la méthode de Théon de Smyrne\n");

    // Saisie du choix
    int_choix = saisirEntier();

    // On effectue l'interraction correspondant au choix
    switch (int_choix) {
        case 1:
            flt_racine = methodeNewton(int_n);
            break;
        case 2:
            flt_racine = methodeHalley(int_n);
            break;
        case 3:
            flt_racine = methodeSmyrne(int_n);
            break;
        default :
            printf("Choix invalide\n");
            break;
    }

    printf("Racine(2) vaudrait : %f\n", flt_racine);
}